#include<unistd.h>
#include<sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include <string.h>

/*
  读进程
*/


typedef struct {
	int age;
	char* name;
} Person;

void main(int argc,char* argv[])
{
	// 参数带共享文件路径
	if(argc<2) perror("wrong arguments!");
	int fd=-1; 
	// 打开共享文件
	fd = open(argv[1],O_RDONLY);
	if(fd<0)
	{
		perror("open file failed");
	}
	Person* pMap;
	// 创建映射区
	pMap = (Person*)mmap(NULL,sizeof(Person),PROT_READ,MAP_SHARED,fd,0);
	if(pMap==MAP_FAILED)
	{
		perror("mmap failed");
		exit(-1);
	}

	// 关闭文件
	close(fd);
	// 创建Person
	for(;;)
	{
		printf("age=%d,name=%s\n",pMap->age,pMap->name);
		sleep(20);
	}
	// 取消映射
	munmap(pMap,sizeof(Person));
}

