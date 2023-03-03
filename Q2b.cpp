#include<iostream>
#include<math.h>

using namespace std; 

int main(int agc, char *argv[]) 
{
	int sum=0;
	for ( int i = 1; i <= argv[1][0]; i++ )
	{
		sum+=pow(argv[1][1],i);
	}
	cout<<"Sum of Powers is: "<<sum<<endl<<endl;
}

