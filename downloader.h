#pragma once

#include "console.h"


class FileDownloader {
private:
// Struct to encapsulate download progress data
    struct DownloadProgress {
    curl_off_t bytesDownloaded;
    curl_off_t totalSize;
    std::chrono::steady_clock::time_point startTime;

    DownloadProgress() : bytesDownloaded(0), totalSize(0), startTime(std::chrono::steady_clock::now()) {}
};

    
    std::string url;
    std::string filename;
    CURL* curl;
    FILE* file;
    
    bool check;
    bool Downloader();
    static int progressCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow);

public:

    
    
    FileDownloader(const std::string& xurl);
    ~FileDownloader();
    
    void download();
};
