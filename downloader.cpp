#include "downloader.h"

// Convert bytes to human readable format
std::string formatBytes(curl_off_t bytes) 
{

    static const char *suffixes[] = {"B", "KB", "MB", "GB", "TB"};
    int suffixIndex = 0;
    double adjustedBytes = static_cast<double>(bytes);
    
    while (adjustedBytes >= 1024 && suffixIndex < sizeof(suffixes) / sizeof(suffixes[0]) ) {
        adjustedBytes /= 1024.0;
        suffixIndex++;
    }
    
    return std::to_string(adjustedBytes) + " " + suffixes[suffixIndex];
}

// Progress callback function
int FileDownloader::progressCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow)
{
    std::string SpeedStr;
    DownloadProgress *progress = static_cast<DownloadProgress*>(clientp);
    double percent;
    double speed;

    // Update progress data
    progress->bytesDownloaded = dlnow;
    progress->totalSize = dltotal;

    // Calculate download completion percentage
    percent = (dltotal > 0) ? (dlnow * 100.0 / dltotal) : 0.0;

    // Calculate download speed
    auto elapsedTime = std::chrono::steady_clock::now() - progress->startTime;
    speed = progress->bytesDownloaded / (std::chrono::duration_cast<std::chrono::milliseconds>(elapsedTime).count() / 1000.0); // bytes per second

    // Clear previous progress bar
    std::cout << "\r";

    // Display progress bar
    console::drawStylishProgressBar(percent / 100.0,50);

    // Display download size information
    std::cout << " (" << formatBytes(progress->bytesDownloaded) << " of " << formatBytes(progress->totalSize) << ")";

    // Display download speed
    SpeedStr =  " | Speed: " + formatBytes(speed) + "/s ";
    std::cout << SpeedStr.c_str();

    std::cout.flush(); // Ensure immediate output

    return 0;
}

bool FileDownloader::Downloader() 
{
    CURL *curl = curl_easy_init();
    DownloadProgress progress;
    CURLcode res;
    FILE *file;

    if (!curl) {
        std::cerr << "Error initializing curl." << std::endl;
        return false;
    }
    // Set the URL
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    // Set progress callback function
    curl_easy_setopt(curl, CURLOPT_XFERINFODATA, &progress);
    curl_easy_setopt(curl, CURLOPT_XFERINFOFUNCTION, progressCallback);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L); // Enable progress data

    // Open file hanndle for writing
    file = fopen(filename.c_str(), "wb");
    if (!file) {
        std::cerr << "Error opening file for writing" << std::endl;
        curl_easy_cleanup(curl);
        return false;
    }

    // Set file as the target for the download
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    // Record start time
    progress.startTime = std::chrono::steady_clock::now();

    // Perform the request
    res = curl_easy_perform(curl);

    // Check for errors
    if (res != CURLE_OK) 
    {
        std::cerr << "\ncurl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        return false;
    } else 
    {
        std::cout << "\nDownload completed successfully!" << std::endl;
    }

    
    return true;
}

FileDownloader::FileDownloader(const std::string& i_url) : url(i_url), curl(nullptr), file(nullptr)
{
    // Initialize libcurl
    if (curl_global_init(CURL_GLOBAL_ALL) != CURLE_OK) 
    {
        std::cerr << "Error initializing libcurl." << std::endl;
    }
     
    std::size_t found = url.find_last_of("/");
    if (found != std::string::npos) 
    {
        filename = url.substr(found + 1);
    } 
    else 
    {
        // invalid URL without filename
        std::cerr << "Error: Invalid URL format." << std::endl;
    }

}

FileDownloader::~FileDownloader()
{
    // close curl handle
    curl_easy_cleanup(curl);

    // close file handle
        
    fclose(file);

    // If the download process was unsuccessful, simply delete the corrupted downloaded file.
    if(!check) 
    {
        std::remove(filename.c_str());
    }

    // close global init
    curl_global_cleanup();
}

void FileDownloader::download()
{
    check = FileDownloader::Downloader();
}
