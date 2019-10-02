/**************************************************************/
/*                                                            */
/*   Program to demonstrate the implmentation of a            */
/*   linked list of numbers.								  */
/*                                                            */
/**************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define bool int
#define false 0
#define true (!false)

//Libraries
#include <stdio.h>
#include <stdlib.h>


//Preprocessor Variable
#define SIZE 3

//Stucture template for data part of a LinearNode
struct data {
	int num;
};

//Stucture template for one node
struct LinearNode {
	struct data *element;
	struct LinearNode *next;
};


// Function prototypes
void addNodes();  //adding nodes to end of the list
void deleteNode(int); // delete a specific node
void viewAllNodes();
bool isEmpty();



// Global Variables
struct LinearNode *front = NULL;
struct LinearNode *last = NULL;

/**************MAIN FUNCTION*******************/
int main() {

	int delNum;

	addNodes();
	viewAllNodes();

	printf("Please enter the number of the node to delete : ");
	scanf("%d", &delNum);
	deleteNode(delNum);

	viewAllNodes();

	getchar();
	getchar();
}


/**********ADD THREE NODES TO THE LIST******************/
// Each new node is added to the end of the list

void addNodes() {

	int aNumber;
	struct LinearNode *aNode;
	struct data *anElement;

	// add SIZE nodes to the list
	for (int i = 0; i<SIZE; i++) {
		//Create space for data part of node
		anElement = (struct data *)malloc(sizeof(struct data));

		if (anElement == NULL)
			printf("Error - no space for the new element\n");
		else
		{
			//Input value into the data part
			printf("Enter a number for node %d: ", i + 1);
			scanf("%d", &anElement->num);

			// create space for new node that will contain data
			aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));

			if (aNode == NULL)
				printf("Error - no space for the new node\n");
			else { // add data part to the node
				aNode->element = anElement;
				aNode->next = NULL;

				//add node to end of the list
				if (isEmpty())
				{
					front = aNode;
					last = aNode;
				}
				else {
					last->next = aNode;
					last = aNode;
				} //end else
			}//end else
		}//end else 
	}//end for
} //end addNodes


  /**********VIEW ALL THREE NODES IN THE LIST******************/
  // Each new node is added to the end of the list
void viewAllNodes() {
	struct LinearNode *current;

	printf("\n");
	if (isEmpty())
		printf("Error - there are no nodes in the list\n");
	else {
		current = front;
		while (current != NULL) {
			printf("Node value is %d\n", current->element->num);
			current = current->next;
		} //end while
	}//end else
} //end viewAllNodes


void deleteNode(int aNumber) {
	struct LinearNode *current, *previous;
	bool notFound = true;

	printf("\n");
	if (isEmpty())
		printf("Error - there are no nodes in the list\n");
	else {
		current = previous = front;

		while (notFound && current != NULL) {
			if (aNumber == current->element->num)
				notFound = false;
			else {
				previous = current;
				current = current->next;
			}//end else
		} //end while

		if (notFound)
			printf("Error - there is not such node with value %d\n", aNumber);
		else {
			if (current == front) { //delete front node
				front = front->next;
				free(current);
			} //end else
			else if (current == last) {//delete last node
				free(current);
				previous->next = NULL;
				last = previous;
			}
			else {//delete node in middle of list
				previous->next = current->next;
				free(current);
			} //end else
			printf("Node with value %d has been deleted\n", aNumber);
		}//end else
	}//end else
}// end deleteNode


bool isEmpty() {
	if (front == NULL)
		return true;
	else
		return false;
}
