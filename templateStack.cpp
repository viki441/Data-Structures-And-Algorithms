#include <iostream> 
#include <stdexcept>

using namespace std;
template<typename T>
class Stack
{
private:
	static constexpr size_t DEF_CAP = 10;
	size_t size;
	size_t capacity;
	T* arr;


private:
	void resize()
	{
		size_t newC = capacity * 2;
		T* newArr = new T[newC];

		for (size_t i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		capacity = newC;

	}


public:

	Stack()
		:size(0), capacity(DEF_CAP)
	{
		arr = new T[capacity];
	}


	Stack(size_t cap)
		:size(0), capacity(cap)
	{
		if (cap <= 0) capacity = DEF_CAP;
		arr = new T[capacity];
	}

	Stack(const Stack& other)
		:size(other.size), capacity(other.capacity)
	{
		T* newArr = new T[capacity];
		for (size_t i = 0; i < size; i++)
		{
			newArr[i] = other.arr[i];
		}
		arr = newArr;
	}


	Stack& operator=(const Stack& other)
	{
		if (this != &other)
		{
			T* newArr = new T[other.capacity];

			for (size_t i = 0; i < other.size; i++)
			{
				newArr[i] = other.arr[i];

			}

			delete[] arr;
			arr = newArr;

			capacity = other.capacity;
			size = other.size;
		}
		return *this;
	}


	Stack(Stack&& other) noexcept
		:size(other.size), capacity(other.capacity), arr(other.arr)
	{
		other.capacity = 0;
		other.size = 0;
		other.arr = nullptr;
	}


	Stack& operator=(Stack&& other) noexcept
	{
		if (this != &other)
		{
			delete[] arr;
			arr = other.arr;
			capacity = other.capacity;
			size = other.size;

			other.capacity = 0;
			other.size = 0;
			other.arr = nullptr;
		}
		return *this;
	}


	~Stack()
	{
		delete[] arr;
	}


	void push(const T& el)
	{
		if (size == capacity)
			resize();

		arr[size] = el;
		size++;
	}


	T pop()
	{
		if (size == 0)
			throw underflow_error("stack is empty\n");

		return arr[--size];
	}


	const T& top()
	{
		if (size == 0)
			throw underflow_error("stack is empty\n");

		return arr[size - 1];
	}


	bool isEmpty()
	{
		return size == 0;
	}
};


bool isMatchingPair(char open, char close)
{
	return (open == '[' && close == ']') ||
		(open == '{' && close == '}') ||
		(open == '(' && close == ')') ||
		(open == '<' && close == '>');
}


bool isSequenceValid(const char* seq)
{
	Stack<char> openingBrackets;
	while (*seq != '\0')
	{
		char el = *seq++;

		if (el == '[' || el == '{' || el == '(' || el == '<')
		{
			openingBrackets.push(el);
		}
		else
		{
			if (openingBrackets.isEmpty())
				return false;

			if (!isMatchingPair(openingBrackets.top(), el))
				return false;

			openingBrackets.pop();
		}
	}

	return openingBrackets.isEmpty();
}
int main()
{
	const char* sequence = "(((((((((())))))))))";

	cout << isSequenceValid(sequence);
}
