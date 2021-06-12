#include <iostream>
#include <array>

using namespace std;

void initializer(array<int, 4>);
void displayArray(array<int, 4>);

int main() {
	//Make an array (object)
	array<int, 4> numArr = { 1, 2 ,3, 4 };


	displayArray(numArr);

	return 0;
}

void changeValue(array<int, 4> myArr){
	array<int, 4>::iterator it;
	it = myArr.begin();

	for (auto it = myArr.begin(); it != myArr.end(); it++) {
		if (it == 0) {
			*it = 99;
		}

		cout << *it << endl;
	}
}

void displayArray(array<int, 4> myArr){
	array<int, 4>::iterator it;
	it = myArr.begin();

	for (auto it = myArr.begin(); it != myArr.end(); it++) {
		cout << *it << endl;
	}

}