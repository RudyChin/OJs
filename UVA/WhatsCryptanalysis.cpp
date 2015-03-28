//UVA level 1
//What's Cryptanalysis?

#include <iostream>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

struct myObj {
	int value;
	int key;
};

bool myCompare(struct myObj i, struct myObj j) {
	if(i.value == j.value) {
		return (i.key < j.key);
	}
	return (i.value > j.value);
}

int main() {
	char spaceEater[10];
	int n;
	cin >> n;
	cin.getline(spaceEater,10,'\n');
	struct myObj hash[26];
	memset(hash,0,26*sizeof(struct myObj));
	for(int i = 0; i < n; i++) {
		char line[2000];
		cin.getline(line,2000,'\n');
		int length = 0;
		while(line[length] != '\0') length++;
		for (int j = 0; j < length; j++) {
			if(isupper(line[j])) line[j] = tolower(line[j]);
			if(line[j] >= 0x61 && line[j] <= 0x7A) {
				hash[line[j]-'a'].key = line[j];
				hash[line[j]-'a'].value++;
			}
		}
	}
	sort(hash,hash+26,myCompare);
	for(int i = 0; i < 26; i++) {
		if(hash[i].value) cout << (char)toupper((char)hash[i].key) << " " << hash[i].value << endl;
	}
}