#include <bits/stdc++.h>
using namespace std;

int isValid(string A)
{
	stack<char> s;
	for(int i =0; i<A.size(); i++)
	{
		if(A[i] == '(' || A[i] == '{' || A[i] == '[')
			s.push(A[i]);
		else if(A[i] == ')' )
		{
			if(s.empty())
				return 0;
			if(s.top() == '(')
				s.pop();
			else
				return 0;
		}
		else if(A[i] == '}' )
		{
			if(s.empty())
				return 0;
			if(s.top() == '{')
				s.pop();
			else
				return 0;
		}
		else if(A[i] == ']' )
		{
			if(s.empty())
				return 0;
			if(s.top() == '[')
				s.pop();
			else
				return 0;
		}
	}
	if(s.size() != 0)
		return 0;

	return 1;
}

int main()
{
	string s = "{{}}[([])][]";
	cout<<isValid(s)<<endl;
}