#include"linklist.h"

void main()
{
	LinkList* list = init_LinkList();
	insert(list,1); 
	insert(list,2); 
	insert(list,3); 
	insert(list,5); 
	insert(list,7); 
	printf("elements size:%d\n",list->length);
	printList(list);
	destoryLinkList(list);
}
