#include <bits/stdc++.h>
using namespace std;

int minPathCost(int mat[][4],int trans[][4],int entry[],int exit[]){
	int first = mat[0][0]+entry[0];
	int second= mat[1][0]+entry[1];
	int firsttemp[] ={0,0};
	int secondtemp[]={0,0};
	vector <int> T1;
	vector <int> T2;
	T1.push_back(entry[0]);
	T1.push_back(mat[0][0]);
	
	T2.push_back(entry[1]);
	T2.push_back(mat[1][0]);

	cout<<first<<" "<<second<<endl;
	for(int i=1;i<4;i++){
		firsttemp[0] = mat[0][i]+first;
		firsttemp[1] = mat[1][i]+first+trans[0][i];
		cout<<"first temp "<<firsttemp[0]<<" "<<firsttemp[1]<<endl;
		secondtemp[0] = mat[1][i]+second;
		secondtemp[1] = mat[0][i]+second+trans[1][i];
		cout<<"second temp "<<secondtemp[0]<<" "<<secondtemp[1]<<endl;
		if(firsttemp[0]<secondtemp[1]){
			first = firsttemp[0];
			T1.push_back(mat[0][i]);
		}
		else{
			first = secondtemp[1];
			T1=T2;
			T1.push_back(mat[1][i]);
		}
		if(firsttemp[1]<secondtemp[0]){
			second = firsttemp[1];
			T2=T1;
			T2.pop_back();
			T2.push_back(mat[1][i]);
		}
		else{
			second = secondtemp[0];
			T2.push_back(mat[1][i]);
		}
		cout<<first<<" "<<second<<endl;
	} 
	first += exit[0];
	second += exit[1];
	if(first>second){
		for(int i=0;i<T2.size();i++)
			cout<<T2[i]<<" -> ";
		return second;
	}
	else{
		for(int i=0;i<T1.size();i++)
			cout<<T1[i]<<" -> ";
		return first;
	}
}

int main(){
	int mat[][4]={{4,5,3,2},{2,10,1,4}};
	int trans[][4]={{0,7,4,3},{0,9,2,8}};
	int entry[]={10,12};
	int exit[] ={18,7};
	int s = minPathCost(mat,trans,entry,exit);
	cout<<"("<<s<<") "<<endl;
}