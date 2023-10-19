#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "lexer.h"

int main() {
    std::string contents;

    std::ifstream file("source.txt");
    if(file.is_open()) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        contents = buffer.str();
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
        return 0;
    }

    auto tokens = lexicalAnalysis(contents);

    for(const auto& token : tokens) {
        std::cout << token.first << " " << token.second << std::endl;
    }

    return 0;
}
