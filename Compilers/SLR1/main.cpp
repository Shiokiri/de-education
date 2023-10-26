#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <memory>

#include "lexer.h"
#include "parser.h"
#include "constants.h"
#include "utils.h"

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

    const auto tokens = lexicalAnalysis(contents);
    // print tokens
    std::cout << "Tokens:" << std::endl;
    for(const auto& token : tokens) {
        std::cout << "[" + token.first + " " + token.second + "] ";
    }
    std::cout << std::endl;

    std::unique_ptr<Parser> parser = std::make_unique<Parser>(std::move(tokens));
    parser->syntaxAnalysis();

    return 0;
}
