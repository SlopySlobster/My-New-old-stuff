//train simulator- shows basics of linked lists in C++
#include <iostream>
using namespace std;

enum CarType { engine, tanker, box, passenger, caboose };

class Node {
public:
	int carNumber;
	int carType;
	bool isFull;
	Node* next;
};


//this function inserts a new node in FRONT of the list---------------------------------------------------
void addFront(Node** head, int num, int type, bool Full) {
	//make a new car
	Node* newNode = new Node;

	//give it its data
	newNode->carNumber = num;
	newNode->carType = type;
	newNode->isFull = Full;

	//set next of new node as head
	newNode->next = (*head);

	//move the head to point to the new node 
	(*head) = newNode;
}

//this function adds a new node AFTER a given node------------------------------------------------------
void addAfter(Node* prev_node, int num, int type, bool Full) {
	//check if previous node is NULL, give error message if it is
	if (prev_node == NULL)
		cout << "ERROR";

	else {
		//make a new car
		Node* newNode = new Node;

		//give it its data
		newNode->carNumber = num;
		newNode->carType = type;
		newNode->isFull = Full;

		//set next to the "next" of the previous node
		newNode->next = prev_node->next;

		//move the next of the previous node as the new node
		prev_node->next = newNode;
	}

}

//this function prints out the whole list----------------------------------------------------------------
void displayList(Node* node) {

	cout << "Printing Train! Choo Choo!" << endl << endl;
	//traverse the list to display each node
	while (node != NULL) {
		cout << "[ ";
		if (node->carType == 0) {
			cout << "engine";
			if (node->isFull == 1)
				cout << " is full";
		}
		else if (node->carType == 1) {
			cout << "tanker";
			if (node->isFull == 1)
				cout << " is full";

		}
		else if (node->carType == 2) {
			cout << "boxcar";
			if (node->isFull == 1)
				cout << " is full";

		}
		else if (node->carType == 3){
			cout << "passenger";
			if (node->isFull == 1)
				cout << " is full";

		}
		else {
			cout << "caboose!";
			if (node->isFull == 1)
				cout << " is full";

		}

		cout << " # ";
		cout << node->carNumber << " ] --> ";
		node = node->next;
	}

	if (node == NULL)
		cout << "end" << endl << endl; //end of train
}


int main() {
	Node* head = NULL;
	Node* prev_node = NULL;

	addFront(&head, 100, box, 0);
	addFront(&head, 2394, engine, 1);
	addFront(&head, 243, passenger, 1);
	addFront(&head, 1294, tanker, 0);
	addFront(&head, 362, box, 1);

	addAfter(prev_node, 235, passenger, 1);

	displayList(head);
}


// 
