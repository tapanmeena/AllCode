#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	int caseNumber = 1;
	while(t--)
	{
		string str;
		cin>>str;
		string result = "";
		int curr = 0;
		for(int i=0;i<str.length();i++)
		{
			// cout<<str[i];
			// cout<<str[i]<<" ";
			int next = str[i] - '0';
			int n = curr - next;
			if(n<0)
			{
				n *= -1;
				for(int j=0;j<n;j++)
					result += "(";
			}
			else if(n>0)
			{
				for(int j=0;j<n;j++)
					result += ")";
			}
			string s = to_string(next);
			result += s;
			curr = str[i] - '0';
			// cout<<n;

			// cout<<"i "<<i<<" "<<result<<endl;
		}
		for(int i=0;i<curr;i++)
			result+=")";
		// cout<<endl;
		cout<<"Case #"<<caseNumber<<": "<<result<<endl;
		caseNumber++;
	}
}