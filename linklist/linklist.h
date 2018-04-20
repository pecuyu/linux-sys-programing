//#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef struct LN
{
	int value;
	struct LN* next;
} LinkNode;

typedef struct 
{
	LinkNode* head;
	LinkNode* tail;
	int length;
} LinkList;


LinkList* init_LinkList();


void insert(LinkList* list,int value);
 

int getElementSize(LinkList* list);



void printList(LinkList* list);

void destoryLinkList(LinkList* list);
