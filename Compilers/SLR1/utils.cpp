//
// Created by shiokiri on 23-10-26.
//

#include "utils.h"

std::ostream& utils::coutWithColor(std::string s, const std::string color) {
    std::cout << color << s << constants::color::DEFAULT_TEXT;
}