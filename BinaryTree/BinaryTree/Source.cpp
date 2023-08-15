#include<iostream>
#include<queue>
#include<stack>

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int x) :data(x), left(nullptr), right(nullptr) {}
};

Node* newNode(int data)
{
	Node* node = new Node(data);
	node->left = node->right = NULL;
	return node;
}
int height(Node* root)
{
	if (!root) { return 0; }
	int leftside = height(root->left);
	int rightside = height(root->right);
	return std::max(leftside, rightside) + 1;
}
unsigned int countOfnodes(Node* root) {
	if (!root) { return 0; }
	return 1 + countOfnodes(root->left) + countOfnodes(root->right);
}
void printCurrentLevel(Node* root, int level) {
	if (!root) { return; }
	if (level == 1) { std::cout << root->data << " "; }
	else if (level > 1) {
		printCurrentLevel(root->left, level + 1);
		printCurrentLevel(root->right, level + 1);
	}
}
bool find(Node* root, int elem)
{
	if (!root)
	{
		return false;
	}
	if (root->data == elem)
	{
		return true;
	}
	return find(root->left, elem) || find(root->right, elem);
}
namespace leaves {
	int countOfleaves(Node* root) {
		if (!root) {
			return 0;
		}
		if (!root->left && !root->right) {
			return 1;
		}
		return countOfleaves(root->left) + countOfleaves(root->right);
	}
	void printLeaves(Node* root) {
		if (!root) { return; }
		if (!root->left && !root->right) {
			std::cout << root->data;
			return;
		}
		if (root->left) {
			printLeaves(root->left);
		}
		if (root->right) {
			printLeaves(root->right);
		}
	}
	void printNonLeaves(Node* root) {
		if (!root) { return; }
		if (!root->left && !root->right) { return; }
		if (root->left || root->right)
		{
			std::cout << root->data << " ";
		}
		printNonLeaves(root->left);
		printNonLeaves(root->right);
	}
}
namespace traversal
{
	void Inorder(Node* root)//inorder
	{
		if (!root)
		{
			return;
		}
		Inorder(root->left);
		std::cout << root->data << ' ';
		Inorder(root->right);
	}

	void Preorder(Node* root)
	{
		if (!root)
		{
			return;
		}
		std::cout << root->data << ' ';
		Preorder(root->left);
		Preorder(root->right);
	}

	void Postorder(Node* root)
	{
		if (!root)
		{
			return;
		}
		Postorder(root->left);
		Postorder(root->right);
		std::cout << root->data << ' ';
	}
	void PreorderIterative(Node* root)
	{
		if (!root)
		{
			return;
		}
		std::stack<Node*> st;
		st.push(root);
		while (!st.empty())
		{
			Node* temp = st.top();
			st.pop();

			std::cout << temp->data << ' ';

			if (temp->right)
			{
				st.push(temp->right);
			}
			if (temp->left)
			{
				st.push(temp->left);
			}
		}
	}
	void InorderIterative(Node* root)
	{
		std::stack<Node*> st;
		Node* temp = root;
		while (temp || !st.empty())
		{
			while (temp)
			{
				st.push(temp);
				temp = temp->left;
			}
			temp = st.top();
			st.pop();
			std::cout << temp->data << ' ';
			temp = temp->right;
		}
	}
	void levelOrder(Node* root) {
		int h = height(root);
		for (int i = 0; i < h; i++) {
			printCurrentLevel(root, i);
		}
	}

}
namespace type {
	bool isFull(Node* root)
	{
		if (!root) { return true; }
		if (!root->left && !root->right) { return true; }
		if (root->left && root->right)
		{
			return isFull(root->left) && isFull(root->right);
		}
		return false;
	}
	bool isPerfect(Node* root)
	{
		int count = countOfnodes(root);
		return (count & (count + 1)) == 0;
		//if the number of nodes  is a power of 2 the tree is perfect
	}
	bool isComplete(Node* root)
	{
		std::queue<Node*> q;
		q.push(root);
		bool flag = false;//will be true in case of non null node
		while (!q.empty()) {
			Node* temp = q.front();
			q.pop();
			if (temp->left) {
				// If we have a non full node, and we see a left child
				if (flag == true)
					return false;
				q.push(temp->left);
			}
			else
				flag = true;
			if (temp->right) {
				// If we have a non full node, and we see a right child
				if (flag == true)
					return false;
				q.push(temp->right);
			}
			else
				flag = true;
		}
		return true;
	}
}
int main() {
	/*
			 1
		   /  \
		   2   3
		  / \   \
		 4   5   6
	   */
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);
	std::cout << "Count of nodes: " << countOfnodes(root);
	std::cout << "\nHeight of binary tree: " << height(root) << std::endl;
	int elem = 2;
	if (find(root, elem)) { std::cout << elem << " is found"; }
	else { std::cout << elem << " is not found"; }
	std::cout << "\nCount of leaves: " << leaves::countOfleaves(root);
	std::cout << "\nLeaf nodes: "; leaves::printLeaves(root);
	std::cout << "\nNon leaf nodes: "; leaves::printNonLeaves(root);

	std::cout << "\nInorder traversal of binary tree is \n";
	traversal::Inorder(root);
	std::cout << "\nInorder traversal of binary tree(iterative) \n";
	traversal::InorderIterative(root);
	std::cout << "\nPreorder traversal of binary tree is \n";
	traversal::Preorder(root);
	std::cout << "\nPreorder traversal of binary tree(iterative) \n";
	traversal::PreorderIterative(root);
	std::cout << "\nPostorder traversal of binary tree is \n";
	traversal::Postorder(root);

	if (type::isComplete(root) == true)
		std::cout << "\nComplete Binary Tree\n";
	else
		std::cout << "\nNot Complete Binary Tree\n";
	if (type::isFull(root) == true)
		std::cout << "\nFull Binary Tree\n";
	else
		std::cout << "\nNot Full Binary Tree\n";
	if (type::isPerfect(root) == true)
		std::cout << "\nPerfect Binary Tree\n";
	else
		std::cout << "\nNot Perfect Binary Tree\n";
}