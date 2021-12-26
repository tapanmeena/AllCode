#include <bits/stdc++.h>
using namespace std;

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int majorityElement(const int *A, int n1)
{
    unordered_map<int, int> umap;

    for (int i = 0; i < n1; i++)
        umap[A[i]]++;
    int max = -99;
    int result = 0;
    for (auto i = umap.begin(); i != umap.end(); i++)
        if (max <= i->second)
        {
            max = i->second;
            result = i->first;
        }
    return result;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << majorityElement(arr, n);
}