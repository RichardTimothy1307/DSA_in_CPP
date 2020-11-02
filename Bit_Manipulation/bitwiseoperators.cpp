#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("bminput.txt", "r", stdin);
	freopen("bmoutput.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);

	/*bitwise AND -> 0 & 1 -> 0
	bitwise OR -> 0 | 1 -> 1
	bitwise XOR -> 0^1 , 1^0 -> 1 bits should be different to get 1
	N*(2^i) Left shift -> 001<<1 -> 010 -> shifts the bits to 1 places to Left
	N/(2^i)Right shift -> 001>>1 -> 000 -> shifts the bits to right 1 places
	bitwise NOT -> 0->1 , 1->0 inverts*/

	unsigned char a = 5, b = 9; //unsigned holds positive values
	//Ascii of 5=00000101
	//Ascii of 9=00001001

	cout << (int)a << "&" << (int)b << "=" << (a & b) << endl; //00000001=1
	cout << (int)a << "|" << (int)b << "=" << (a | b) << endl; //00001101=13
	cout << (int)a << "^" << (int)b << "=" << (a ^ b) << endl; //00001100 =12
	cout << "9<<1 or 9*2^1" << "=" << (b << 1) << endl;
	cout << "9>>1 or 9/2^1" << "=" << (b >> 1) << endl;

	return 0;

}






