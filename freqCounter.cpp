#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	// cin>>str;
	str = "apple";
	
	unordered_map<char, int> freq;
	for(int i=0;i<str.length(); i++)
		freq[str[i]]++;		

	string result = "";
	for(int i=0;i<str.length();i++)
	{
		if(freq[str[i]] > 0)
		{
			result += str[i] + to_string(freq[str[i]])+" ,";
			freq[str[i]] = 0;
		}
	}
	result.pop_back();

	cout<<result<<endl;
}