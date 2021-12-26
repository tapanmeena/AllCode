#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vect;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vect.push_back(temp);
    }
    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << endl;
}

/************
[1,2]
1+2 = 3

[1,5,2,1]
1+3+2+1 = 7

************/