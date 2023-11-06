//
// Created by shiokiri on 23-10-25.
//

#ifndef SLR1_PARSER_H
#define SLR1_PARSER_H

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ranges>
#include <vector>
#include <stack>
#include <set>
#include <map>

#include "constants.h"
#include "utils.h"

struct Product {
    std::string L;
    std::vector<std::string> R;
    bool operator < (Product const &other) const {
        if (L != other.L) {
            return L < other.L;
        }
        return R < other.R;
    }
    void printProduct(int const dot = -1) const {
        std::cout << L << " -> ";
        for(int i = 0; i < R.size(); i++) {
            if(i == dot) {
                std::cout << "· ";
            }
            std::cout << R[i] << " ";
        }
        if(dot == R.size()) {
            std::cout << "·";
        }
        std::cout << std::endl;
    }
};
struct Grammar {
    std::string S;
    std::vector<std::string> V;
    std::vector<std::string> T;
    std::vector<Product> P;
    void printGrammar() const {
        utils::print("Grammar: ", constants::color::RED_TEXT) << std::endl;
        utils::print("S: ", constants::color::GREEN_TEXT) << S << std::endl;
        utils::print("V: ", constants::color::GREEN_TEXT);
        for(auto const& v: V) {
            std::cout << v + " ";
        }
        std::cout << std::endl;
        utils::print("T: ", constants::color::GREEN_TEXT);
        for(auto const& t: T) {
            std::cout << t + " ";
        }
        std::cout << std::endl;
        utils::print("P: ", constants::color::GREEN_TEXT) << std::endl;
        int index = 0;
        for(auto const& p: P) {
            std::cout << index++ << " ";
            p.printProduct();
        }
    }
};
struct Item {
    int pIndex, dotIndex;
    bool operator < (Item const& other) const {
        return pIndex == other.pIndex ? dotIndex < other.dotIndex : pIndex < other.pIndex;
    }
};
struct TypeI {
    std::set<Item> items;
    bool operator < (TypeI const& other) const {
        return items < other.items;
    }
    [[nodiscard]] TypeI closure(Grammar const &G) const {
        TypeI J = {items};
        bool changed = true;
        while(changed) {
            changed = false;
            auto const size = J.items.size();
            for(auto const [pIndex, dotIndex] : J.items) {
                if(dotIndex == G.P[pIndex].R.size()) continue;
                auto const B = G.P[pIndex].R[dotIndex];
                if(std::find(G.V.begin(), G.V.end(), B) != G.V.end()) {
                    for(int i = 0; i < G.P.size(); i++) {
                        if(B == G.P[i].L) {
                            if(J.items.find(Item(i, 0)) == J.items.end()) {
                                J.items.insert(Item(i, 0));
                            }
                        }
                    }
                }
            }
            changed = J.items.size() != size || changed;
        }
        return J;
    }
    [[nodiscard]] TypeI go(Grammar const &G, std::string const& X) const {
        TypeI go = {};
        for(auto const& [pIndex, dotIndex] : items) {
            // A -> α·Bβ
            if(dotIndex == G.P[pIndex].R.size()) continue;
            auto const B = G.P[pIndex].R[dotIndex];
            if(B == X) {
                // A -> αB·β
                go.items.insert(Item(pIndex, dotIndex+1));
            }
        }
        return go.closure(G);
    }
    void print(int const index = -1) const {
        // TODO: need gcc v13 to support std::format in C++20
        utils::print("I" + std::to_string(index) + ": ", constants::color::GREEN_TEXT);
        std::cout << "| ";
        for(auto const& item: items) {
            auto const& [p, d] = item;
            std::cout << p << " " << d << " | ";
        }
        std::cout << std::endl;
    }
};
struct TypeC {
    std::set<TypeI> I;
    bool operator < (TypeC const& other) const {
        return I < other.I;
    }
};
class Parser {
private:
    Grammar G;
    std::vector<std::pair<std::string, std::string>> tokens;
    using string_umap_set = std::unordered_map<std::string, std::set<std::string>>;
    string_umap_set first, follow;
    using pair_umap_string = std::unordered_map<std::pair<std::string, std::string>, std::string,
        decltype([](const std::pair<std::string, std::string> &p) {
        return std::hash<std::string>{}(p.first) ^ std::hash<std::string>{}(p.second);
    })>;
    pair_umap_string actionTable, gotoTable;
    TypeC C;
public:
    Parser() = delete;
    template <typename T>
    explicit Parser(T&& tokens) : tokens(std::forward<T>(tokens)) {
        G.S = "Program";
        G.V = {"Program", "FunctionDeclaration", "ArgumentList", "BlockStatement",
               "Type", "ArithmeticExpression", "BoolExpression",
               "ArithmeticOperator", "ComparisonOperator", "FunctionId", "ActualArgumentList"};
        G.T = {"identifier", "literal",
               "(", ")", "{", "}", ",", ";", "=",
               "while", "if", "else", "return",
               "int", "string",
               "==", "!=", "-", "+", "*", "/"};
        G.P = { {"Program", {"FunctionDeclaration"}},

                {"FunctionDeclaration", {"FunctionDeclaration", "FunctionDeclaration"}},
                {"FunctionDeclaration", {"Type", "identifier", "(", ")", "{", "BlockStatement", "}"}},
                {"FunctionDeclaration", {"Type", "identifier", "(", "ArgumentList", ")", "{", "BlockStatement", "}"}},

                {"ArgumentList", {"Type", "identifier"}},
                {"ArgumentList", {"Type", "identifier", ",", "ArgumentList"}},

                {"FunctionId", {"identifier", "(", ")"}},
                {"FunctionId", {"identifier", "(", "ActualArgumentList", ")"}},

                {"ActualArgumentList", {"ArithmeticExpression"}},
                {"ActualArgumentList", {"ArithmeticExpression", ",", "ActualArgumentList"}},

                {"BlockStatement", {"BlockStatement", "BlockStatement"}},

                {"BlockStatement", {"Type", "identifier", ";"}},
                {"BlockStatement", {"Type", "identifier", "=", "ArithmeticExpression", ";"}},
                {"BlockStatement", {"identifier", "=", "ArithmeticExpression", ";"}},

                {"BlockStatement", {"Type", "identifier", "=", "FunctionId", ";"}},
                {"BlockStatement", {"identifier", "=", "FunctionId", ";"}},

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
                {"ComparisonOperator", {"!="}},

                {"ArithmeticOperator", {"+"}},
                {"ArithmeticOperator", {"-"}},
                {"ArithmeticOperator", {"*"}},
                {"ArithmeticOperator", {"/"}} };
        // print G
        G.printGrammar();
        // initialization
        getFirst();
        getFollow();
        getSLR1Table();
    };
    ~Parser() = default;
    Parser(const Parser& other) = default;
    Parser& operator = (const Parser& other) = default;
    Parser(Parser&& other) noexcept = default;
    Parser& operator = (Parser&& other) noexcept = default;
    
    void syntaxAnalysis();
    void getFirst();
    void getFollow();
    void getSLR1Table();
};

#endif //SLR1_PARSER_H
