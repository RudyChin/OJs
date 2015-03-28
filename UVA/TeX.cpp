//UVA 272

#include <iostream>

using namespace std;

typedef enum  {
	leftQ,
	rightQ
} quote_t;

void add(char *line, int pos, quote_t q) {
	int end = 0;
	while(line[end++]!='\0');
	for(int i = end; i > pos; i--) {
		line[i] = line[i-1];
	}
	if(q == leftQ) {
		line[pos] = '`';
		line[pos+1] = '`';
	} else {
		line[pos] = '\'';
		line[pos+1] = '\'';
	}
}

int main() {
	char line[2000];
	quote_t q = leftQ;
	while(cin.getline(line, 2000, '\n')) {
		int i = 0;
		while(i < 2000 && line[i] != '\0') {
			if(line[i] == '\"') {
				add(line, i, q);
				q == leftQ? q = rightQ : q = leftQ;
			}
			i++;
		}
		cout << line << endl;
	}
	return 0;
}
