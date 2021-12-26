#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int jj=1;jj<=t;jj++)
	{
		int n,k,p;
		cin>>n>>k>>p;
		vector<vector<int>> vec(n, vector<int>(k,0));
		for(int i=0;i<n;i++)
		    for(int j=0;j<k;j++)
		        cin>>vec[i][j];
		int sums[n][k];
        for(int i=0;i<n;i++)
        {
            int count = 0;
            for(int j=k-1; j>=0;j--)
            {
                count += vec[i][j];
                sums[i][j] = count;
            }
        }
        int dp[n+1][p+1];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;i<=k;j++)
            {
                dp[i][j] = dp[i-1][j];
                for(int z=k-1; z>=k-1-(j-1); z--)
                {
                    int count = k-z;
                    dp[i][j] = max(dp[i][j],dp[i][j-count] + sums[i-1][z]);
                }
            }
        }
		cout<<"Case #"<<jj<<": "<<dp[n][k];
	}
}