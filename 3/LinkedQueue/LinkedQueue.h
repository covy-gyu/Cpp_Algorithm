#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string>

typedef struct tagNode
{
	char* Data;
	struct tagNode* NextNode;
} Node;

typedef struct tagLinkedQueue
{
	Node* Front;
	Node* Rear;
	int Count;
} LinkedQueue;

void LQ_CreateQueue(LinkedQueue** Queue);
void LQ_DestroyQueue(LinkedQueue* Queue);

Node* LQ_CreateNode(const char* NewData);
void LQ_DestroyNode(Node* _Node);

void LQ_EnQueue(LinkedQueue* Queue, Node* NewNode);
Node* LQ_DeQueue(LinkedQueue* Queue);

int LQ_IsEmpty(LinkedQueue* Queue);

#endif