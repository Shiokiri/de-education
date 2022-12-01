#include "Kmp.h"

void Kmp::findNext()
{
    for (int i = 2, j = 0; i <= len2; i++)
    {
        while (s2[i] != s2[j+1] && j > 0) j = Next[j];
        if (s2[i] == s2[j+1]) Next[i] = ++j;
    }
}
bool Kmp::kmp()
{
    for (int i = 1, j = 0; i <= len1; i++)
    {
        while (s1[i] != s2[j+1] && j > 0) j = Next[j];
        if (s1[i] == s2[j+1]) ++j;
        if (j == len2) return true;
    }
    return false;
}

bool Kmp::judgeSubString(string a, string b)
{
    len1 = a.length();
    len2 = b.length();
    if(len1 < len2) return false;
    s1 = "0"+a;
    s2 = "0"+b;
    memset(Next, 0, sizeof(Next));
    findNext();
    return kmp();
}
