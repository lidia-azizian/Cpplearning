#include <iostream>
#include<algorithm>
template<typename T>
class Vector {
public:

	//Constructor
	Vector() :m_capacity(0), m_size(0), ptr(new T[m_capacity]) {}
	//Destructor
	~Vector() { delete[]ptr; }


	// Copy constructor
	Vector(const Vector& other) : ptr(nullptr), m_capacity(0), m_size(0) {
		*this = other; // using the copy assignment operator
	}

	// Copy assignment operator
	Vector& operator=(const Vector& other) {
		if (this != &other) {
			delete[] ptr;

			m_capacity = other.m_capacity;
			m_size = other.m_size;
			ptr = new T[m_capacity];

			std::copy(other.ptr, other.ptr + m_size, ptr);
		}
		return *this;
	}

	// Move constructor
	Vector(Vector&& other) noexcept : ptr(nullptr), m_capacity(0), m_size(0) {
		*this = std::move(other); // using the move assignment operator
	}


	// Move assignment operator
	Vector& operator=(Vector&& other) noexcept {
		if (this != &other) {
			delete[] ptr;

			ptr = other.ptr;
			m_capacity = other.m_capacity;
			m_size = other.m_size;

			other.ptr = nullptr;
			other.m_capacity = 0;
			other.m_size = 0;
		}
		return *this;
	}

	void push_back(int elem)
	{
		if (m_size == m_capacity)
		{
			m_capacity = m_capacity ? m_capacity * 2 : 1;//if m_capacity is 0, then assign 1
			int* tmp = new int[m_capacity];
			for (int i = 0; i < m_capacity; i++)
			{
				tmp[i] = ptr[i];
			}
			delete[] ptr;
			ptr = tmp;
		}

		ptr[m_size++] = elem;
	}

	int size() { return m_size; }
	int capacity() { return m_capacity; }
	void pop_back() { m_size--; }

	void insert(int elem, int index)
	{
		if (index == m_capacity)
		{
			push_back(elem);
		}
		ptr[index] = elem;
	}

	int& operator[](int index)
	{
		return ptr[index];
	}


	Vector operator+(const Vector& oth)
	{
		Vector result;
		result.m_capacity = this->m_capacity + oth.m_capacity;
		result.m_size = this->m_size + oth.m_size;
		result.ptr = new int[result.m_capacity];

		for (int i = 0; i < this->m_size; i++) {
			result.ptr[i] = this->ptr[i];
		}

		for (int i = 0; i < oth.m_size; i++) {
			result.ptr[this->m_size + i] = oth.ptr[i];
		}

		return result;
	}



private:
	T* ptr;
	int m_capacity;
	int m_size;
};
int main() {
	Vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	std::cout << "Vector size: " << v1.size() << std::endl;
	std::cout << "Vector capacity : " << v1.capacity() << std::endl;
	Vector<int> v2;
	v2.push_back(3);

	Vector<int> v3;
	v3 = v1 + v2;
	std::cout << "v3 elements: ";
	for (int i = 0; i < v3.size(); i++) {
		std::cout << " " << v3[i] << " ";
	}
	v3.pop_back();
	std::cout << "\nv3 elements after pop: ";
	for (int i = 0; i < v3.size(); i++) {
		std::cout << " " << v3[i] << " ";
	}
}