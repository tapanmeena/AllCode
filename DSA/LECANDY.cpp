#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		sum += temp;
		if(sum>k)
		{
			cout<<"No"<<endl;
			return 0;
		}
	}
	if(sum<=k)
		cout<<"YES"<<endl;
	else
		cout<<"No"<<endl;
}