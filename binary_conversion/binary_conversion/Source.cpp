/*
Input  an integer  containing  only  0s and 1s(i.e., a  “binary”  integer)
and prints  its  decimal equivalent.
(Hint: Use the modulus and division operators to pick off the “binary” number’s digits one
	at a  time  from right to left. 
	Just as  in the  decimal number system where  the  rightmost digit has a positional
	value of 1 and the next digit left has a positional
	value of 10, then 100, the 1000, etc., in  the  binary 
	number  system, the  rightmost  digit  has  a  positional  
	value  of 1, the  next  digit left  has  a  positional  value  of 2, 
	then  4, then  8, etc.Thus  the  decimal  number  234  can  be interpreted
	as 4 * 1 + 3 * 10 + 2 * 100. The decimal equivalent of 
	binary 1101 is 1 * 1 + 0 * 2 + 1 * 4 + 1 * 8 or 1 + 0 + 4 + 8, or 13.)
*/
#include <iostream>
using namespace std;

int main() {
	int binary, number, decimal = 0, highBit = 16, factor = 10000;
	
	cout << "Enter a binary number (5 digits maximum): ";
	cin >> binary; 
	
	number = binary;
	
	while (highBit >= 1) {
		decimal += binary / factor * highBit;
		highBit /= 2;
		binary %= factor;
		factor /= 10;
	}
	
	cout << "The decimal equivalent of " << number << " is " << decimal << endl;

	return 0;
}