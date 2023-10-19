//
// Created by shiokiri on 23-10-18.
//

#include "lexer.h"

auto lexicalAnalysis(std::string code) -> std::vector<std::pair<std::string, std::string>>  {
    std::vector<std::string> keywords = {"fun", "int", "string", "return", "if", "while"};
    std::vector<std::string> operators = {"+", "-", "*", "/", "="};
    std::vector<std::string> delimiters = {"{", "}", "(", ")", ";"};

    // first: token
    // second: type { keywords, operators, delimiters, literal, identifier }
    std::vector<std::pair<std::string, std::string>> tokens = {};

    auto checkCharInStringVector = [](char ch, const std::vector<std::string> &stringVector) {
        for(const auto& str : stringVector) {
            if(str.find(ch) != std::string::npos) {
                return true;
            }
        }
        return false;
    };
    auto checkStringInStringVector = [](std::string s,const std::vector<std::string> &stringVector) {
        for(const auto& str : stringVector) {
            if(s == str) {
                return true;
            }
        }
        return false;
    };

    int index = 0;

    while(index < code.length()) {
        if(code[index] == ' ') {
            index++;
            continue;
        }
        // delimiters
        else if(checkCharInStringVector(code[index], operators)) {
            tokens.push_back(std::make_pair(std::string(1, code[index]), "operators"));
        }
        // operators
        else if(checkCharInStringVector(code[index], delimiters)) {
            tokens.push_back(std::make_pair(std::string(1, code[index]), "delimiters"));
        }
        // literal - string
        else if(code[index] == ' " ') {
            index++;
            std::string str;
            while(code[index] != ' " ') {
                str += code[index];
                index++;
            }
            tokens.push_back(std::make_pair(str, "literal-string"));
        }
        // literal - int
        else if(isdigit(code[index])) {
            std::string str;
            while(isdigit(code[index])) {
                str += code[index];
                index++;
            }
            tokens.push_back(std::make_pair(str, "literal-int"));
        }
        // keywords / identifier
        else if(isalpha(code[index])){
            std::string str;
            while(isalpha(code[index])) {
                str += code[index];
                index++;
            }
            if(checkStringInStringVector(str, keywords)) {
                tokens.push_back(std::make_pair(str, "keywords"));
            }
            else {
                tokens.push_back(std::make_pair(str, "identifier"));
            }
        }
        index++;
    }

    return tokens;
}
