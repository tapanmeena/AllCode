#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<string> words = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	int n = 123;
	string s = to_string(n);
	vector<string> result;
	for(int i=0;i<s.length();i++)
	{
		int temp = n%10;
		result.push_back(words[temp]);
		n = n / 10;
	}
	for(int i=2;i>=0;i--)
		cout<<result[i]<<" ";
}