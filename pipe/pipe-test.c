#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<stdio.h>

void main()
{
	int pipe_fd[2]={0}; // pipe_fd[0],pipe_fd[1]分别为读写文件描述符
	pid_t child_pid=-1;
	char buf[10];
	if(pipe(pipe_fd)==-1)
	{
	   perror("pipe error");
	   return;
	} 
	child_pid=fork();
	if(child_pid==-1)
	{
	  perror("fork error");
	  return;
	}

	if(child_pid>0)  //父进程 
	{
	  printf("\n--------this is parent-------\n");
	  close(pipe_fd[0]); // 关闭读端
	  write(pipe_fd[1],"hello",10);
	  close(pipe_fd[1]);
	  wait(NULL);  // 等待
	  return;
	}
	else if(child_pid==0) // 子进程
	{
	  close(pipe_fd[1]);  // 关闭写端
	  int len=0;
	  while((len = read(pipe_fd[0],&buf,sizeof(buf)))>0)
             write(STDOUT_FILENO,&buf,len); // 输出
	  printf("\n--------this is child--------\n");
          close(pipe_fd[0]);
	  return;
	}
}
