#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
/**
  实现兄进程使用ls并将结果输出到管道,弟进程读取结果并用wc统计
 **/

void main()
{
	int pipe_fd[2]={0};
	pid_t pid=-1,wpid;
	char buf[100];  
	if(pipe(pipe_fd)==-1)
	{
		perror("pipe call error");
	}
	int i=0;
	for(;i<2;i++)
	{
		pid = fork();
		if(pid==0)  // 创建子进程成功	
		{
			break;
		}
		if(pid==-1)
		{
			char buf_err[20];
			sprintf(buf_err,"fork %d  error:",i);
			perror(buf_err);
			exit(1);
		}
	}


	if(i == 0) // 子进程1
	{
		close(pipe_fd[0]); //子进程0写，关闭读端
		dup2(pipe_fd[1],STDOUT_FILENO); // 将标准输出变为管道
		execlp("ls","ls",NULL);
	}

	else if(i == 1) // 子进程2
	{
		close(pipe_fd[1]);  // 子进程读，关闭写端
		dup2(pipe_fd[0],STDIN_FILENO);  // 将标准输入重定向到管道读端
		execlp("wc","wc","-l",NULL);
	}

	else if(i == 2)   // 父进程
	{
		close(pipe_fd[0]); // 关闭父进程对管道的读写控制
		close(pipe_fd[1]);
		wpid = wait(NULL);  
		printf("child died, pid=%d\n",wpid);
		wpid = wait(NULL);  
		printf("child died, pid=%d\n",wpid);
	}	

}
