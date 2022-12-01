#ifndef KMP_H
#define KMP_H

#include "Singleton.h"

#include <string>
#include <iostream>
#include <cstring>

using std::string;

constexpr int NEXT_MAX = 100005;

class Kmp : public Singleton<Kmp>
{
    friend class Singleton<Kmp>;
public:
    Kmp(const Kmp&) = delete;
    Kmp& operator = (const Kmp&) = delete;
    bool judgeSubString(string, string);

private:
    Kmp() = default;
    int Next[NEXT_MAX];
    string s1, s2;
    int len1, len2;
    void findNext();
    bool kmp();
};

#endif // KMP_H
