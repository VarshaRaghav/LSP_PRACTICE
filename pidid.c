#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("My PID is %d My Parent PID is %d\n", getpid(),getppid());
}
