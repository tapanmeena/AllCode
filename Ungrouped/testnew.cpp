#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int dir[n+1][2];
	for(int i=1;i<n;i++)
	{
		cin>>dir[i][0]>>dir[i][1];
	}
	int vis[n+1][2];
	memset(vis,0,sizeof(vis));
	int fre[n+1];
	memset(fre,0,sizeof(fre));
	int curr=1;
	int cnt = 0;
	int tle=0,ff=0;
	while(curr!=n)
	{
		tle++;
		if(tle>6000000)
		{
			ff=1;
			break;
		}
		cnt++;
		fre[curr]++;
		int flag=0;
		if(fre[curr]%2==0)
			flag=1;
		curr=dir[curr][flag];
	}
	if(ff==1)
		cout<<"IMPOSSIBLE";
	else
		cout<<cnt<<endl;
	return 0;
}

