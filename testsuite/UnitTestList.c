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

int addAtFrontWithOneNode()
{
	printTestInfo("addAtFrontWithOneNode", "(not implemented)");
	return 0;
}

int addAtRearWithNoNodes()
{
	printTestInfo("addAtRearWithNoNodes", "(not implemented)");
	return 0;
}

int addAtRearWithOneNode()
{
	printTestInfo("addAtRearWithOneNode", "(not implemented)");
	return 0;
}

int removeFromListWithOneNode()
{
	printTestInfo("removeFromListWithOneNode", "(not implemented)");
	return 0;
}

int nullNodeTest()
{
	printTestInfo("nullNodeTest", "(not implemented)");
	return 0;
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
Boolean emptyList(){

    struct node = createTestNode(1);
    addAtRear(testlist,node);
    
    struct node2 = createTestNode(1);
    addAtRear(testlist,node2);
   
    freeNode(removeNode(testlist,node), testlist -> freeObject);
    freeNode(removeNode(testlist,node2), testlist -> freeObject);
    
    myassert(isEmpty(testlist) == TRUE)
    
    return TRUE;    
    
}

/**
 * Add to front in list with one node
 */
int addAtFrontWithOneNode()
{
	struct node *node = createTestNode(1);
	addAtFront(testlist,node);

	struct node2 = createTestNode(1);
	addAtFront(testlist,node2);

	myassert(testlist->size == 2)
	myassert(testlist->head == node2)
	myassert(testlist->tail == node)
	myassert(testlist->head->prev == NULL)
	myassert(testlist->tail->next == NULL)

	return 2;
}


void runUnitTests()
{
	int result;
	char *testName;

	testName = "addAtFrontWithNoNodes";
	beforeTest(testName);
	result = addAtFrontWithNoNodes();
	afterTest(testName, result);

	testName = "addAtFrontWithOneNode";
	beforeTest(testName);
	result = addAtFrontWithOneNode();
	afterTest(testName, result);

	testName = "addAtRearWithNoNodes";
	beforeTest(testName);
	result = addAtRearWithNoNodes();
	afterTest(testName, result);

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

	//////////////////////////////////
	//TODO: Add in your tests here  //
	//////////////////////////////////
	testName = "addAtFrontWithNOneNode";
	beforeTest(testName);
	result = addAtFrontWithOneNode();
	afterTest(testName, result);
	
	testName = "emptyList";
	beforeTest(testName);
	result = emptyList();
	afterTest(testName, result);

	
	
	fprintf(stdout, "Test Cases: %d\n",  testCount);
	fprintf(stdout, "Passed: %d\n", passCount);
	fprintf(stdout, "Failed: %d\n", testCount - passCount);
}

int main(int argc, char *argv[])
{
	runUnitTests();
	exit(0);
}
