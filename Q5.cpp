#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;

void SortArray(int* arr)
{
	int temp=0;
	for(int x = 0; x < 7-1; x++)
	{
		for(int y = 0; y < 7-x-1; y++)
		{
			if (arr[y] > arr[y+1]) 
			{ 
            			temp=arr[y];
				arr[y]=arr[y+1];
				arr[y+1]=temp;
			}
		}
	}
	for(int x = 0; x < 7; x++)
	cout<<arr[x]<<",";
	cout<<endl;
}

int main(){
	

	int Array1[7],Array2[7];
	
	cout<<"Enter Array1"<<endl;
	for(int x = 0; x < 7; x++)
	{
		cout<<"Array1["<<x<<"]"<<endl;
		cin>>Array1[x];
	}
	cout<<"Enter Array2"<<endl;
	for(int x = 0; x < 7; x++)
	{
		cout<<"Array2["<<x<<"]"<<endl;
		cin>>Array2[x];
	}	
	
	cout<<"Parent Process Sucessfully Created!"<<endl;
	cout<<"Parent ID = "<<getpid()<<endl<<endl;
	cout<<"Now Creating the Children"<<endl;

	pid_t pid=fork();
	if ( pid > 0)
	{
		pid=fork();// Second Child created
		if ( pid > 0)
		wait(NULL);

		else if	( pid == 0 ){			
		cout<<"This is Child 2:"<<endl;
		cout<<" ID = "<<getpid()<<", Parent ID = "<<getppid()<<endl;
		cout<<"Sorted Array2: ";SortArray(Array2);
		cout<<endl;
		exit(1);
		}
	}
	else if	( pid == 0 ){//First Child created
	cout<<"This is Child 1:"<<endl;
	cout<<" ID = "<<getpid()<<", Parent ID = "<<getppid()<<endl;
	cout<<"Sorted Array1: ";SortArray(Array1);
	cout<<endl;
	}
	exit(1);

}

