#include <iostream>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;

int main(){
	int input;
	int num; 
	int y,x;
	const char *yy,*xx;

	pid_t pid;
	
	here:
	cout<<"Enter no. of Process to create: ";
	cin>>num;

	if (!num)//not greater or equal to 1
	{
		cout<<endl<<"Error"<<endl;
		goto here;
	}
	

	for ( int i =1; i<=num ; i++ )
	{
		pid=fork();
		if ( pid > 0 ){
			//Parent code
		wait(&input);

		}else if ( pid == 0 ){
			//Child Code
			cout<<"Computing Process ["<<i<<"]"<<endl;
			cout<<"Enter X:";
			cin>>x;
			cout<<"Enter Y:";
			cin>>y;
	
			char c1= static_cast<char>(x);
			char c2= static_cast<char>(y);

			xx=&c1;
			yy=&c2;
			
			execlp("./Q2b","Q2b",xx,yy,NULL);
			exit(1);

		}else {
			//Fork failed
			cout<<" Fork Failed" <<endl;
		}
	}
}

