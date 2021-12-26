#include <bits/stdc++.h>
using namespace std;

string reverseString(string s)
{
	int n = s.length();
	string result = "";
	string temp = "";
	for(int i=0;i<n;i++)
	{
		temp += s[i];
		if(s[i] == ' ')
		{
			result = temp+result; 
			temp = "";
		}
	}
	result = temp +" "+result;
	return result;
}

string SimplyreverseString(string s)
{
	int n = s.length();
	for(int i=0; i<n/2; i++)
	{
		char c = s[i];
		s[i] = s[n-i-1];
		s[n-i-1] = c;
	}
	return s;
}

int main()
{
	string s = "my name is tapan";
	cout<<SimplyreverseString(s)<<endl;
	cout<<reverseString(s)<<endl;
	return 0;
}