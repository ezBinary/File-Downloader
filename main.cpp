#include "downloader.h"

int main()
{
    // Get a valid URL from the user
    std::string i_url = console::getValidURL();

    // Download
    FileDownloader fdl(i_url.c_str());
    fdl.download();

    return 0;
}
