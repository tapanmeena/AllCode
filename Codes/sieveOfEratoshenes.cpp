#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n = 50;
	bool prime[n+1];
	memset(prime, true, sizeof(prime));

	for(int i=2; i*i<=n;i++)
	{
		if(prime[i])
		{
			for(int j=i*i; j<=n; j += i)
				prime[j] = false;
		}
	}
	vector<int> primeV;
	for(int i=2;i<n;i++)
		if(prime[i])
			primeV.push_back(i);
	cout<<primeV[primeV.size()-1]<<endl;
			// cout<<i<<" ";
	// cout<<endl;
}