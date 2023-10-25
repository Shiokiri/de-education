#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <memory>

#include "lexer.h"
#include "parser.h"

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

    std::unique_ptr<Parser> parser = std::make_unique<Parser>();
    parser->syntaxAnalysis(std::move(tokens));

    return 0;
}
