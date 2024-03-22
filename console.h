#pragma once
#include "common.h"

bool isValidURL(const std::string& url) ;

namespace console
{
    std::string getValidURL();
    void drawStylishProgressBar(double progress, int width);
}