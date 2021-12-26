#include <bits/stdc++.h>
using namespace std;

bool palindromeChecker(string str)
{
	int n = str.length(), t;
	stack<char> s;
	for(int i=0;i<n/2;i++)
		s.push(str[i]);
	if(n & 1)
		t = (n/2)+1;
	else
		t = n/2;

	for(int i=t;i<n;i++)
	{
		if(str[i] != s.top())
			return false;
		s.pop();
	}
	return true;
}

int main()
{
	string str;
	// cin>>str;
	str = "madam is good";
	string temp = "";
	for(int i=0;i<str.length();i++)
	{
		if(str[i] != ' ')
			temp += str[i];
		if(str[i] == ' ')
		{
			if(palindromeChecker(temp))
				cout<<temp<<endl;
			temp = "";
		}
		else if(str[i] != ' ' && i==str.length()-1)
		{
			if(palindromeChecker(temp))
				cout<<temp<<endl;
			temp = "";
		}
	}
}