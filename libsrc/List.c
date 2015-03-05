#include <stdio.h>
#include <stdlib.h>
#include "List.h"

/**
 * This program implements a doubly linked list using C language.
 * @auther Sali
 */

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
  if(list->size==0 || list==NULL)  return;
  
  struct node *temp = list-> head;
      while(temp != NULL){
	freeNode(temp, list->freeObject);
      }
      list->head=NULL;
      list->tail =NULL;
      
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
	
	return list->size==0; 
    
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
     //if the list is empty or null
     if (list == NULL || list->size==0) return;
     if (node == NULL) return;
     list->size ++;
    
     node->prev=list->tail;
     node->next=NULL;

      //if we have one node
     if(list -> size==1){
          list -> tail = node;
          list -> head = node;
      // if we have more than one node
     }else{
       list->tail->next=node;
       list->tail=node;
       

     }
   
    
  }
   
  
  
/**
 * Removing from the frony of the list.
 * @return first
 */      

struct node* removeFront(struct list *list)
{
  //if the list is empty or null
  if(list==NULL ||list->size==0) return NULL ;
  list->size --;
  
    struct node *first = list-> head;
   
  // if we have one node in the list
  if(list->size==1){
    list-> head=NULL;
    list -> tail=NULL;
    return first;
    
 // if we have more than one node
  }else{
     list-> head= list->head->next;
     list->head->prev=NULL;
     first->next=NULL;
     list->head->prev=NULL;
  }
 
	return first;
}


/**
 * Removing from the rear of the list.
 * @return rear
 * 
 */
struct node* removeRear(struct list *list)
{
    //if the list is empty or null
 if(list == NULL || list->size==0) return NULL;
   list -> size --;
 
    struct node *rear = list -> tail;
    
   //if it has one node
    if(list->size==1){
      list -> head = NULL;
      list -> tail = NULL;
      return rear;
    // if we have more than one node in the list
    }else{
    list -> tail =  list -> tail -> prev; 
    list -> tail -> next = NULL;
    rear -> prev = NULL;
    list-> tail->next=NULL;

}
    return rear;
}

/**
 * removing a node from a lise
 * @return node
 * 
 */
struct node* removeNode(struct list *list, struct node *node)
{
   if(list == NULL || node==NULL || list->size==0) return NULL;
   
   
  if(node -> prev != NULL){
  
    node -> prev -> next = node -> next;
  }
  if(node -> next != NULL){
  
    node -> next -> prev = node -> prev;
  }
  
  
  if(list -> head == node){
  
    list -> head = list -> head -> next;
  }
  if(list -> tail == node){
  
    list -> tail = list -> tail -> prev;
  }

     node -> next = node -> prev = NULL;
     
     list -> size --;

	return node;
}

struct node* search(const struct list *list, const void *obj)
{
	if(list->size==0 || list==NULL) return NULL;
	
	struct node *temp= list ->head;
	
	  while(temp != NULL){
	     if(list -> equals(temp->obj,obj)){
	       return temp;
	  }
	  temp=temp-> next;
	}
	return NULL;
}


void reverseList(struct list *list)
{
  //if the list empty or null
  if(list == NULL || list->size==0) return;
  
  //if the list hase one node
  if( list->size==1) return;
  
  //if we have more than one node
  struct node *curr = list -> head;
  struct node *temp;
  struct node *newTail;

  while(curr != NULL){
    temp = curr -> next;
    curr -> next = curr -> prev;
    curr -> prev = temp;
    curr = temp;  
  
}
  newTail = list -> tail;
  list -> tail = list -> head;
  list -> head = newTail;
  
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
