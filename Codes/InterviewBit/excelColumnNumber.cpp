#include <bits/stdc++.h>
using namespace std;

int main()
{
	string A = "AB";
	int value = 0;
	for(int i = 0; i<A.size(); i++)
	{
		if(i != 0)
		{
			value *= 26;
		}
		value += A[i] - 65 + 1;
	}
	cout<<value<<endl;
}