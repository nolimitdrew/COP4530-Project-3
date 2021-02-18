
/* Name: Andrew Stade
Date: 10/22/2020
Section: COP 4530 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

namespace cop4530
{
	template <typename T>
	class Stack
	{
		public:
			Stack();	// constructor
			~Stack();	// destructor
			Stack(const Stack<T> &);	// copy constructor
			Stack(Stack<T> &&);			// move constructor
			Stack<T> & operator=(const Stack<T> &);	// copy assignment operator=
			Stack<T> & operator=(Stack<T> &&);		// move assignment operator=
			bool empty() const;
			void clear();
			void push(const T& x);	// copy version
			void push(T && x);		// move version
			void pop();
			T& top();
			const T& top() const;
			int size() const;
			void print(std::ostream& os, char ofc = ' ') const;
			std::vector<T> returnVector() const;
			
		private:
			std::vector<T> v;
			
	};
	template <typename T>
	std::ostream & operator << (std::ostream & os, const Stack<T> & a);
	
	template <typename T>
	bool operator == (const Stack<T> & a, const Stack<T> & b);
	
	template <typename T>
	bool operator != (const Stack<T> & a, const Stack<T> & b);
	
	template <typename T>
	bool operator <= (const Stack<T> & a, const Stack<T> & b);
	
	
#include "stack.hpp"
}

#endif