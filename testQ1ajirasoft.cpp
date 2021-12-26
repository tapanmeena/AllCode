#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int mat[n+2][2];

	for(int i=1;i<n;i++)
	{
		cin>>mat[i][0]>>mat[i][1];
	}

	int frequency[n+2];
	memset(frequency, 0, sizeof(frequency));

	int floore=1,ans=0;
	int tle=0;

	while(floore!=n && tle < 5000000)
	{
		frequency[floore]++;
		floore=mat[floore][(frequency[floore]+1)%2];
		tle++;
		ans++;
	}

	if(floore!=n)
	{
		cout<<"IMPOSSIBLE";
	}
	else
	{
		cout<<ans<<endl;
	}
	return 0;
}