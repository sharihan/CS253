#include <stdio.h>
#include <stdlib.h>
#include "List.h"

struct list * createList(int (*equals)(const void *,const void *),
			 char * (*toString)(const void *),
			 void (*freeObject)(void *))
{
	struct list *list;
	list = (struct list *) malloc(sizeof(struct list));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->equals = equals;
	list->toString = toString;
	list->freeObject = freeObject;
	return list;
}

void freeList(struct list *list)

if(list== isEmpty())
  return;

    Node *temp = list-> head;
    
      while(temp != null){
	Node n= temp -> next;
	freeNode(temp, list -> freeObject);
	temp=n;

{
  //setting head and tail to null
       list ->head=null;
       list -> tail= null;
       free(list);
}

int getSize(const struct list *list)
{
	return list -> size;
}

int isEmpty(const struct list *list)
{
	return list->size == 0;
}

void addAtFront(struct list *list, struct node *node)
{
	if (list == NULL) return;
	if (node == NULL) return;
	list->size++;
	node->next = list->head;
	node->prev = NULL;
	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
	} else {
		list->head->prev = node;
		list->head = node;
	}
}

void addAtRear(struct list *list, struct node *node)
{
}

struct node* removeFront(struct list *list)
{
	return NULL;
}

struct node* removeRear(struct list *list)
{
	return NULL;
}

struct node* removeNode(struct list *list, struct node *node)
{
	return NULL;
}

struct node* search(const struct list *list, const void *obj)
{
	return NULL;
}

void reverseList(struct list *list)
{
}

void printList(const struct list *list)
{
	if (!list) return; //list was null!!
	int count = 0;
	char *output;
	struct node *temp = list->head;
	while (temp) {
		output = list->toString(temp->obj);
		printf(" %s -->",output);
		free(output);
		temp = temp->next;
		count++;
		if ((count % 6) == 0)
			printf("\n");
	}
	printf(" NULL \n");
}