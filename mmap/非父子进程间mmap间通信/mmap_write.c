#include<unistd.h>
#include<sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include <string.h>


typedef struct {
	int age;
	char  name[20];
} Person;

void main(int argc,char* argv[])
{
	// 参数带共享文件路径
	if(argc<2) perror("wrong arguments!");
	int fd=-1; 
	// 打开共享文件
	fd = open(argv[1],O_RDWR|O_CREAT,0644);
	if(fd<0)
	{
		perror("open file failed");
	}
	// 拓展文件
	ftruncate(fd,sizeof(Person));
	char* pMap;
	// 创建映射区
	pMap = mmap(NULL,sizeof(Person),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(pMap==MAP_FAILED)
	{
		perror("mmap failed");
		exit(-1);
	}

	// 关闭文件
	close(fd);
	// 创建Person
	Person p = {1,"mmap"};
	for(int i=0;;i++)
	{
		memcpy(pMap,&p,sizeof(Person));
		p.age=i;
		sleep(5);
	}
	// 取消映射
	munmap(pMap,sizeof(Person));
}

