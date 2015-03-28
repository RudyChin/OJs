//Quicksum


#include <iostream>

using namespace std;

int main() {
	char line[256];
	while(cin.getline(line,256,'\n')) {
		if(line[0] == '#') break;
		int count = 0;
		int sum = 0;
		while(line[count] != '\0') {
			if(line[count] == ' ') {
				count++;
				continue;
			}
			else {
				sum += ((line[count] - 'A') + 1) * (count + 1);
				count++;
			}
		}
		cout << sum << endl;
	}

}