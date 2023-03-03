#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;

int main(){

	int a=5;
	fork();
	cout<<" ID = "<<getpid()<<", Parent ID = "<<getppid()<<endl;
	a++;
	fork();
	cout<<" ID = "<<getpid()<<", Parent ID = "<<getppid()<<endl;
	a++;
	fork();
	cout<<" ID = "<<getpid()<<", Parent ID = "<<getppid()<<endl;
	cout<<endl<<a;
	return 0;
}
	

By repeatedly running the code, I observed that every time there is an ouput of 8 7s (i.e. the number 7 is output 8 times). This is consistent with the fact that the number of precesses created should be 2 raised to the power of the number of forks in the code.The 7s do appear irregularly, sometimes in a line, sometimes after a line or there might be empty lines between them too. This happens because there is a context switch, possibly, before the endl command in run. Also, since the manipulated value of 'a' is to be output at the end of all forks, and since it is incremented twice (the initial value being 5), its final value of 7 is also consistent with the theoratical value. This means that all processes created are being executed till the end. I also added a few extra lines in the code (to display PIDs )and examined the processes' table, which led me to conclude that at times the parent processes are executing before the child processes resulting in the child carrying the ppid of 2084 (this isnt the PID of any process). This means that the child processes are being orphaned. There is no trend in how often they are orphaned. The number of times ranged from 2 to sometimes 5. So it can be concluded that it solely depends on the operating system and its scheduling.  

I tried very hard to locate a zombie process in the process table. The 'top' process would generate a PID which was the next consecutive number of the PID of my last process created with the fork() system call (for e.g. the last PID was 22583 and the PID of the top process would be 22584). In the process table there was never a PID which matched my processes (I was checking as I also output PIDs along with the given code's output). I judged by checking the values near that of the top process's PID and they previous value was at least lower than the top process's PID by a 100 values. So, I could not detect any zombie processes. I ran my code at least 25 times with no luck of finding a zombie entry. 
