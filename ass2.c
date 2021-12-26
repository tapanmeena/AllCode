#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(){
	char hel[] = "Hello World";
	for(int i=0; i<strlen(hel); i++){
		int temp = fork();
		wait(NULL);
		if(temp>0)
			return 0;
		else
			printf("%c",hel[i]);
		fflush(stdout);
	}
}
