#include <bits/stdc++.h>
using namespace std;

double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
{
    priority_queue<pair<double, int>> pq;
    double totalProfit = 0;
    int n = classes.size();
    for (int i = 0; i < classes.size(); i++)
    {
        totalProfit += ((classes[i][0]) * 1.0 / (classes[i][1]));
        double profit = ((classes[i][0] + 1) * 1.0 / (classes[i][1] + 1)) - ((classes[i][0]) * 1.0 / (classes[i][1]));
        // cout << " profit: " << profit << endl;
        pq.push({profit, i});
    }
    // cout << totalProfit*1.0/4 << endl;
    while (extraStudents)
    {
        extraStudents--;
        pair<double, int> tempPair = pq.top();
        pq.pop();
        totalProfit += tempPair.first;
        // cout << "temp pair: " << tempPair.first << "\t s: " << tempPair.second << endl;
        classes[tempPair.second][0] += 1;
        classes[tempPair.second][1] += 1;
        // cout << "class pair: " << classes[tempPair.second][0] << "\t sp: " << classes[tempPair.second][1] << endl;
        // cout<<" t: "<<((classes[tempPair.second][0] + 1) * 1.0 / (classes[tempPair.second][1] + 1))<<endl;
        double profit = ((classes[tempPair.second][0] + 1) * 1.0 / (classes[tempPair.second][1] + 1)) - ((classes[tempPair.second][0]) * 1.0 / (classes[tempPair.second][1]));
        // cout<<"prof: "<<profit<<endl;
        pq.push({profit, tempPair.second});
    }
    // while (!pq.empty())
    // {
    //     pair<double, int> tempPair = pq.top();
    //     pq.pop();
    //     cout << " tp: " << tempPair.first << endl;
    //     // totalProfit += tempPair.first;
    // }

    return (totalProfit * 1.0 / n);
}

int main()
{
    vector<vector<int>> classes{{1, 2}, {3, 5}, {2, 2}};
    cout << maxAverageRatio(classes, 2);
}