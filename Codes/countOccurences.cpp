// C++ program to count appearances of 
// a digit 'd' in range from [0..n] 
#include <bits/stdc++.h> 
using namespace std; 

int getOccurence(int n, int d) 
{ 
	int result = 0; // Initialize result 

	// Count appearances in numbers starting 
	// from d. 
	int itr = d; 
	while (itr <= n) 
	{ 
		// When the last digit is equal to d 
		if (itr%10 == d) 
			result++; 

		// When the first digit is equal to d then 
		if (itr != 0 && itr/10 == d) 
		{ 
			// increment result as well as number 
			result++; 
			itr++; 
		} 

		// In case of reverse of number such as 12 and 21 
		else if (itr/10 == d-1) 
			itr = itr + (10 - d); 
		else
			itr = itr+10; 
	} 
	return result; 
} 

// Driver code 
int main(void) 
{ 
	int n = 10001, d = 1; 
	cout << getOccurence(n, d); 
	return 0; 
} 
