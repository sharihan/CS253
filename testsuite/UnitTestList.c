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
/*////////////////////////////////////////////////
 * TODO: Write your test functions here        //
 *///////////////////////////////////////////////

/**
 * checking empty list
 */
// int emptyList(){
// 
//     struct node *node = createTestNode(1);
//     addAtRear(testlist,node);
//     
//     struct node *node2 = createTestNode(1);
//     addAtRear(testlist,node2);
//    
//     freeNode(removeNode(testlist,node), testlist -> freeObject);
//     freeNode(removeNode(testlist,node2), testlist -> freeObject);
//     
//     myassert(testlist) == 0)
//     return 0;    
//     
// }

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

int removeFromListWithOneNode()
{
        struct node *node = createTestNode(1);
	addAtFront(testlist, node);
	
	freeNode(removeFront(testlist),(testlist -> freeObject));
	
	myassert(testlist->size == 0)
	myassert(testlist->head == NULL)
	myassert(testlist->tail == NULL)	
	return 1;
}



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

	testName = "addAtRearWithOneNode";
	beforeTest(testName);
	result = addAtRearWithOneNode();
	afterTest(testName, result);

	testName = "removeFromListWithOneNode";
	beforeTest(testName);
	result = removeFromListWithOneNode();
	afterTest(testName, result);

	testName = "nullNodeTest";
	beforeTest(testName);
	result = nullNodeTest();
	afterTest(testName, result);

	
// 	testName = "emptyList";
// 	beforeTest(testName);
// 	result = emptyList();
// 	afterTest(testName, result);

	testName = "addAtFrontWithOneNode";
	beforeTest(testName);
	result = addAtFrontWithOneNode();
	afterTest(testName, result);
	
	testName = "addAtRearWithNoNodes";
	beforeTest(testName);
	result = addAtRearWithNoNodes();
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
