//
// Created by shiokiri on 23-10-25.
//

#include "parser.h"

void Parser::syntaxAnalysis() {
    // initialization
    tokens.push_back({"$", "$"});
    std::vector<std::string> stack, symbol;
    stack.push_back("0");
    symbol.push_back("$");
    int tokenIndex = 0, step = 1;
    // print tokens
    utils::print("Tokens:", constants::color::RED_TEXT) << std::endl;
    for(const auto& token : tokens) {
        std::cout << "[" + token.first + " " + token.second + "] ";
    }
    std::cout << std::endl;
    // begin analysis
    utils::print("Syntax Analysis: ", constants::color::RED_TEXT) << std::endl;
    auto getTokenType = [this](int const index) {
        if(index >= tokens.size()) {
            return tokens[tokens.size()-1].first;
        }
        std::pair pair = tokens[index];
        if(pair.second == "identifier" || pair.second == "literal") {
            return pair.second;
        } else {
            return pair.first;
        }
    };
    std::string a = getTokenType(tokenIndex);
    while(true) {
        std::string const s = stack.back();
        for(int i = 0; i <= 200; i++) {
            utils::print("-", constants::color::YELLOW_TEXT);
        }
        std::cout << std::endl;
        utils::print("Step: " + std::to_string(step++), constants::color::CARMINE_TEXT) << std::endl;
        utils::print("Status: ", constants::color::LIGHT_RED_TEXT);
        for(auto const& sta : stack) {
            std::cout << sta << " ";
        }
        std::cout << std::endl;
        utils::print("Symbol: ", constants::color::LIGHT_BLUE_TEXT);
        for(auto const& sym : symbol) {
            std::cout << sym << " ";
        }
        std::cout << std::endl;
        utils::print("Input: ", constants::color::LIGHT_GREEN_TEXT);
        for(int i = tokenIndex; i < tokens.size(); i++) {
            std::cout << getTokenType(i) << " ";
        }
        std::cout << std::endl;
        utils::print(actionTable[{s, a}] + ": ", constants::color::BLUE_TEXT);
        if(auto act = actionTable[{s, a}]; act[0] == 's') {
            // shift
            stack.push_back(act.erase(0, 1));
            symbol.push_back(a);
            std::cout << "Shift " + a << std::endl;
            tokenIndex++;
            a = getTokenType(tokenIndex);
        } else if(act[0] == 'r') {
            // reduce
            int const pIndex = std::stoi(act.erase(0, 1));
            Product p = G.P[pIndex]; // shift A -> β => pop|β|
            for(int i = 0; i < p.R.size(); i++) {
                if(!stack.empty()) {
                    stack.pop_back();
                    symbol.pop_back();
                }
            }
            std::string const t = stack.back();
            stack.push_back(gotoTable[{t, p.L}]); // GOTO[t, A]
            symbol.push_back(p.L);
            std::cout << "Reduce Product " + std::to_string(pIndex) + ": ";
            p.printProduct();
        } else if(act == "acc") {
            // accept
            utils::print("Accept! Syntax analysis completed.", constants::color::CYAN_TEXT) << std::endl;
            break;
        } else {
            // error
            utils::print("Error!", constants::color::YELLOW_TEXT) << std::endl;
            break;
        }
    }
}

void Parser::getFirst() {
    // initialization
    // V => (V, [])
    for (auto const& v: G.V) {
        first[v] = {};
    }
    // 1 X in T => FIRST[X] = {X}
    // T => (T, [T])
    for (auto const& t: G.T) {
        first[t] = { t };
    }
    // 3 (X -> ε) => ε in FIRST[X]
    // ε in P.R => (P.L, ε)
    for(auto const& p: G.P) {
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
        for (auto const& p: G.P) {
            auto findEpsilonIndex = [&]() {
                for (int i = 0; i <= p.R.size() - 1; i++) {
                    auto const first_Yi = first[p.R[i]];
                    // ε not in FIRST[Y(1-i-1)]
                    if(first_Yi.find(constants::EPSILON) == first_Yi.end()) {
                        return i;
                    }
                }
                // ε in FIRST[Y(1-k)]
                return -1;
            };
            if(int const index = findEpsilonIndex(); index == -1) {
                first[p.L].insert(constants::EPSILON);
                changed = true;
            }
            else {
                int const size = first[p.L].size();
                for(auto const& s : first[p.R[index]]) {
                    if(s != constants::EPSILON) {
                        first[p.L].insert(s);
                    }
                }
                changed = first[p.L].size() != size || changed;
            }
        }
    }
    // print FIRST set
    utils::print("FIRST set: ", constants::color::RED_TEXT) << std::endl;
    for (auto const& pair : first) {
        std::cout << "FIRST[" << std::quoted(pair.first) << "]: { ";
        for(auto const& s : pair.second) {
            std::cout << std::quoted(s) << " ";
        }
        std::cout << "}"<< std::endl;
    }
}

void Parser::getFollow() {
    // initialization
    // V => (V, [])
    for (auto const& v : G.V) {
        follow[v] = {};
    }
    // 1 S => (S, [$])
    follow[G.S].insert("$");
    bool changed = true;
    while (changed) {
        changed = false;
        for (auto const& p : G.P) {
            for(int i = 0; i <= p.R.size()-1; i++) {
                if(std::find(G.V.begin(), G.V.end(), p.R[i]) != G.V.end()) {
                    int const size = first[p.R[i]].size();
                    if(i < p.R.size()-1) {
                        // 2 A -> αBβ => a != ε in FIRST[β], a in FOLLOW[B]
                        for(auto const& f : first[p.R[i+1]]
                            | std::views::filter([](auto f) { return f != constants::EPSILON; })) {
                            follow[p.R[i]].insert(f);
                        }
                        // 3 A -> αBβ && ε in FIRST[β] => a in FOLLOW[A], a in FOLLOW[B]
                        if(auto const& beta = first[p.R[i+1]]; beta.find(constants::EPSILON) != beta.end()) {
                            for(auto const& f : follow[p.L]) {
                                follow[p.R[i]].insert(f);
                            }
                        }
                    }
                    else {
                        // 3 A -> αB => a in FOLLOW[A], a in FOLLOW[B]
                        for(auto const& f : follow[p.L]) {
                            follow[p.R[i]].insert(f);
                        }
                    }
                    changed = first[p.R[i]].size() != size || changed;
                }
            }
        }
    }
    // print FOLLOW set
    utils::print("FOLLOW set: ", constants::color::RED_TEXT) << std::endl;
    for (auto const& pair : follow) {
        std::cout << "FOLLOW[" << std::quoted(pair.first) << "]: { ";
        for(auto const& s : pair.second ) {
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
    TypeI start = {{{static_cast<int>(G.P.size()-1), 0}}}; // Program' -> ·Program
    // 1 find C of G'
    TypeC C = {{start.closure(G)}};
    bool changed = true;
    while(changed) {
        changed = false;
        int const size = C.I.size();
        std::set<TypeI> temp = {};
        for(auto const& I: C.I) {
            for(auto const& X: G.V) {
                temp.insert(I.go(G, X));
            }
            for(auto const& X: G.T) {
                temp.insert(I.go(G, X));
            }
        }
        for(auto const& I: temp | std::views::filter([](auto const& I){ return I.items.size() != 0; })) {
            C.I.insert({I.items});
        }
        changed = C.I.size() != size || changed;
    }
    std::map<TypeI, int> IIndex;
    int IIndexSize = 0;
    for(auto const& I: C.I) {
        IIndex[I] = IIndexSize++;
    }
    // print C
    utils::print("C = {I1, I2, ..., In}: ", constants::color::RED_TEXT) << std::endl;
    for(auto const& I: C.I) {
        I.print(IIndex[I]);
        for(auto const& item: I.items) {
            auto const p = G.P[item.pIndex];
            p.printProduct(item.dotIndex);
        }
    }
    // 2 find GOTO
    for(auto const& I: C.I) {
        for(auto const& v: G.V) {
            int const i = IIndex[I];
            if(auto const go = I.go(G, v); IIndex.find(go) != IIndex.end()) {
                int const j = IIndex[go];
                gotoTable[{std::to_string(i), v}] = std::to_string(j);
            }
        }
    }
    // print GOTO
    utils::print("GOTO: ", constants::color::RED_TEXT) << std::endl;
    std::cout << std::left << std::setw(5) << "#";
    for(auto const& v: G.V | std::views::filter([](auto const& v) { return v != "Program'"; })) {
        std::cout << std::left << std::setw(20) << v;
    }
    std::cout << std::endl;
    for(int i = 0; i < IIndexSize; i++) {
        std::cout << std::setw(5) << i;
        for(auto const& v: G.V | std::views::filter([](auto const& v) { return v != "Program'"; })) {
                std::cout << std::left << std::setw(20) << gotoTable[{std::to_string(i), v}];
        }
        std::cout << std::endl;
    }
    // 3 find ACTION
    for(auto const& I: C.I) {
        int const i = IIndex[I];
        for(auto const& [pIndex, dotIndex]: I.items) {
            if(dotIndex < G.P[pIndex].R.size()) {
                // 1 Ii A -> α·aβ, GOTO[IIndex(Ii), a] = j, a in T => ACTION[IIndex(Ii), a] = sj
                auto const a = G.P[pIndex].R[dotIndex];
                if(std::find(G.T.begin(), G.T.end(), a) != G.T.end()) {
                    actionTable[{std::to_string(i), a}] = "s"+std::to_string(IIndex[I.go(G, a)]);
                }
            }
            else {
                auto const p = G.P[pIndex];
                if(p.L == "Program'" && p.R[0] == "Program" && dotIndex == 1) {
                    // 3 Ii S' -> S· => ACTION[i, $] = acc
                    actionTable[{std::to_string(i), "$"}] = "acc";
                }
                else {
                    // 2 Ii A -> α· => a in FOLLOW(A), ACTION[i, a] = A -> α
                    auto const followA = follow[p.L];
                    for(auto const& a : followA) {
                        actionTable[{std::to_string(i), a}] = "r"+std::to_string(pIndex);
                    }
                }
            }
        }
    }
    // print ACTION
    utils::print("ACTION: ", constants::color::RED_TEXT) << std::endl;
    std::cout << std::left << std::setw(5) << "#";
    for(auto const& t: G.T) {
        std::cout << std::left << std::setw(10) << t;
    }
    std::cout << std::left << std::setw(10) << "$";
    std::cout << std::endl;
    for(int i = 0; i < IIndexSize; i++) {
        std::cout << std::setw(5) << i;
        for(auto const& t: G.T) {
            std::cout << std::left << std::setw(10) << actionTable[{std::to_string(i), t}];
        }
        std::cout << std::left << std::setw(10) << actionTable[{std::to_string(i), "$"}];
        std::cout << std::endl;
    }
}
