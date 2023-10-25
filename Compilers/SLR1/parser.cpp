//
// Created by shiokiri on 23-10-25.
//

#include "parser.h"

void Parser::syntaxAnalysis(const std::vector<std::pair<std::string, std::string>>&& tokens) {
    for(const auto& token : tokens) {
        std::cout << token.first << " " << token.second << std::endl;
    }
}