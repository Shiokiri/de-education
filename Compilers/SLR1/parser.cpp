//
// Created by shiokiri on 23-10-25.
//

#include "parser.h"

void Parser::syntaxAnalysis() {
    getFirst();
    getFollow();
    getSLR1Table();
}

void Parser::getFirst() {
    auto checkStringInStringVector =
        [](std::string searchString,const std::vector<std::string> &stringVector) -> bool {
        auto it = std::find(stringVector.begin(), stringVector.end(), searchString);
        return it != stringVector.end();
    };

    // Initialize
    // V -> (V, [])
    for(const auto& v: G.V) {
        first[v] = { };
    }
    // T -> (T, [T])
    for(const auto& t: G.T) {
        first[t] = { t };
    }
    // 若右边第一个符号是终结符或 ε，则直接将其加入 First
    // P.R[0] in T || P.R[0] == ε -> (P.L, [P.R[0]])
    for(const auto& p: G.P) {
        if(checkStringInStringVector(p.R[0], G.T) || p.R[0] == "ε") {
            first[p.L].insert(p.R[0]);
        }
    }
    bool changed = true;
    while(changed) {
        changed = false;
        // 若右边第一个符号是非终结符，则将其 First 集的的非 ε 元素加入 First
        for(const auto& p: G.P) {
            if(checkStringInStringVector(p.R[0], G.V)) {
                const int size = first[p.L].size();
                for(const auto& s: first[p.R[0]]) {
                    if(s != "ε") {
                        first[p.L].insert(s);
                    }
                }
                if(first[p.L].size() != size) {
                    changed = true;
                }
            }
            // 若右边第一个符号是非终结符而且紧随其后的是很多个非终结符，这个时候就要注意是否有 ε

            // 若第 i 个非终结符的 First 集有 ε  ，则可将第 i+1 个非终结符去除 ε  的 First 集加入 First（X）。
        }
    }

    // print FIRST SET
    std::cout << "FIRST set: " << std::endl;
    for (const auto& pair : first) {
        std::cout << "FIRST[\"" + pair.first + "\"]: { ";
        for(const auto& s: pair.second ) {
            std::cout << "\"" + s + "\" ";
        }
        std::cout << "}"<< std::endl;
    }
}

void Parser::getFollow() {

}

void Parser::getSLR1Table() {

}