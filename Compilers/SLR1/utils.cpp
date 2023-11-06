//
// Created by shiokiri on 23-10-26.
//

#include "utils.h"

std::ostream& utils::print(std::string s, std::string const color) {
    std::ostream& os = std::cout;
    return os << color << s << constants::color::DEFAULT_TEXT;
}
