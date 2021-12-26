#include <bits/stdc++.h>
using namespace std;

int findMaximumAllocation(int cost[], int N, int K)
{
    int count = 0, sum = 0; 
  
    sort(cost, cost + N); 
    for (int i = 0; i < N; i++) { 
        if (sum +cost[i] <= K)  
        { 
            sum = sum + cost[i]; 
            count++; 
        } 
    } 
    return count; 
}

int main()
{
    int t;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
        int n,b;
        cin>>n>>b;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout<<"Case #"<<j<<": "<<findMaximumAllocation(arr, n, b)<<endl;
    }
}