//
// Created by shiokiri on 23-10-25.
//

#ifndef SLR1_PARSER_H
#define SLR1_PARSER_H

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

struct Product {
    std::string L;
    // TODO: vector -> set
    std::vector<std::string> R;

    Product(const std::string& L, const std::vector<std::string>& R) : L(L), R(R) {}

    void printProduct() const {
        std::cout << L << " -> ";
        for(const auto& r: R) {
            std::cout << r << " ";
        }
        std::cout << std::endl;
    }
};

struct Grammar {
    // TODO: vector -> set
    std::string S;
    std::vector<std::string> V;
    std::vector<std::string> T;
    std::vector<Product> P;

    void printGrammar() const {
        std::cout << "G: " << std::endl;
        std::cout << "S: " << std::endl << S << std::endl;
        std::cout << "V: " << std::endl;
        for(const auto& v: V) {
            std::cout << v + " ";
        }
        std::cout << std::endl << "T: " << std::endl;
        for(const auto& t: T) {
            std::cout << t + " ";
        }
        std::cout << std::endl << "P: " << std::endl;
        for(const auto& p: P) {
            p.printProduct();
        }
    }
};

class Parser {
private:
    Grammar G;
    const std::string EPSILON = "ε";
    // TODO: vector -> set
    const std::vector<std::pair<std::string, std::string>>&& tokens;
    std::unordered_map<std::string, std::set<std::string>> first;

public:
    Parser(const std::vector<std::pair<std::string, std::string>>&& tokens)
    : tokens(std::move(tokens))
    {
        G.S = "Program";
        G.V = {"Program", "FunctionDeclaration", "ArgumentList", "BlockStatement",
               "Type", "ArithmeticExpression", "BoolExpression",
               "ArithmeticOperator", "ComparisonOperator"};
        G.T = {"identifier", "literal", "(", ")", "{", "}", ",", ";", "=",
               "while", "if", "else", "return", "int", "string","==", "-", "+", "*", "/"};
        G.P = { {"BlockStatement", {"BlockStatement", "BlockStatement"}},
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

        // print G
        G.printGrammar();

    };

    void syntaxAnalysis();
    void getFirst();
    void getFollow();
    void getSLR1Table();
};


#endif //SLR1_PARSER_H
