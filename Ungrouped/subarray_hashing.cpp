#include<bits/stdc++.h>
using namespace std;

#define inputArray(arr,n) for(int ia=0;ia<n;ia++) cin>>arr[i]
#define printArray(arr,n) for(int ia=0;ia<n;ia++) cout<<arr[i]
#define lli long long int

void is_subset(int arr1[], int arr2[], int m, int n){
	map<int,int> map1;
	bool issubset = true;
	for(int i=0; i<m; i++)
		map1[arr1[i]]++;
	for(int i=0; i<n; i++){
		if(map1[arr2[i]]==0){
			issubset = false;
			break;
		}
		else
			map1[arr2[i]]--;
	}
	if(!issubset)
		cout<<"Not a Subset"<<endl;
	else
		cout<<"Arr2 is a subset of Arr1"<<endl;
}

int main(){
	int arr1[] = {11,1,1,13,21,7,1};
	int arr2[] = {11,3,7,1,1,1};
	int m = sizeof(arr1)/sizeof(arr1[0]);
	int n = sizeof(arr2)/sizeof(arr2[0]);
	is_subset(arr1,arr2,m,n);
	return 0;
}