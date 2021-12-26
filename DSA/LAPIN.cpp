#include<bits/stdc++.h>
using namespace std;

int main()
{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			string s1="", s2="";
			int start = s.length()/2;
			if(s.length()%2 == 1)
				start++;
			for(int j=0;j<s.length()/2;j++)
				s1 += s[j];
			for(int j=start;j<s.length(); j++)
				s2 += s[j];
			sort(s1.begin(),s1.end());
			sort(s2.begin(), s2.end());
			// cout<<"s1 "<<s1<<" s2 "<<s2<<endl;
			if(s1==s2)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	
}