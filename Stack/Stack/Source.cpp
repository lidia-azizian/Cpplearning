#include <iostream>
template<typename T>
class Stack {
public:
	Stack(int size);
	~Stack();
	bool isEmpty()const;
	void push(const int& x);
	void pop();
	T& topElem()const;
private:
	int capacity;
	T* arr;
	int top;
};
template<typename T> Stack<T>::Stack(int size) :capacity(size), arr(new T[size]), top(-1) {}
template<typename T> Stack<T>::~Stack() { delete[] arr; }
template<typename T> bool Stack<T>::isEmpty()const { return top == -1; }
template<typename T> void Stack<T>::push(const int& x)
{
	if (top > capacity) { std::cout << "Overflow\n"; }
	arr[++top] = x;
}
template<typename T> void Stack<T>::pop()
{
	if (isEmpty()) { std::cout << "Underflow\n"; return; }
	top--;
}
template<typename T> T& Stack<T>::topElem()const
{
	if (top < 0) { std::cout << "Stack is empty"; }
	return arr[top];
}
int main() {
	Stack<int> st(5);
	st.isEmpty() == true ? std::cout << "Stack is empty\n" : std::cout << "Stack is not empty\n";
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	std::cout << "After filling stack: ";
	while (!st.isEmpty()) {
		std::cout << st.topElem() << " ";
		st.pop();
	}
	st.push(1);
	st.isEmpty() == true ? std::cout << "\nStack is empty\n" : std::cout << "\nStack is not empty\n";
	std::cout << st.topElem();
	return 0;
}