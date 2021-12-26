#include <bits/stdc++.h>
using namespace std;

bool isCorrect(string s)
{
	int n = s.length();
	stack<char> st;
	st.push(s[0]);
	for(int i=1;i<n;i++)
	{
		if(s[i] == '}' && (st.empty() || st.top() == '}'))
			return false;
		if(s[i] == '{')
			st.push(s[i]);
		else if(s[i] == '}' && st.empty())
			return false;
		else if(!st.empty())
			st.pop();
	}
	if (st.empty())
		return true;
	return false;
}

void sieve(int n)
{
	bool arr[n+1];
	memset(arr, true, sizeof(arr));

	for(int i=2; i*i<n; i++)
	{
		if(arr[i])
		{
			for(int j=i*i; j<=n;j+=i)
				arr[j] = false;
		}
	}

	for(int i=2;i<n;i++)
		if(arr[i])
			cout<<i<<endl;
}

int main()
{
	int n = 121;
	sieve(n+1);
}