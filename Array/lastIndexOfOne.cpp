#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int index = -1;
		for(int i=0; i<s.size(); i++)
		{
			if(s[i] == '1')
				index = i;
		}
		cout<<index<<endl;
	}
}