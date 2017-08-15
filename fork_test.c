#include<stdio.h>
#include<unistd.h>

void main()
{
  printf("-------------\n");
  pid_t pid; 
  int i=0;
  for(;i<5;i++)
  {
     pid=fork();
     if(0==pid)
     {
         break;
     }
  }

    if(i<5&&0==pid)
    {
       sleep(i);
       printf("this is child process,pid=%d,ppid=%d\n",getpid(),getppid());
    }
    else
    {	    
       sleep(i);
       printf("this is praent process,pid=%d,ppid=%d\n",getpid(),getppid());
    }
}
