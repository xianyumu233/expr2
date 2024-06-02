#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
	int p1,p2,p3,p4,p5,p6,p7;    //定义七个进程
	int end_p1=0,end_p2=0,end_p3=0,end_p4=0,end_p5=0,end_p6=0,end_p7=0;  //设定进程初始都未结束
	int pid, status;

	if((p1=fork())==0) {   //创建进程p1
		//是子进程则输出
		execl("/bin/echo","echo","I am P1",0);
	}
	wait(&status); //等待终止的子进程
	if((p2=fork())==0) { //创建进程p2
		//是子进程则输出
		execl("/bin/echo","echo","I am P2",0);
	}
	if((p3=fork())==0) { //创建进程p3
		//是子进程则输出
		execl("/bin/echo","echo","I am P3",0);
	}
	do {
		pid=wait(&status);//等待终止的子进程
		if(pid==p2) end_p2=1; //置进程p2结束
		if(pid==p3) end_p3=1;//置进程p3结束
	} while(end_p3==0);
	if((p4=fork())==0) { //创建进程p4
		//是子进程则输出
		execl("/bin/echo","echo","I am P4",0);
	}
	if((p5=fork())==0)  {//创建进程p5
		//是子进程则输出
		execl("/bin/echo","echo","I am P5",0);
	}
	do {
		pid=wait(&status);//等待终止的子进程
		if(pid==p4) end_p4=1;//置进程p4结束
		if(pid==p2) end_p2=1;//置进程p2结束
		if(pid==p5) end_p5=1;//置进程p5结束
	} while(end_p4==0||end_p5==0);

	if((p6=fork())==0)  {//创建进程p6
		//是子进程则输出
		execl("/bin/echo","echo","I am P6",0);
	}
	do {
		pid=wait(&status);//等待终止的子进程
		if(pid==p2) end_p2=1;//置进程p2结束
		if(pid==p6) end_p6=1;//置进程p6结束
	} while(end_p2==0||end_p6==0);
	if((p7=fork())==0)  {//创建进程p7
		//是子进程则输出
		execl("/bin/echo","echo","I am P7",0);

	}
	wait(&status);
	exit(1);
}

