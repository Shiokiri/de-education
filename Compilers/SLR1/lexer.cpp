//
// Created by shiokiri on 23-10-18.
//

#include "lexer.h"

auto lexicalAnalysis(std::string code) -> std::vector<std::pair<std::string, std::string>>  {
    std::vector<std::string> keywords = {"int", "string", "return", "if", "while"};
    std::vector<std::string> operators = {"+", "-", "*", "/", "=", "==", "!="};
    std::vector<std::string> delimiters = {"{", "}", "(", ")", ",", ";"};
    // first: token
    // second: type { keywords, operators, delimiters, literal, identifier }
    std::vector<std::pair<std::string, std::string>> tokens = {};
    auto checkStringInStringVector =
        [](std::string searchString,const std::vector<std::string> &stringVector) -> bool {
        auto it = std::find(stringVector.begin(), stringVector.end(), searchString);
        return it != stringVector.end();
    };
    int index = 0;
    while(index < code.length()) {
        std::string codeIndex(1, code[index]);
        // space
        if(code[index] == ' ') {
            index++;
            continue;
        }
        // delimiters length = 2
        else if(index+1 < code.length() && checkStringInStringVector(codeIndex + code[index+1], operators)) {
            tokens.push_back(std::make_pair(codeIndex + code[index+1], "operators"));
            index += 2;
        }
        // delimiters length = 1
        else if(checkStringInStringVector(codeIndex, operators)) {
            tokens.push_back(std::make_pair(std::string(1, code[index]), "operators"));
            index++;
        }
        // operators length = 1
        else if(checkStringInStringVector(codeIndex, delimiters)) {
            tokens.push_back(std::make_pair(std::string(1, code[index]), "delimiters"));
            index++;
        }
        // literal - string
        else if(code[index] == ' " ') {
            index++;
            std::string str;
            while(code[index] != ' " ') {
                str += code[index];
                index++;
            }
            tokens.push_back(std::make_pair(str, "literal"));
        }
        // literal - int
        else if(isdigit(code[index])) {
            std::string str;
            while(isdigit(code[index])) {
                str += code[index];
                index++;
            }
            tokens.push_back(std::make_pair(str, "literal"));
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
        else {
            index++;
        }
    }
    return tokens;
}
