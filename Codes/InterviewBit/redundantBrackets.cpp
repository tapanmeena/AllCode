#include <bits/stdc++.h>
using namespace std;

int braces(string A)
{
	stack<char> charStack;
	int n = A.size();
	for(int i=0; i<n; i++)
	{
		if(A[i] == '(' || A[i] == '+' || A[i] == '-' || A[i] == '/' || A[i] == '*')
			charStack.push(A[i]);
		else if(A[i] == ')')
		{
			if(charStack.top() == '(')
				return 1;
			else
			{
				while(!charStack.empty() && charStack.top() != '(')
				{
					charStack.pop();
				}
				charStack.pop();
			}
		}
	}
	return 0;
}

int main()
{
	// while(true)
	// {
		// string A = "((a + b))";
		string A = "(a + (a + b))";
		// cin>>A;
		cout<<braces(A)<<endl;		
	// }
}
