#include <stdio.h>
#include <stdlib.h>
int main(){
	int arr[] = {1,2,3,4,5};
	FILE *fptr;
	fptr = fopen("/home/tapan/Desktop/test.csv","w");
	if (fptr==NULL){
		printf("Error");
		exit(0);
	}
	int i=0;
	for (i=0;i<5; i++)
		fprintf(fptr, "%d",arr[i] );
}