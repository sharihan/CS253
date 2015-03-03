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


/**
 * Freeing the list.
 */
void freeList(struct list *list)
{
  if(list== isEmpty())  return;
  struct node *temp = list-> head;
      while(temp != Null){
	freeNode(temp, list->freeObject);
      }
      list->head=NULL;
      List->tail =NULL;
      free(list);
    
}


/**
 * Getting the size of the list.
 * @return size
 */
int getSize(const struct list *list)
{
	return list -> size;
}

/**
 * Checking if the list is empty.
 * @return list=0
 */
int isEmpty(const struct list *list)
{
	return list -> size==0;
}


/**
 * adding from the front of the list.
 * 
 */
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



/**
 * adding from the rear of the list.
 * 
 */
void addAtRear(struct list *list, struct node *node)
{
    
     if (list == NULL) return;
     if (node == NULL) return;
     list -> size ++;
     
      if(list -> tail != NULL){
       list -> tail -> next = node;
   }
   
    if(list -> tail == NULL){
          list -> tail = node;
          list -> head = node;
	  list -> size ++;
          return; 
  }
   
  node -> prev = list -> tail;
  list -> tail = node;
  list -> size++;
  }

  
  
/**
 * Removing from the frony of the list.
 * @return first
 */      

struct node* removeFront(struct list *list)
{
     
  if(list==NULL || list-> size==0) return NULL;
  
    struct node *first = list-> head;
   
  //if we have one node in the list
  if(list -> head && list ->tail){
    list-> head=NULL;
    list -> tail=NULL;
    list->size--;
    return first;

  }
  if(list->head !=NULL){
  
    list-> head= list->head->next;
  }
  
  list->head->prev=NULL;
  first-> next=NULL;
  list-> size--;
  
  
	return first;
}


/**
 * Removing from the rear of the list.
 * @return rear
 * 
 */
struct node* removeRear(struct list *list)
{
 if(list == NULL || list -> size == 0) return NULL;
  
    struct node *rear = list -> tail;
   //if it has one node
    if(list -> head == list -> tail){
      list -> head = NULL;
      list -> tail = NULL;
      
      list -> size --;
      return rear;
    }
 
 // if there is a node at the rear
    if(rear != NULL){
      list -> tail =  list -> tail -> prev;
    } 
    list -> tail -> next = NULL;
    rear -> prev = NULL;
    list -> size --;

    return rear;
}

/**
 * removing a node from a lise
 * @return node
 * 
 */
struct node* removeNode(struct list *list, struct node *node)
{
   if(list == NULL || node==NULL) return 0;
   
   
  if(node -> prev != NULL){
    node -> prev -> next = node -> next;
  }
  
  if(list -> head == node){
    list -> head = list -> head -> next;
  }
  
  if(list -> tail == node){
    list -> tail = list -> tail -> prev;
  }
  
  if(node -> next != NULL){
    node -> next -> prev = node -> prev;
  }
  node -> next = node -> prev = NULL;
  list -> size --;

	return node;
}

struct node* search(const struct list *list, const void *obj)
{
	if(list==0) return NULL;
	
	struct node *temp= list ->head;
	while(temp != NULL){
	  if(list -> getObject(temp->obj)==obj){
	    return temp;
	  }
	  temp=temp-> next;
	}
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
