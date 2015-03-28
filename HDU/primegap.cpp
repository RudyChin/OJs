//primegap


#include <iostream>
#include <cstring>

using namespace std;

int main () {
	bool *check = new bool [1299709];
	int *gap = new int [1299709];
	memset(check, 0, 1299709 * sizeof(bool));
	int k;
	while(cin >> k, k) {
		if(!check[k-1]) {
			int firstPrime, secondPrime;
			int i;
			for(i = k; i >= 0; i--) {
				bool found = true;
				for(int j = 2; j * j <= i; j++)
					if(i%j==0) { 
						found = false;
						break;
					}
				if(found) { 
					firstPrime = i;
					break;
				}
			}
			i = k;
			while(1) {
				i++;
				bool found = true;
				for(int j = 2; j * j <= i; j++)
					if(i%j==0) { 
						found = false;
						break;
					}
				if(found) { 
					secondPrime = i;
					break;
				}
			}
			for(i = firstPrime+1; i < secondPrime; i++) {
				check[i-1] = true;
				gap[i-1] = secondPrime - firstPrime;
			}
			check[firstPrime-1] = true;
			check[secondPrime-1] = true;
			gap[firstPrime-1] = 0;
			gap[secondPrime-1] = 0;
		}
		cout << gap[k-1] << endl;
	}
}