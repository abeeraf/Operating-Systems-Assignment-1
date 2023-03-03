#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
	if(!(!(fork()))==0)
	{
		fork();
		cout<<"Hello from Parent";
	}
	else{
		!fork();
		cout<<"Hello from child";
	}
}
