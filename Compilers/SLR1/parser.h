//
// Created by shiokiri on 23-10-25.
//

#ifndef SLR1_PARSER_H
#define SLR1_PARSER_H

#include <iostream>
#include <vector>

struct Product {
    std::string name;
    std::vector<std::string> components;

    Product(const std::string& n, const std::vector<std::string>& comps) : name(n), components(comps) {}
};

struct Grammar {
    std::string S;
    std::vector<std::string> V;
    std::vector<std::string> T;
    std::vector<Product> P;
};

class Parser {
private:
    Grammar G;
public:
    Parser() {
        G.S = "Program";
        G.V = {"Program", "FunctionDeclaration", "ArgumentList", "BlockStatement",
               "Type", "ArithmeticExpression", "BoolExpression",
               "ArithmeticOperator", "ComparisonOperator"};
        G.T = {"identifier", "literal", "(", ")", "{", "}", ",", ";", "=",
               "while", "if", "else", "return", "int", "string","==", "-", "+", "*", "/"};

        G.P = {
                {"BlockStatement", {"BlockStatement", "BlockStatement"}},
                {"BlockStatement", {"Type", "identifier", ";"}},
                {"BlockStatement", {"Type", "identifier", "=", "ArithmeticExpression", ";"}},
                {"BlockStatement", {"identifier", "=", "ArithmeticExpression", ";"}},
                {"BlockStatement", {"while", "(", "BoolExpression", ")", "{", "BlockStatement", "}"}},
                {"BlockStatement", {"if", "(", "BoolExpression", ")", "{", "BlockStatement", "}"}},
                {"BlockStatement", {"if", "(", "BoolExpression", ")", "{", "BlockStatement", "}", "else", "{", "BlockStatement", "}"}},
                {"BlockStatement", {"return", ";"}},
                {"BlockStatement", {"return", "ArithmeticExpression", ";"}},

                {"Type", {"int"}},
                {"Type", {"string"}},

                {"ArithmeticExpression", {"ArithmeticExpression", "ArithmeticOperator", "ArithmeticExpression"}},
                {"ArithmeticExpression", {"-", "ArithmeticExpression"}},
                {"ArithmeticExpression", {"(", "ArithmeticExpression", ")"}},
                {"ArithmeticExpression", {"identifier"}},
                {"ArithmeticExpression", {"literal"}},

                {"BoolExpression", {"ArithmeticExpression", "ComparisonOperator", "ArithmeticExpression"}},
                {"BoolExpression", {"(", "BoolExpression", ")"}},

                {"ComparisonOperator", {"=="}},

                {"ArithmeticOperator", {"+"}},
                {"ArithmeticOperator", {"-"}},
                {"ArithmeticOperator", {"*"}},
                {"ArithmeticOperator", {"/"}} };
    };

    void syntaxAnalysis(const std::vector<std::pair<std::string, std::string>>&& tokens);
};


#endif //SLR1_PARSER_H
