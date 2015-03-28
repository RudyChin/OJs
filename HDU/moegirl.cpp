//moe girls


#include <iostream>
#include <string.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	char spaceEater[1];
	cin.getline(spaceEater,1,'\n');
	for(int i = 0; i < n; i++) {
		char line[120];
		cin.getline(line,101,'\n');
		int length = 0;
		while(line[length] != '\0') length++;
		if(line[length-4] == 'd' && line[length-3] == 'e' && line[length-2] == 's' && line[length-1] == 'u') {
			line[length-4] = '\0';
		}
		strcat(line, "nanodesu");
		cout << "Case #" << i+1 << ": " << line << endl;
	}
}