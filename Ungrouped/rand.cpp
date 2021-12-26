#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	srand(time(0));	
	for(int i=0;i<n;i++){
		if(i%5==0)
			cout<<endl;
		cout<<rand()%10+1<<" ";
	}
}