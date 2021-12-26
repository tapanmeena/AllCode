#include<bits/stdc++.h> 
using namespace std;


string PatternChaser(string str) 
{
	int n = str.length(); 
	int subsArr[n+1][n+1];

	memset(subsArr, 0, sizeof(subsArr)); 

	string result; 
	int rLength = 0;

	int i=1, index = 0; 
	for (i; i<=n; i = i+1) 
	{ 
		for (int j=i+1; j<=n; j = j+1) 
		{ 
			if (str[i-1] == str[j-1] && subsArr[i-1][j-1] < (j - i)) 
			{ 
				subsArr[i][j] = subsArr[i-1][j-1] + 1; 
				if (subsArr[i][j] > rLength) 
				{ 
					rLength = subsArr[i][j]; 
					index = max(i, index); 
				} 
			} 
			else
				subsArr[i][j] = 0; 
		} 
	} 
	if (rLength > 0) 
		for (i = index - rLength + 1; i <= index; i++) 
			result.push_back(str[i-1]); 

	if(rLength<2)
		return "no null";
	return result; 
} 

int main() 
{ 
	string str = "123224"; 
	cout << PatternChaser(str); 
	return 0; 
} 
