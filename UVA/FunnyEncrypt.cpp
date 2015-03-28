//UVA level 1
//Funny Encryption Method

#include <iostream>

using namespace std;

int power(int base, int exp) {
	int sum = 1;
	for(int i = 0; i < exp; i++)
		sum *= base;
	return sum;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		int temp = input;
		int b1 = 0, b2 = 0;
		while (temp) {
			if (temp % 2) b1++;
			temp /= 2;
		}
		int strRep[100];
		temp = input;
		int k = 0;
		while (temp) {
			strRep[k++] = temp % 10;
			temp /= 10;
		}
		int hexRep = 0;
		for (int j = 0; j < k; j++)
			hexRep += (strRep[j] * power(16,j));
		while (hexRep) {
			if (hexRep % 2) b2++;
			hexRep /= 2;
		}
		cout << b1 << " " << b2 << endl;
	}
	return 0;
}