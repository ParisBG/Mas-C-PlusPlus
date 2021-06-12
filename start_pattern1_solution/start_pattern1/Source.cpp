#include <iostream>
#include <string>
using namespace std;

void showStars(int);

int main() {

	for (int x = 0; x < 10; x++) {
		showStars(x+1);
		cout << endl;
	}
	return 0;
}

void showStars(int starNum) {
	string star = "*";

	for (int i = 0; i < starNum; i++) {
		cout << star;
	}
}