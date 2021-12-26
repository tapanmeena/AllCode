#include <bits/stdc++.h>
#include <sstream>
#include <string>
using namespace std;

string RunLength(string str)
{
    int n = str.length();
    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]){
            count=count+1;
            i=i+1;
        }
        stringstream ss;  
        ss<<count;  
        string s;  
        ss>>s;
        cout <<s<< str[i];
        s.clear();
    }
    return "sad";
}

int main(void)
{
    string str  = "wwwbbbw";
    RunLength(str);
    return 0;
} 

