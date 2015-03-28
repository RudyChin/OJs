//UVA level 1
//The Fibonaccimal Base

#include <iostream>
#include <string.h>

#define LARGEST 40

using namespace std;

int findPos(int *fib,int input) {
	int k = 0;
	while(k < LARGEST && fib[k] <= input) k++;
	return k-1;
}

int main() {
	int fib[LARGEST];
	bool answer[LARGEST];
	int firstOnePos;
	fib[0] = 1;
	fib[1] = 2;
	for(int i = 2; i < LARGEST; i++)
		fib[i] = fib[i-1] + fib[i-2];
	int n;
	cin >> n;
	int input;
	for (int i = 0; i < n; ++i)
	{
		cin >> input;
		int temp = input;
		int k;
		bool first = true;
		memset(answer,0,LARGEST*sizeof(bool));
		while (temp) {
			k = findPos(fib,temp);
			temp -= fib[k];
			answer[k] = 1;
			if(first) { 
				firstOnePos = k;
				first = false;
			}
		}
		cout << input << " = ";
		for (int j = firstOnePos; j >= 0; j--) {
			cout << answer[j];
		}
		cout << " (fib)" << endl;
	}
	return 0;
}