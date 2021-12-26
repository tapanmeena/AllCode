#include <bits/stdc++.h>
using namespace std;

bool sortcol(const vector<int> &v1,
             const vector<int> &v2)
{
    return v1[1] > v2[1];
}

int rec(vector<vector<int>> &boxTypes, int truckSize, int result, int index)
{
    if (truckSize == 0 || index>=boxTypes.size())
        return result;
    // cout << " trucksize: " << truckSize << "\tresult: " << result << "\tindex: " << index <<"\tboxtypes "<<boxTypes[index][0]<< endl;
    if (truckSize >= boxTypes[index][0])
        return rec(boxTypes, truckSize - boxTypes[index][0], result + (boxTypes[index][0] * boxTypes[index][1]), index + 1);
    else
        return result + (truckSize * boxTypes[index][1]);
}

int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
{
    sort(boxTypes.begin(), boxTypes.end(), sortcol);

    return rec(boxTypes, truckSize, 0, 0);
}

int main()
{
    vector<vector<int>> vect{{5,10},{2,5},{4,7},{3,9}};

    cout << maximumUnits(vect, 10) << endl;
}