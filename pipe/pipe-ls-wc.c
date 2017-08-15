#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
/**
 实现父进程使用ls并将结果输出到管道，子进程读取结果并用wc统计
**/

void main()
{
  int pipe_fd[2]={0};
  pid_t pid;
  char buf[100];  
  if(pipe(pipe_fd)==-1)
  {
	perror("pipe call error");
  }

  pid = fork();

  if(pid==-1)
  {
	perror("fork error");
  }
  else if(pid==0) // 子进程
  {
	close(pipe_fd[1]);  // 子进程读，关闭写端
	int ret;
//	while((ret=read(pipe_fd[0],buf,sizeof(buf))) >0)  // 如果读到数据则输出
//		write(STDOUT_FILENO,buf,ret);
	dup2(pipe_fd[0],STDIN_FILENO);  // 将标准输入重定向到管道读端
	execlp("wc","wc","-l",NULL);
	close(pipe_fd[0]);
  }
  else  // 父进程
  {
	close(pipe_fd[0]); // 父进程写，关闭读端
	dup2(pipe_fd[1],STDOUT_FILENO); // 将标准输出变为管道
	execlp("ls","ls",NULL);
	close(pipe_fd[1]);
  }

}
