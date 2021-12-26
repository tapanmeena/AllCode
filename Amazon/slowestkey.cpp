#include <bits/stdc++.h>
using namespace std;

bool sortCol(const pair<char, int> &p1,
             const pair<char, int> &p2)
{
    return p1.first > p1.second;
}

char slowestKey(vector<int> &releaseTimes, string keysPressed)
{
    int max = releaseTimes[0];
    // vector<pair<char, int>> result;
    // result.push_back({keysPressed[0], releaseTimes[0]});
    char key = keysPressed[0];
    for (int i = 1; i < releaseTimes.size(); i++)
    {
        int temp = releaseTimes[i] - releaseTimes[i - 1];
        if (temp > max)
        {
            max = temp;
            key = keysPressed[i];
            // result.clear();
            // result.push_back({keysPressed[i], temp});
        }
        else if (temp == max)
        {
            if (keysPressed[i] > key)
                key = keysPressed[i];
            // result.push_back({keysPressed[i], temp});
        }
    }
    // sort(result.begin(), result.end(), [](const pair<char, int> &p1, const pair<char, int> &p2)
    //      { return p1.first > p.first; });
    return key;
}

int main()
{
    vector<int> releaseTimes{1, 2};

    cout << slowestKey(releaseTimes, "ba") << endl;
}