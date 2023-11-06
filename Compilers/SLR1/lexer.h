//
// Created by shiokiri on 23-10-18.
//

#ifndef SLR1_LEXER_H
#define SLR1_LEXER_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <cctype>

#include "constants.h"
#include "utils.h"

auto lexicalAnalysis(std::string const&) -> std::vector<std::pair<std::string, std::string>>;

#endif //SLR1_LEXER_H
