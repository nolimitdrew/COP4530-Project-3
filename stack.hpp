
/* Name: Andrew Stade
Date: 10/22/2020
Section: COP 4530 */

template <typename T>
Stack<T>::Stack()		// zero-argument constructor
{
}

template <typename T>
Stack<T>::~Stack()		// destructor
{
	v.clear();
}

template <typename T>
Stack<T>::Stack(const Stack<T> & x)		// copy constructor
{
	*this = x;
}

template <typename T>
Stack<T>::Stack(Stack<T> && x)		// move constructor
{
	*this = x;
}

template <typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> & b)		// copy assignment operator=
{
	v = b.v;
	return *this;
}

template <typename T>
Stack<T> & Stack<T>::operator=(Stack<T> && b)		// move assignment operator=
{
	v = b.v;
	return *this;
}

template <typename T>
bool Stack<T>::empty() const
{
	return v.empty();
}

template <typename T>
void Stack<T>::clear()			
{
	v.clear();
}

template <typename T>
void Stack<T>::push(const T& x)		// copy version
{
	v.push_back(x);
}

template <typename T>
void Stack<T>::push(T&& x)			// move version
{
	v.push_back(x);
}

template <typename T>
void Stack<T>::pop()
{
	v.pop_back();
}

template <typename T>
T& Stack<T>::top()
{
	return v.back();
}

template <typename T>
const T& Stack<T>::top() const
{
	return v.back();
}

template <typename T>
int Stack<T>::size() const
{
	return v.size();
}

template <typename T>
void Stack<T>::print(std::ostream & os, char ofc) const
{
	for(auto itr = v.begin(); itr != v.end(); itr++)	// lecture slides
	{
		os << *itr << ofc;
	}
}

template <typename T>
std::ostream & operator << (std::ostream & os, const Stack<T> & a)
{
	a.print(os);
	return os;
}

template <typename T>
bool operator == (const Stack<T> & a, const Stack<T> & b)
{
	return a.returnVector() == b.returnVector();
}

template <typename T>
bool operator != (const Stack<T> & a, const Stack<T> & b)
{
	return !(a == b);
}

template <typename T>
bool operator <= (const Stack<T> & a, const Stack<T> & b)
{
	return a.returnVector() <= b.returnVector();
}

template <typename T>
std::vector<T> Stack<T>::returnVector() const
{
	return v;
}