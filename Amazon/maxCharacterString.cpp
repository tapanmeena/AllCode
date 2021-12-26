//Length of the longest substring without repeating characters

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    string temp = "";
    int maxNum = 0;
    if (s.length() <= 1)
        return s.length();
    for (int i = 0; i < s.length(); i++)
    {
        if (temp.find(s[i]) != -1)
        {
            //found
            temp = temp.substr(temp.find(s[i]) + 1);
        }
        temp += s[i];
        // cout << " temp: " << temp <<"\t op:"<<(temp.size() - maxNum)<< endl;
        // if (temp.length() > maxNum)
            // maxNum = temp.length();
        maxNum = (temp.length() > maxNum) ? temp.length() : maxNum;
        // cout << " maxNum: " << maxNum << "\t templength: " << temp.length() << endl;
    }
    return maxNum;
}

int main()
{
    string str = "abcabcbb";
    cout << lengthOfLongestSubstring(str);
}