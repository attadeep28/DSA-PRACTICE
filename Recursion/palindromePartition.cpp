#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int lo, int hi, string s)
{
    while (lo <= hi)
    {
        if (s[lo++] != s[hi--])
            return false;
    }
    return true;
}
void f(int start, string s, vector<string> &ds)
{
    if (start == s.size())
    {
        for (auto str : ds)
            cout << str << " ";
        cout << endl;
        return;
    }

    for (int i = start; i < s.size(); i++)
    {
        if (isPalindrome(start, i, s))
        {
            ds.push_back(s.substr(start, i - start + 1));
            f(i + 1, s, ds);
            ds.pop_back();
        }
    }
}
int main()
{
    string s = "aab";
    vector<string> ds;
    f(0, s, ds);
    return 0;
}