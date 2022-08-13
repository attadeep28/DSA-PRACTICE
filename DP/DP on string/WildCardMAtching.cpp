#include <bits/stdc++.h>
using namespace std;
bool f(int i, int j, string s1, string s2)
{
    if (i < 0 and j < 0) return true;

    if (i < 0 and j >= 0) return false;

    if (j < 0 and i >= 0)
    {
        for (auto it : s1)
        {
            if (it != '*')
                return false;
        }
        return true;
    }

    if (s1[i] == s2[j] or s1[i] == '?')

        return f(i - 1, j - 1, s1, s2);

    if (s1[i] == '*')

        return f(i - 1, j, s1, s2) or f(i, j - 1, s1, s2);

    return false;
}
int main()
{
    return 0;
}