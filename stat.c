#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>

void main(int argc,char* argv[])
{
 if(argc!=2)
 {
   perror("argument error");
   exit(1);
 }

  struct stat buf;
  int res=-1;
  res = stat(argv[1],&buf);
  if(res==0)
  {
    printf("st_ino=%ld\n",buf.st_ino);
    printf("st_size=%ld\n",buf.st_size);
    printf("st_nlink=%d\n",(int)buf.st_nlink);
    printf("st_mode=%#x\n",buf.st_mode);
  
   if(S_ISREG(buf.st_mode))
   {
    printf("regular file\n");
   }
   else if(S_ISDIR(buf.st_mode))
   {
    printf("directory\n");
   }
  }
  else
  {
   perror("stat failure");
   exit(1);
  }
}
