//
// Created by shiokiri on 23-10-18.
//

#include "lexer.h"

auto lexicalAnalysis(std::string const& code) -> std::vector<std::pair<std::string, std::string>>  {
    std::vector<std::string> keywords = {"int", "string", "return", "if", "else", "while"};
    std::vector<std::string> operators = {"+", "-", "*", "/", "=", "==", "!="};
    std::vector<std::string> delimiters = {"{", "}", "(", ")", ",", ";"};
    // first: token
    // second: type { keywords, operators, delimiters, literal, identifier }
    std::vector<std::pair<std::string, std::string>> tokens = {};
    int index = 0;
    while(index < code.length()) {
        std::string codeIndex(1, code[index]);
        // space
        if(code[index] == ' ') {
            index++;
            continue;
        }
        // operators length = 2
        else if(index+1 < code.length() && std::find(operators.begin(), operators.end(), codeIndex + code[index+1]) != operators.end()) {
            tokens.push_back({codeIndex + code[index+1], "operators"});
            index += 2;
        }
        // operators length = 1
        else if(std::find(operators.begin(), operators.end(), codeIndex) != operators.end()) {
            tokens.push_back({codeIndex, "operators"});
            index++;
        }
        // delimiters length = 1
        else if(std::find(delimiters.begin(), delimiters.end(), codeIndex) != delimiters.end()) {
            tokens.push_back({codeIndex, "delimiters"});
            index++;
        }
        // literal - string
        else if(code[index] == '"') {
            index++; // "
            std::string str;
            while(code[index] != '"') {
                str += code[index];
                index++;
            }
            index++; // "
            tokens.push_back({str, "literal"});
        }
        // literal - int
        else if(isdigit(code[index])) {
            std::string str;
            while(isdigit(code[index])) {
                str += code[index];
                index++;
            }
            tokens.push_back({str, "literal"});
        }
        // keywords / identifier
        else if(isalpha(code[index])){
            std::string str;
            while(isalpha(code[index])) {
                str += code[index];
                index++;
            }
            if(std::find(keywords.begin(), keywords.end(), str) != keywords.end()) {
                tokens.push_back({str, "keywords"});
            }
            else {
                tokens.push_back({str, "identifier"});
            }
        }
        else {
            index++;
        }
    }
    return tokens;
}
