#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>


using namespace std;

int main() {
	//List stack
	stack <int, list<int>> listStack;

	//deque stack (regular ass stack)
	stack <int> dequeStack;

	//Vector Stack
	stack <int, vector<int>> vectorStack;

	vectorStack.empty(); //is stack empty?
	vectorStack.pop(); //pops top of stack
	vectorStack.push(8); //inserts a num to top of stack
	vectorStack.size(); //returns size of stack
	vectorStack.top(); //returns top of stack

	// A STACK IS LIFO (LAST IN FIRST OUT)

	//A que is FIFO (FIRST IN FIRST OUT)
	//Primary operations are enqueue (push) and dequeue (pop)
	queue <int> myQue;


	myQue.push(12); //inserts num into front of list
	myQue.pop(); //pops front of list
	myQue.front(); //shows number at the front



	return 0;
}