#include <stdio.h>
int main() {
	int pid;
	pid = fork();    //创建进程
	if(pid == 0) {      //子进程创建成功
		printf("I am the child,my pid is %d!\n",getpid());
	} else {
		printf("I am the parent,my pid is %d,my child pid is %d!\n",getpid(),pid);
	}
}

