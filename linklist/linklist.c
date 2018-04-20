#include "linklist.h"


LinkList* init_LinkList()
{
	LinkList* linklist=(LinkList*)malloc(sizeof(LinkList));
	if(linklist==NULL)
	{
		perror("init LinkList failed");
	}
	
	linklist->head=NULL;
	linklist->tail=NULL;
	linklist->length=0;
	printf("init linklist success\n");	
	return linklist;
}

void insert(LinkList* list,int value)
{
	if(list==NULL) return;
	
	LinkNode* node=(LinkNode*)malloc(sizeof(LinkNode));
	node->value=value;
	if(list->head==NULL)
	{
		list->head=node;
		list->head->next=list->tail;
	}
	else
	{
		if(list->tail==NULL) 
		{
			list->tail=node;
			list->head->next=list->tail;
			list->tail->next=NULL;
		}
		else
		{
			list->tail->next=node;
			list->tail=node;
			list->tail->next=NULL;
		}
	}
	
	list->length++;
} 

int getElementSize(LinkList* list)
{
	if(list==NULL) return -1;
	return list->length;
}


void printList(LinkList* list)
{
	if(list==NULL) return;
	if(list->length>0)
	{
		LinkNode* curNode=list->head;
		while(curNode!=NULL)
		{
			printf("curNode:p:%p,v:%d\n",curNode,curNode->value);
			curNode=curNode->next;
		}
	}
}


void destoryLinkList(LinkList* list)
{
	if(list==NULL) return;
	LinkNode* curNode=list->head;
	LinkNode* next;
	while(curNode!=NULL)
	{
		next=curNode->next;
		free(curNode);
		printf("free node : %p\n",curNode);
		curNode=next;
	}

	free(list);
	printf("free linklist: %p\n",list);
	
	printf("destroy linklist success\n");	

}



