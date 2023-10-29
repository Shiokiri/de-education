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
    // Initialize
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
            auto findEpsilonIndex = [&]() -> int {
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
    // Initialize
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
                                        follow[p.L].insert(f); // f != ε already
                                    }
                                    return;
                                }
                            }
                            // 3 A -> αBβ && ε in FIRST[β] => ε in FOLLOW[A], a in FOLLOW[B]
                            for(const auto &f: follow[p.L]) {
                                follow[p.R[i]].insert(f);
                            }
                        }();
                    }
                    else {
                        // 3 A -> αB => ε in FOLLOW[A], a in FOLLOW[B]
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

}