#include <bits/stdc++.h>
using namespace std;

#define inputArray(arr,n) for(int ia = 0; ia<n; ia++) cin>>arr[ia]
#define printArray(arr,n) for(int ia = 0; ia<n; ia++) cout<<arr[ia]<<" "
#define lli long long int

int solution(vector<int> &A){
	vector<int> level_wise_sum;
	int start = 0,end = 1,element = 1;
	while(true){
		int temp_sum = 0;
		for(int i=start; i<min(end,n); i++)
			temp_sum += A[i];
		level_wise_sum.push_back(temp_sum);
		start = end;
		element *= 2;
		end += element;
		if(start>=n)
			break;
	}
	int max_sum = INT_MIN, max_sum_level = 0;
	for(int i=0; i<level_wise_sum.size(); i++){
		if( level_wise_sum[i]>max_sum){
			max_sum = level_wise_sum[i];
			max_sum_level = i+1;
		}
	}
	return max_sum_level;
}

int main(){
	vector<int> a;
	a.push_back(-1);	
	a.push_back(7);	
	a.push_back(0);	
	a.push_back(7);	
	a.push_back(-8);
	cout<<solution(a)<<endl;
	return 0;
}