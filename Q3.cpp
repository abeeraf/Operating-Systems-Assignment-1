#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;

int main(){


	float v,w,x,y,z;
	int resultB=0,resultC=0,resultD=0;
	int resultE=0,resultF=0,resultG=0;

	float total;	

	cout<<"Enter value of v: "<<endl;
	cin>>v;
	cout<<"Enter value of w: "<<endl;
	cin>>w;
	cout<<"Enter value of x: "<<endl;
	cin>>x;
	cout<<"Enter value of y: "<<endl;
	cin>>y;
	cout<<"Enter value of z: "<<endl;
	cin>>z;

	pid_t pid=fork();

	if ( pid > 0 ){
		//Parent code
		// process A
		wait(&resultB);
		
		pid=fork();
		if ( pid > 0 ){
		wait(&resultC);

			pid=fork();
			if ( pid > 0){
				wait(&resultD);
			}
			else if ( pid == 0){
				
				resultD= z - x;
				cout<<"z - x = "<<resultD<<endl;
				exit(resultD);
			}
	cout<<resultC/256<<endl;
	cout<<"Final Result = "<<resultB/256+resultC/256+resultD/256<<endl;
		}
		else if (pid == 0)
		{
			// Process C
			pid=fork(); // F created 
			if ( pid > 0)
			{	
				wait(&resultF);
				pid=fork();
				if ( pid > 0){
				wait(&resultG);
				resultC=resultG/256+resultF/256;
				exit(resultC);
				}				
				else if	( pid == 0 ){			
				resultG=v+x;
				cout<<"v + x = "<<resultG<<endl;
				exit(resultG);
				}
				
			}
			else if (pid == 0)
			{	
				resultF= w + v;
				cout<<"w + v = "<<resultF<<endl;
				exit(resultF);
			}
		}	

	}
	else if( pid == 0 ){
		//Child Code
		// IN B
		pid=fork();// E created
		if ( pid > 0)
		{	//In process B
			wait(&resultE);//Entering E child of B
			resultB=w*resultE/256;
			cout<<"w * (x + y) = "<<resultB<<endl;
			exit(resultB);
		}
		else if ( pid == 0 )// In process E
		{	 
			resultE=x+y;
			cout<<"x + y = "<<resultE<<endl;
			exit(resultE);
		}

	}
	

	cout<<"Now computing result directly ---> w*(x+y)+[(w+v)+(v+x)]+(z-x)="<<w*(x+y)+((w+v)+(v+x))+(z-x)<<endl;
}
