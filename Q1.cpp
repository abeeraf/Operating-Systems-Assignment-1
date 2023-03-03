#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;

int main(){
	
	pid_t pid=fork();

	if ( pid > 0 ){
		//Parent code
		cout<<"This is process A:"<<endl;
		cout<<"P1"<<":"<<" ID = "<<getpid()<<", Parent ID = "<<getppid()<<endl;// for Process A
		wait(NULL);/////////////////Will execute after the B Branch///////////////////////////

		cout<<endl<<"BRANCH B COMPLETED,STARTING BRANCH C"<<endl<<endl;//////////////////Starting the C branch/////////////////////////
		pid=fork();
		if ( pid > 0 ){
			wait(NULL);/////////////////Starting the C branch/////////////////////////
			cout<<endl<<"BRANCH C COMPLETED,STARTING BRANCH D"<<endl<<endl;

			pid=fork();
			if ( pid > 0){
				wait(NULL);
			}
			else if ( pid == 0){/////////////////Starting the D branch/////////////////////////
				cout<<"This is process D:"<<endl;
				cout<<"P10"<<":"<<" ID = "<<getpid()<<", Parent ID = "<<getppid()<<endl;// Output D 
			}			
			//////////////////////////////////D branch Ends here//////////////////////
		}
		else if (pid == 0)
		{
			cout<<"This is process C:"<<endl;
			cout<<"P6"<<":"<<" ID = "<<getpid()<<", Parent ID = "<<getppid()<<endl;// Output for C
			pid=fork(); // F created 
			if ( pid > 0)
			{
				pid=fork();
				if ( pid > 0)
				wait(NULL);

				else if	( pid == 0 ){			
				cout<<"This is process G:"<<endl;
				cout<<"P9"<<":"<<" ID = "<<getpid()<<", Parent ID = "<<getppid()<<endl;//Output G
				exit(1);
				}
				
			}
			else if (pid == 0)
			{
				cout<<"This is process F:"<<endl;
				cout<<"P7"<<":"<<" ID = "<<getpid()<<", Parent ID = "<<getppid()<<endl;//Output F
				pid=fork();
				if (pid > 0)
				wait(NULL);
				else if (pid == 0)
				{
					cout<<"This is process H:"<<endl;
					cout<<"P8"<<":"<<" ID = "<<getpid()<<", Parent ID = "<<getppid()<<endl;//Output H
					exit(0);
				}
			}
		}	
	
	//////////////////////////////////C Branch Ends Here//////////////////////
	exit(1);
	}
	//////////////////The B Branch/////////////////////////
	else if ( pid == 0 ){
		//Child Code
		// IN B
		pid=fork();// E created
		if ( pid > 0)
		{
			cout<<"This is process B:"<<endl;
			cout<<"P2"<<":"<<" ID = "<<getpid()<<", Parent ID = "<<getppid()<<endl;// Output B 
			wait(NULL);// Entering E child of B
		}
		else if ( pid == 0 )// In E
		{	
			// In E 
			cout<<"This is process E:"<<endl;		
			cout<<"P3"<<":"<<" ID = "<<getpid()<<", Parent ID = "<<getppid()<<endl;// Output for E
			pid=fork(); // I created 
			if ( pid > 0)
			{
				pid=fork();
				if ( pid > 0)
				wait(NULL);

				else if	( pid == 0 ){			
				cout<<"This is process J:"<<endl;
				cout<<"P5"<<":"<<" ID = "<<getpid()<<", Parent ID = "<<getppid()<<endl;//Output J
				exit(1);
				}
			}
			else if	( pid == 0 ){
			cout<<"This is process I:"<<endl;
			cout<<"P4"<<":"<<" ID = "<<getpid()<<", Parent ID = "<<getppid()<<endl;}//Output I
				
		}
		exit(1);

	}
	////////////////////////B branch ends Here//////////////////////////
	else {
		//Fork failed
		cout<<" Fork Failed" <<endl;
	}
	

}

