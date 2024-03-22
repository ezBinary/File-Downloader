#include "console.h"
#include <string>
#include <regex>
// Check the validate URL format
bool isValidURL(const std::string& url)
{
    // Regular expression to validate URL format
    std::regex urlRegex("(https?|ftp)://[^\\s/$.?#].[^\\s]*");
    return std::regex_match(url, urlRegex);
}

// Get a valid URL from the user
std::string console::getValidURL() {
    std::string url;

    while (true) 
    {
        std::cout << "Enter the URL or 'q' to quit: ";
        std::getline(std::cin, url);

        if (url == "q" || url == "Q") {
            std::cout << "Input cancelled." << std::endl;
            exit(0);
        }

        if (isValidURL(url)) {
            return url;
        }

        std::cout << "Invalid URL format. Please enter a valid URL or 'q' to cancel." << std::endl;
    }
}

// Print Stylish Progress Bar
void console::drawStylishProgressBar(double progress, int width) {
        int completedBlocks = static_cast<int>(progress * width);
        int remainingBlocks = width - completedBlocks;
        int i;
        // Clear previous output
        std::cout << "\r" << std::flush;

        // Print new progress bar
        std::cout << "[";

        for (i = 0; i < completedBlocks; ++i) {
            std::cout << "\u2588"; // Full block Unicode character
        }

        for (i = 0; i < remainingBlocks; ++i) {
            std::cout << "\u2591"; // Light shade Unicode character
        }

        std::cout << "] " << std::fixed << std::setprecision(0) << (progress * 100) << "%" << std::flush;
    }
