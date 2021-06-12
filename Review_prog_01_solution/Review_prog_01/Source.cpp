#include <iostream>

using namespace std;

int main() {

	int num1;
	int num2;

	cout << "Please enter your first integer:";
	cin >> num1;

	cout << "Please enter your second integer:";
	cin >> num2;

	if (num1 > num2) {

		cout << num1 << " is larger!" << endl;;


	} else if (num2 > num1) {

		cout << num2 << " is larger!" << endl;;


	} else {
		cout << "THESE NUMBERS ARE EQUAL!!" << endl;
	}


	return 0;
}

/* Write a program that asks the user to enter two integers,
obtains the numbers from the user,
then prints the larger number followed by the words “is larger.”
If thenumbers are equal, print the message “These numbers are equal.”
*/