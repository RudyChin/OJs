//Mileage Bank


#include <iostream>
#include <stdlib.h>

using namespace std;

int main () {
	char line[256];
	int sum = 0;
	while(cin.getline(line,256,'\n')) {
		if(line[0] == '#') break;
		else if(line[0] == '0') {
			//output and flush data
			cout << sum << endl;
			sum = 0;
		} else {
			//sum the miles
			int pos = 0;
			char level;
			char strmiles[10];
			int mileIdx = 0;
			while(line[pos] > '9' || line[pos] < '0') pos++;
			while(line[pos] <= '9' && line[pos] >= '0') strmiles[mileIdx++] = line[pos++];
			level = line[pos+1];
			strmiles[mileIdx] = '\0';
			switch(level) {
				case 'F':
					sum += 2*atoi(strmiles);
					break;
				case 'B':
					sum += (int)(0.5+(1.5*atoi(strmiles)));
					break;
				case 'Y':
					if(atoi(strmiles) <= 500) sum += 500;
					else sum += atoi(strmiles);
					break;
			}
		}
	}
}