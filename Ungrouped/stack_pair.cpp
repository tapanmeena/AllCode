#include <bits/stdc++.h>
using namespace std;

#define inputArray(arr,n) for(int ia = 0; ia<n; ia++) cin>>arr[ia]
#define printArray(arr,n) for(int ia = 0; ia<n; ia++) cout<<arr[ia]<<" "
#define lli long long int

int main(){
	stack <pair<int,int>> s;
	int arr[] = {1,2,7,19,1,7,123,7,2,125};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	for(int i=0; i<arr_size; i++){
		if(s.empty()){
			s.push(make_pair(arr[i],arr[i]));
		}
		else if(s.top().second < arr[i]){
			s.push(make_pair(arr[i],arr[i]));
		}
		else if(s.top().second > arr[i]){
			s.push(make_pair(arr[i],s.top().second));
		}
	}

	while(!s.empty()){
		auto i = s.top();
		s.pop();
		cout<<"Current Element is "<<i.first<<" Maximum Element is "<<i.second<<endl;
	}
}