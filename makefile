proj3.x: test_stack1.cpp
	g++ -std=c++11 test_stack1.cpp -o proj3.x

in2post.x: in2post.cpp
	g++ -std=c++11 in2post.cpp -o in2post.x 

clean:
	rm -f *.o *.x