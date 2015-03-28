//UVA level 2
//Brick Wall Patterns

#include <iostream>

using namespace std;

/*int Permuatation(int bricks) {
	if (bricks == 0) return 1;
	else if (bricks < 0) return 0;
	else {
		int left = Permuatation(bricks-1);
		int right = Permuatation(bricks-2);
		return left + right;
	}
}*/

int main() {
	long fib[50];
	fib[0] = 1;
	fib[1] = 2;
	for(int i = 2; i < 50; i++)
		fib[i] = fib[i-1] + fib[i-2];
	int n;
	while(cin >> n, n != 0)
		cout << fib[n-1] << endl;
	return 0;
}