/*
 * UnitTestList.c
 *
 *      Author: marissa
 */

#include <stdio.h>
#include <stdlib.h>

#include "Object.h"
#include "Node.h"
#include "List.h"

/*
 * macro to mimic the functionality of assert() from <assert.h>. The difference is that this version doesn't exit the program entirely.
 * It will just break out of the current function (or test case in this context).
 */
#define myassert(expr) if(!(expr)){ fprintf(stderr, "\t[assertion failed] %s: %s\n", __PRETTY_FUNCTION__, __STRING(expr)); return 0; }

struct list *testlist;

int testCount = 0;
int passCount = 0;

void printTestInfo(char* testName, char *info)
{
	fprintf(stdout, "%s - %s\n", testName, info);
}

void printTestResult(char* testName, int passed)
{
	if(passed){
		fprintf(stdout, "%s - %s\n\n", "[PASSED]", testName);
	}else{
		fprintf(stdout, "%s - %s\n\n", "[FAILED]", testName);
	}
}

struct node *createTestNode(int jobid)
{
	struct object * job = createObject(jobid, "cmd args");
	struct node *node = createNode(job);
	return node;
}

int addAtFrontWithNoNodes()
{
	struct node *node = createTestNode(1);
	addAtFront(testlist, node);
	myassert(testlist->size == 1)
	myassert(testlist->head == node)
	myassert(testlist->tail == node)
	myassert(testlist->head->next == NULL)
	myassert(testlist->head->prev == NULL)
	return 1;
}


void beforeTest(char* testName)
{
	printTestInfo(testName, "Running...");
	testlist = createList(equals, toString, freeObject);
	testCount++;
}
void afterTest(char* testName, int result)
{
	printTestResult(testName, result);
	freeList(testlist);
	passCount += result;
}

/*///////////////////////////////////////////////
 * TODO: Write your test functions here        //
 *///////////////////////////////////////////////

/**
 *checking the size of the list
 */ 
int getSizeOfListWithNoNodes()
{

	struct node *node = NULL;
	addAtFront(testlist,node);
	struct node *node2 = NULL;
	
	addAtFront(testlist,node2);
	myassert(getSize(testlist) == 0)
	
	return 1;    
}


/**
 * check the size of list with 4 nodes
 */ 
int getSizeOfListWithFourNodes()
{

	struct node *node = createTestNode(1);
	addAtFront(testlist,node);
	
	struct node *node2 = createTestNode(1);
	addAtFront(testlist,node2);
	
	struct node *node3 = createTestNode(1);
	addAtFront(testlist,node3);
	
	struct node *node4 = createTestNode(1);
	addAtFront(testlist,node4);
      

	myassert(getSize(testlist) == 4)
	
	return 1; 
}

/**
 * checking empty list
 */
int emptyListTest()
{

	struct node *node = createTestNode(1);
	addAtRear(testlist,node);
	
	struct node *node2 = createTestNode(1);
	addAtRear(testlist,node2);
      
	freeNode(removeNode(testlist,node), testlist -> freeObject);
	freeNode(removeNode(testlist,node2), testlist -> freeObject);
	
	myassert(testlist->size == 0)
	
	return 1;    
    
}

/**
 * Add to front in list with one node
 */
int addAtFrontWithOneNode()
{
	struct node *node = createTestNode(1);
	addAtFront(testlist,node);
	struct node *node2 = createTestNode(1);
	addAtFront(testlist,node2);
	myassert(testlist->size == 2)
	myassert(testlist->head == node2)
	myassert(testlist->tail == node)
	myassert(testlist->head->prev == NULL)
	myassert(testlist->tail->next == NULL)

	return 1;
}

/**
 * Add to rear with no nodes
 */
int addAtRearWithNoNodes()
{

	struct node *node = createTestNode(1);
	addAtRear(testlist, node);
	
	myassert(testlist->size == 1)
	myassert(testlist->head == node)
	myassert(testlist->tail == node)
	myassert(testlist->head->next == NULL)
	myassert(testlist->head->prev == NULL)
	
	return 1;
}

/**
 * add to rear one node
 */
int addAtRearWithOneNode()
{
        struct node *node = createTestNode(1);
	addAtRear(testlist,node);
	struct node *node2 = createTestNode(1);
	addAtRear(testlist,node2);
	
	myassert(testlist->size == 2)
	myassert(testlist->head == node)
	myassert(testlist->tail == node2)
	myassert(testlist->head->prev == NULL)
	myassert(testlist->tail->next == NULL)
 	return 1;
 }

 
/**
 * remove from a list one node
 */
int removeFrontFromListWithOneNode()
{
        struct node *node = createTestNode(1);
	addAtFront(testlist, node);
	
	freeNode(removeFront(testlist),(testlist -> freeObject));
	
	myassert(testlist->size == 0)
	myassert(testlist->head == NULL)
	myassert(testlist->tail == NULL)	
	return 1;
}

 
/**
 * remove from rear a list 23 node
 */
int removeRearFromListWithTwoNode()
{
        struct node *node = createTestNode(1);
	addAtFront(testlist, node);
	
	struct node *node2 = createTestNode(1);
	addAtFront(testlist, node2);
	
	
	freeNode(removeRear(testlist), testlist -> freeObject);
  
        myassert(testlist -> size == 1)
        myassert(testlist -> head == node2)
        myassert(testlist -> tail == node2)
        myassert(testlist -> head -> next == NULL)
        myassert(testlist -> tail -> prev == NULL)
	
	return 1;
}



/**
 * remove a node one node list
 */
int removeNodeFromListWithOneNode()
{
  
	struct node *node = createTestNode(1);
	addAtFront(testlist,node);
	
	freeNode(removeNode(testlist,node), testlist -> freeObject);
	
	myassert(testlist -> size == 0)
	myassert(testlist -> head == NULL)
	myassert(testlist -> tail == NULL)

	
	return 1;
}

/**
 * remove a node two nodes list
 */
int removeNodeFromListWithTwoNodes()
{

	struct node *node = createTestNode(1);
	addAtFront(testlist,node);
	struct node *node2 = createTestNode(1);
	addAtFront(testlist,node2);
	
	freeNode(removeNode(testlist,node2), testlist -> freeObject);
	
	myassert(testlist -> size == 1)
	myassert(testlist -> head == node)
	myassert(testlist -> tail == node)
	myassert(testlist -> head -> prev == NULL)
	myassert(testlist -> tail -> next == NULL)
	
	return 1;
}

/**
 * null node test
 */
int nullNodeTest()
{
	struct node *node = NULL;
	addAtFront(testlist,node);
	struct node *node2 = NULL;
	addAtFront(testlist,node2);
	      
	freeNode(removeNode(testlist,node), testlist -> freeObject);
	freeNode(removeNode(testlist,node2), testlist -> freeObject);

	myassert(testlist -> size == 0)
	myassert(testlist -> head == NULL)
	myassert(testlist -> tail == NULL)
	return 1;
  
}


/**
 *  not empty list test
 */
int notEmptyListTest()
{

	struct node *node = createTestNode(1);
	addAtFront(testlist,node);
	struct node *node2 = createTestNode(1);
	addAtFront(testlist,node2);

	freeNode(removeNode(testlist,node), testlist -> freeObject);
	  
	myassert(testlist -> size == 1)
	myassert(testlist -> head == node2)
	myassert(testlist -> tail == node2) 

	return 1;
}

/**
 * search the list
 */
int searchListTest()
{

	struct node *node = createTestNode(1);
	addAtFront(testlist,node);
	  
	struct node *node2 = createTestNode(2);
	addAtFront(testlist,node2);
	  
	struct node *node3 = createTestNode(3);
	addAtFront(testlist,node3);
	  
	myassert(search(testlist , node -> obj))
	myassert(search(testlist , node2-> obj))
	myassert(search(testlist , node3 -> obj))
	  
	return 1;
 }
 
/**
 * reverse list with two nodes
 */
int reverseListWithTwoNodes()
{

	struct node *node = createTestNode(1);
	addAtFront(testlist,node);
	struct node *node2 = createTestNode(1);
	addAtFront(testlist,node2);
	
	reverseList(testlist);
	
	myassert(testlist -> size == 2)
	myassert(testlist -> head == node)
	myassert(testlist -> tail == node2)

	myassert(testlist -> head -> prev == NULL)
	myassert(testlist -> tail -> next == NULL)
	
	return 1;
}

/**
 * reverse list with three nodes
 */

int reverseListWithThreeNodes(){

	struct node *node = createTestNode(1);
	addAtFront(testlist,node);
	struct node *node2 = createTestNode(1);
	addAtFront(testlist,node2);
	struct node *node3 = createTestNode(1);
	addAtFront(testlist,node3);
	
	reverseList(testlist);
	
	myassert(testlist -> size == 3)
	myassert(testlist -> head == node)
	myassert(testlist -> tail == node3)
	myassert(testlist -> head -> next == node2)
	myassert(testlist -> tail -> prev == node2)
	
	myassert(testlist -> head -> prev == NULL)
	myassert(testlist -> tail -> next == NULL)
	
	return 1;
}


void runUnitTests()
{
	int result;
	char *testName;

	testName = "addAtFrontWithNoNodes";
	beforeTest(testName);
	result = addAtFrontWithNoNodes();
	afterTest(testName, result);

   

//////////////////////////////////
//TODO: Add in your tests here  //
//////////////////////////////////

	
	testName = "getSizeTest";
	beforeTest(testName);
	result = getSizeOfListWithNoNodes();
	afterTest(testName, result);
	
	testName = "getSizeTestFourNodes";
	beforeTest(testName);
	result = getSizeOfListWithFourNodes();
	afterTest(testName, result);
	
	testName = "nullNodeTest";
	beforeTest(testName);
	result = nullNodeTest();
	afterTest(testName, result);
	
        testName = "emptyListTest";
	beforeTest(testName);
	result = emptyListTest();
	afterTest(testName, result);
	
	
	testName = "notEmptyListTest";
	beforeTest(testName);
	result=  notEmptyListTest();
	afterTest(testName, result);
	
	
	testName = "addAtFrontWithOneNode";
	beforeTest(testName);
	result = addAtFrontWithOneNode();
	afterTest(testName, result);
	
	testName = "addAtRearWithOneNode";
	beforeTest(testName);
	result = addAtRearWithOneNode();
	afterTest(testName, result);
	
	
	testName = "addAtRearWithNoNodes";
	beforeTest(testName);
	result = addAtRearWithNoNodes();
	afterTest(testName, result);
	

	testName = "removeFrontFromListWithOneNode";
	beforeTest(testName);
	result = removeFrontFromListWithOneNode();
	afterTest(testName, result);

	
	testName = "removeRearFromListWithTwoNode";
	beforeTest(testName);
	result = removeRearFromListWithTwoNode();
	afterTest(testName, result);
	
	testName = "removeNodeFromListWithTwoNodes()";
	beforeTest(testName);
	result = removeNodeFromListWithTwoNodes();
	afterTest(testName, result);
	
	testName = "removeNodeFromListWithOneNode()";
	beforeTest(testName);
	result = removeNodeFromListWithOneNode();
	afterTest(testName, result);
	
	
	testName ="searchListTest";
	beforeTest(testName);
	result=searchListTest();
	afterTest(testName, result);

	testName = "reverseListWithTwoNodes";
	beforeTest(testName);
	result=  reverseListWithTwoNodes();
	afterTest(testName, result);
	
	testName = "reverseListWithThreeNodes";
	beforeTest(testName);
	result=  reverseListWithThreeNodes();
	afterTest(testName, result);
	
	
/////////////////////end of tests//////////////////////
	
	fprintf(stdout, "Test Cases: %d\n",  testCount);
	fprintf(stdout, "Passed: %d\n", passCount);
	fprintf(stdout, "Failed: %d\n", testCount - passCount);
}

int main(int argc, char *argv[])
{
	runUnitTests();
	exit(0);
}
