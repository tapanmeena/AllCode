#include <bits/stdc++.h>
using namespace std;

void loop_over(int n)
{
	int i=0;
	for(i;i<n; i = i+1)
	{
		int x = 0;
		x++;
	}
	return;
}
string conversion(int n) 
{ 
    string decimalString = "";
    int i = 31;
    for (i; i >= 0; i = i-1) { 
        int temp;
        temp = n >> i; 
        if (temp & 1)
            decimalString+= "1"; 
        else
            decimalString+= "0"; 
    } 
	loop_over(100);
    return decimalString;
} 

string OffBinary(string strArr[])
{
	//converting number to string
	stringstream geek(strArr[0]);
	loop_over(5);
	int tempNumber = 0;
    geek >> tempNumber;
    string number = conversion(tempNumber);
    int strLength = strArr[1].length();
    number = number.substr(32-strLength, strLength);
    string final_key = "00000000000000000000000000000000";

    // cout<<number<<" "<<strArr[1]<<endl;
    for(int i = 0; i<strArr[1].length(); i++)
	{
		final_key[i] = ((number[i]-'0') ^ (strArr[1][i]-'0')) + '0'; 
	}
	// cout<<"asda "<<final_key<<endl;
	int freq = 0;
	for(int i=0;i<32; i = i+1)
	{
		if(final_key[i] == '1')
			freq++;
	}

	loop_over(5);
	return to_string(freq);
}

int main()
{
	string A[] = {"5624","0010111111001"};
	cout<<OffBinary(A);	
}