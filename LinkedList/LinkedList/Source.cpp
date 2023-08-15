#include<iostream>
class Node {
public: int data;
	  Node* next;
	  Node() :data(0), next(nullptr) {}
	  Node(int x) :data(x), next(nullptr) {}
};

//insetion at the beginning
void insert(Node** head, int x) {
	//sarqeci nor node
	Node* node = new Node;
	node->data = x;
	//nor nodey togh cuyc ta current headi vra
	node->next = *head;
	//ev heady arden darna nor nodey
	*head = node;
}

//insertion at the end
void insertattheend(Node** head, int x) {
	Node* newnode = new Node();
	newnode->data = x;
	newnode->next = NULL;

	//if linked list is empty, then our head is newnode
	if (*head == NULL) {
		*head = newnode;
		return;
	}
	//if ll is not empty
	Node* last = *head;
	while (last->next) {
		last = last->next;
	}
	last->next = newnode;
}

//insertion after
void insertAfter(Node* prev, int x) {
	if (!prev) { std::cout << "It can't be null"; return; }
	Node* newnode = new Node();
	newnode->data = x;
	newnode->next = prev->next;
	prev->next = newnode;
}

//deletion at first
Node* deleteatfirst(Node* head) {
	if (!head) { return NULL; }
	Node* temp = head;
	head = head->next;
	delete temp;
	return head;

}

//delete from the end
Node* removeLastNode1(Node* head)
{
	if (head == NULL)
		return NULL;

	if (head->next == NULL) {
		delete head;
		return NULL;
	}

	// Find the second last node
	Node* second_last = head;
	while (second_last->next->next != NULL)
		second_last = second_last->next;

	// Delete last node
	delete (second_last->next);

	// Change next of second last
	second_last->next = NULL;

	return head;
}


//delete from the end 2
Node* removeLastNode2(Node* head) {
	if (head == NULL)
		return NULL;

	if (head->next == NULL) {
		delete head;
		return NULL;
	}
	Node* last = head;
	Node* prelast = NULL;
	while (last->next) {
		prelast = last;
		last = last->next;
	}
	prelast->next = NULL;
	delete last;
	last = NULL;
	return head;
}

//delete from n-th position
Node* deleteNthposition(Node* head, int position) {
	if (head == NULL)
		return NULL;

	if (head->next == NULL) {
		delete head;
		return NULL;
	}
	Node* dummy = new Node(0); dummy->next = head;
	Node* last = head;
	Node* prelast = dummy;
	for (int i = 1; i < position; i++) {
		prelast = last;
		last = last->next;
	}
	prelast->next = last->next;
	Node* newnode = dummy->next;
	delete dummy;
	return newnode;
}

//delete by value
Node* removeelements(Node* head, int elem) {
	if (!head) { return head; }
	Node* dummy = new Node(0);
	dummy->next = head;
	Node* prev = dummy;
	Node* curr = head;
	while (curr) {
		if (curr->data == elem) {
			prev->next = curr->next;
			delete curr;
			curr = prev->next;
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}
	Node* newnode = dummy->next;
	delete dummy;
	return newnode;
}

int getlength(Node* head) {
	int cnt = 0;
	Node* temp = head;
	while (temp) {
		cnt++;
		temp = temp->next;
	}
	return cnt;
}

Node* deleteMiddle(Node* head) {
	int length = getlength(head);
	Node* dummy = new Node(0); dummy->next = head;
	Node* prev = dummy; Node* curr = head;
	for (int i = 0; i < length / 2; i++) {
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	delete curr;
	curr = nullptr;
	Node* newnode = dummy->next;
	delete dummy;
	return newnode;
}
void print(Node* head) {
	while (head) {
		std::cout << head->data << std::endl;
		head = head->next;
	}
}

//reverse
Node* reverse(Node* head) {
	Node* prev = NULL, * next = NULL;
	Node* curr = head;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
	return head;
}
//search iterative
bool searchiterative(Node* head, int x) {
	Node* curr = head;
	while (curr) {
		if (curr->data == x) { return true; }
		curr = curr->next;
	}return false;
}
bool searchrecursive(Node* head, int data) {
	if (!head) { return false; }
	if (head->data == data) { return true; }
	return searchrecursive(head->next, data);
}
void removeduplicates(Node* head) {
	Node* current = head;
	if (current == NULL) { return; }
	Node* nextofnext;
	while (current->next) {
		if (current->data == current->next->data) {
			nextofnext = current->next->next;
			delete current->next;
			current->next = nextofnext;
		}
		else {
			current = current->next;
		}
	}

}
Node* deleteDuplicates(Node* head) {
	Node* current = head;

	while (current != nullptr && current->next != nullptr) {
		if (current->data == current->next->data) {
			Node* duplicate = current->next;
			current->next = duplicate->next;
			delete duplicate; // Free memory of the duplicate node
		}
		else {
			current = current->next;
		}
	}

	return head;
}
int main() {
	Node* head = new Node();
	head->next = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(3);
	head->next->next->next->next = new Node(4);
	head->next->next->next->next->next = new Node(3);
	head->next->next->next->next->next->next = new Node(4);
	head->next->next->next->next->next->next->next = new Node(8);
	head->next->next->next->next->next->next->next = new Node(10);
	head->next->next->next->next->next->next->next = new Node(9);


	std::cout << "Initial list: \n";
	print(head);
	std::cout << "After inserting a node at the beginning: \n";
	insert(&head, 4);
	print(head);
	std::cout << "\nAfter inserting a node at the end: \n";
	insertattheend(&head, 4);
	print(head);
	std::cout << "\nAfter inserting a node after a given node: \n";
	insertAfter(head, 5);
	print(head);

	std::cout << std::endl;
	std::cout << "After deleting a node from the beginning: \n";
	head = deleteatfirst(head);
	print(head);
	std::cout << "\nAfter deleting a node from the end in two ways : \n";
	head = removeLastNode1(head);
	head = removeLastNode2(head);
	print(head);
	std::cout << "\nAfter deleting a node from the N-th position: \n";
	head = deleteNthposition(head, 2);
	print(head);
	std::cout << "After deleting a node by value: \n";
	head = removeelements(head, 4);
	print(head);
	std::cout << "After deleting middle node: \n";
	head = deleteMiddle(head);
	print(head);
	std::cout << "Reversed linked list: \n";
	head = reverse(head);
	print(head);
	std::cout << "After deleting duplicates: \n";
	removeduplicates(head);
	print(head);

	std::cout << "\nAfter deleting duplicates second way: \n";
	insert(&head, 3);
	head = deleteDuplicates(head);
	print(head);
	std::cout << "Searching element: \n";
	searchiterative(head, 3) ? std::cout << "Yes, element found in the linked list." : std::cout << "No, element not found\n";

	searchrecursive(head, 5) ? std::cout << "\nYes element found in the linked list." : std::cout << "\nNo, element not found";

}