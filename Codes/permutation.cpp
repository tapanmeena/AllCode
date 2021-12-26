#include <bits/stdc++.h>
using namespace std;

vector<string> result;

void permute(string s, int l, int n)
{
	if(l == n)
	{
		result.push_back(s);
		return;
	}
	for(int i=l;i<n;i++)
	{
		swap(s[l], s[i]);
		permute(s, l+1, n);
		swap(s[i], s[l]);
	}
}

int main()
{
	string s = "ABC";
	permute(s,0,s.length());
	for(int i=0; i<result.size();i++)
		cout<<result[i];
	cout<<endl;
}