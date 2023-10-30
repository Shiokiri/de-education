//
// Created by shiokiri on 23-10-25.
//

#include "parser.h"

void Parser::syntaxAnalysis() {
    getFirst();
    getFollow();
    getSLR1Table();
    // initialization
    tokens.push_back({"$", "$"});
    std::stack<std::string> stack;
    stack.push("0");
    int tokenIndex = 0;
    int step = 1;
    // begin analysis
    auto getNextTokenType = [&]() -> std::string {
        if(tokenIndex == tokens.size()) return tokens[tokens.size()-1].first;
        std::pair pair = tokens[tokenIndex++];
        if(pair.second == "identifier" || pair.second == "literal") {
            return pair.second;
        } else {
            return pair.first;
        }
    };
    std::string a = getNextTokenType();
    while(true) {
        std::string s = stack.top();
        utils::coutWithColor("Step: "+std::to_string(step++), constants::color::CARMINE_TEXT) << std::endl;
        utils::coutWithColor("Status: ", constants::color::BLUE_TEXT);
        std::stack<std::string> tempStack;
        while(!stack.empty()) {
            tempStack.push(stack.top());
            stack.pop();
        }
        while(!tempStack.empty()) {
            std::cout << tempStack.top() << " ";
            stack.push(tempStack.top());
            tempStack.pop();
        }
        std::cout << std::endl;
        std::cout << actionTable[{s, a}] << std::endl;
        if(auto act = actionTable[{s, a}]; act[0] == 's') {
            // shift
            stack.push(act.erase(0, 1));
            a = getNextTokenType();
        } else if(act[0] == 'r') {
            // reduce
            Product p = G.P[std::stoi(act.erase(0, 1))]; // shift A -> β => pop|β|
            for(int i = 0; i < p.R.size(); i++) {
                if(!stack.empty()) {
                    stack.pop();
                } else {
                    // error
                    goto GRAMMAR_ERROR;
                }
            }
            std::string t = stack.top();
            stack.push(gotoTable[{t, p.L}]); // GOTO[t, A]
            p.printProduct();
        } else if(act == "acc") {
            // accept
            utils::coutWithColor("complete syntax analysis", constants::color::CYAN_TEXT) << std::endl;
            break;
        } else {
            GRAMMAR_ERROR:
            // error
            utils::coutWithColor("------------------", constants::color::YELLOW_TEXT) << std::endl;
            utils::coutWithColor("--grammar error!--", constants::color::YELLOW_TEXT) << std::endl;
            utils::coutWithColor("------------------", constants::color::YELLOW_TEXT) << std::endl;
            break;
        }
    }
}

void Parser::getFirst() {
    // initialization
    // V => (V, [])
    for (const auto& v: G.V) {
        first[v] = {};
    }
    // 1 X in T => FIRST[X] = {X}
    // T => (T, [T])
    for (const auto& t: G.T) {
        first[t] = { t };
    }
    // 3 (X -> ε) => ε in FIRST[X]
    // ε in P.R => (P.L, ε)
    for(const auto& p: G.P) {
        if(std::find(p.R.begin(), p.R.end(),constants::EPSILON) != p.R.end()) {
            first[p.L].insert(constants::EPSILON);
        }
    }
    bool changed = true;
    while (changed) {
        changed = false;
        // 2 X -> Y(1-k), X in V
        // ε in FIRST[Y(1-i-1)] => a != ε in FIRST[Y(i)], a in FIRST(X)
        // ε in FIRST[Y(1-k)] => ε in FIRST[X]
        for (const auto& p: G.P) {
            auto findEpsilonIndex = [&]() {
                for (int i = 0; i <= p.R.size() - 1; i++) {
                    auto first_Yi = first[p.R[i]];
                    // ε not in FIRST[Y(1-i-1)]
                    if(first_Yi.find(constants::EPSILON) == first_Yi.end()) {
                        return i;
                    }
                }
                // ε in FIRST[Y(1-k)]
                return -1;
            };
            if(const int index = findEpsilonIndex(); index == -1) {
                first[p.L].insert(constants::EPSILON);
                changed = true;
            }
            else {
                const int size = first[p.L].size();
                for(const auto& s: first[p.R[index]]) {
                    if(s != constants::EPSILON) {
                        first[p.L].insert(s);
                    }
                }
                changed = first[p.L].size() != size || changed;
            }
        }
    }
    // print FIRST set
    utils::coutWithColor("FIRST set: ", constants::color::RED_TEXT) << std::endl;
    for (const auto& pair : first) {
        std::cout << "FIRST[" << std::quoted(pair.first) << "]: { ";
        for(const auto& s: pair.second ) {
            std::cout << std::quoted(s) << " ";
        }
        std::cout << "}"<< std::endl;
    }
}

void Parser::getFollow() {
    // initialization
    // V => (V, [])
    for (const auto& v: G.V) {
        follow[v] = {};
    }
    // 1 S => (S, [$])
    follow[G.S].insert("$");
    bool changed = true;
    while (changed) {
        changed = false;
        for (const auto &p : G.P) {
            for(int i = 0; i <= p.R.size()-1; i++) {
                if(std::find(G.V.begin(), G.V.end(), p.R[i]) != G.V.end()) {
                    const int size = first[p.R[i]].size();
                    if(i < p.R.size()-1) {
                        [&]() {
                            for(int j = i+1; j <= p.R.size()-1; j++) {
                                if(first[p.R[j]].find(constants::EPSILON) == first[p.R[j]].end()) {
                                    // 2 A -> αBβ => a != ε in FIRST[β], a in FOLLOW[B]
                                    // aB[sentence] find first of sentence
                                    for(const auto &f: first[p.R[j]]) {
                                        follow[p.R[i]].insert(f); // f != ε already
                                    }
                                    return;
                                }
                            }
                            // 3 A -> αBβ && ε in FIRST[β] => a in FOLLOW[A], a in FOLLOW[B]
                            for(const auto &f: follow[p.L]) {
                                follow[p.R[i]].insert(f);
                            }
                        }();
                    }
                    else {
                        // 3 A -> αB => a in FOLLOW[A], a in FOLLOW[B]
                        for(const auto &f: follow[p.L]) {
                            follow[p.R[i]].insert(f);
                        }
                    }
                    changed = first[p.R[i]].size() != size || changed;
                }
            }
        }
    }
    // print FOLLOW set
    utils::coutWithColor("FOLLOW set: ", constants::color::RED_TEXT) << std::endl;
    for (const auto& pair : follow) {
        std::cout << "FOLLOW[" << std::quoted(pair.first) << "]: { ";
        for(const auto& s: pair.second ) {
            std::cout << std::quoted(s) << " ";
        }
        std::cout << "}"<< std::endl;
    }
}

void Parser::getSLR1Table() {
    // augmented grammar G'
    G.S = "Program'";
    G.V.push_back(G.S);
    G.P.push_back({"Program'", {"Program"}});
    // find closure of (Program' -> ·Program)
    typeI start = {{Item(G.P.size()-1,0)}}; // Program' -> ·Program
    // 1 find C of G'
    typeC C = {{start.closure(G)}};
    bool changed = true;
    while(changed) {
        changed = false;
        const int size = C.I.size();
        std::set<typeI> temp = {};
        for(auto& I: C.I) {
            for(const auto& X: G.V) {
                temp.insert(I.go(G, X));
            }
            for(const auto& X: G.T) {
                temp.insert(I.go(G, X));
            }
        }
        for(auto& I: temp) {
            if(I.items.size() != 0) {
                C.I.insert({I.items});
            }
        }
        changed = C.I.size() != size || changed;
    }
    std::map<typeI, int> IIndex;
    int IIndexSize = 0;
    for(auto & I: C.I) {
        IIndex[I] = IIndexSize++;
    }
    // print C
    utils::coutWithColor("C = {I1, I2, ..., In}: ", constants::color::RED_TEXT) << std::endl;
    for(auto & I: C.I) {
        I.print(IIndex[I]);
        for(const auto & item: I.items) {
            auto p = G.P[item.pIndex];
            p.printProduct(item.dotIndex);
        }
    }
    // 2 find GOTO
    for(auto & I: C.I) {
        for(const auto& v: G.V) {
            const int i = IIndex[I];
            if(const auto go = I.go(G, v); IIndex.find(go) != IIndex.end()) {
                const int j = IIndex[go];
                gotoTable[{std::to_string(i), v}] = std::to_string(j);
            }
        }
    }
    // print GOTO
    utils::coutWithColor("GOTO: ", constants::color::RED_TEXT) << std::endl;
    std::cout << std::left << std::setw(5) << "#";
    for(const auto& v: G.V) {
        if(v != "Program'") {
            std::cout << std::left << std::setw(21) << v;
        }
    }
    std::cout << std::endl;
    for(int i = 0; i < IIndexSize; i++) {
        std::cout << std::setw(5) << i;
        for(const auto& v: G.V) {
            if(v != "Program'") {
                std::cout << std::left << std::setw(21) << gotoTable[{std::to_string(i), v}];
            }
        }
        std::cout << std::endl;
    }
    // 3 find ACTION
    for(auto & I: C.I) {
        const int i = IIndex[I];
        for(auto [pIndex, dotIndex]: I.items) {
            // 1 Ii A -> α·aβ, GOTO[IIndex(Ii), a] = j, a in T => ACTION[IIndex(Ii), a] = sj
            if(dotIndex < G.P[pIndex].R.size()) {
                auto a = G.P[pIndex].R[dotIndex];
                if(std::find(G.T.begin(), G.T.end(), a) != G.T.end()) {
                    actionTable[{std::to_string(i), a}] = "s"+std::to_string(IIndex[I.go(G, a)]);
                }
            }
            else {
                auto p = G.P[pIndex];
                if(p.L == "Program'" && p.R[0] == "Program" && dotIndex == 1) {
                    // 3 Ii S' -> S· => ACTION[i, $] = acc
                    actionTable[{std::to_string(i), "$"}] = "acc";
                }
                else {
                    // 2 Ii A -> α· => a in FOLLOW(A), ACTION[i, a] = A -> α
                    auto followA = follow[p.L];
                    for(const auto& a : followA) {
                        actionTable[{std::to_string(i), a}] = "r"+std::to_string(pIndex);
                    }
                }
            }
        }
    }
    // print ACTION
    utils::coutWithColor("ACTION: ", constants::color::RED_TEXT) << std::endl;
    std::cout << std::left << std::setw(5) << "#";
    for(const auto& t: G.T) {
        std::cout << std::left << std::setw(10) << t;
    }
    std::cout << std::left << std::setw(10) << "$";
    std::cout << std::endl;
    for(int i = 0; i < IIndexSize; i++) {
        std::cout << std::setw(5) << i;
        for(const auto& t: G.T) {
            std::cout << std::left << std::setw(10) << actionTable[{std::to_string(i), t}];
        }
        std::cout << std::left << std::setw(10) << actionTable[{std::to_string(i), "$"}];
        std::cout << std::endl;
    }
}
