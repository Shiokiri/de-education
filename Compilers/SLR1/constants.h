//
// Created by shiokiri on 23-10-26.
//

#ifndef SLR1_CONSTANTS_H
#define SLR1_CONSTANTS_H

#include <string>

namespace constants {
    const std::string EPSILON = "ε";
    namespace color {
        const std::string DEFAULT_TEXT = "\033[0m";
        const std::string RED_TEXT = "\033[1;31m";
        const std::string GREEN_TEXT = "\033[0;32m";
        const std::string YELLOW_TEXT = "\033[0;33m";
        const std::string BLUE_TEXT = "\033[0;34m";
        const std::string CARMINE_TEXT = "\033[0;35m";
        const std::string CYAN_TEXT = "\033[0;36m";
    }
}

#endif //SLR1_CONSTANTS_H
