#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n = 188;
	int size_n = floor(log10(n) + 1);
	cout<<"Digits "<<size_n<<endl;
	int digit_arr[10];
	memset(digit_arr, 0, sizeof(digit_arr));
	for(int i=0;i<size_n;i++)
	{
		digit_arr[n%10]++;
		n = n/10;
	}
	for(int i=0;i<10;i++)
		cout<<digit_arr[i]<<" ";
	cout<<endl;

	for(int i=104;i<1000;i+=8)
	{
		frequency[10];
		memset(frequency, 0, sizeof(frequency));

		int val = i;
		frequency[val%10]++;
		val = val/10;
		frequency[val%10]++;
		val = val/10;
		frequency[val%10]++;
		val = val/10;

		val = i;

		if(frequency[val%10] > digit_arr[val%10])
			continue;
		val = val/10;
	}	
}