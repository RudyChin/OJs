//  Ubiquitous Religions


#include <iostream>

using namespace std;

struct node
{
	/* data */
	int sid;
	node *next;
};

struct tag
{
	/* data */
	bool linked;
	int listNum;
};

int main() {
	int n, m;
	while (cin >> n >> m, (n!=0 && m!=0)) {
		tag track[n];
		int number = 1;
		for(int i = 0; i < n; i++) track[i].linked = false;
		node *diffList[n];
		int toBeDel[n];
		for(int i = 0; i < n; i++) toBeDel[i] = -1;
		int delIdx = 0;
		int count = 0;
		int total = 0;
		for(int k = 0; k < m; k++) {
			int i, j;
			cin >> i >> j;
			i--;
			j--;
			if(!track[i].linked && !track[j].linked) {
				node *tempi = new node;
				tempi->sid = i;
				tempi->next = NULL;

				node *tempj = new node;
				tempj->sid = j;
				tempj->next = NULL;
				
				track[i].linked = true;
				track[i].listNum = count;
				track[j].linked = true;
				track[j].listNum = count;

				tempi->next = tempj;
				diffList[count++] = tempi;
				total++;
			} 
			else if(!track[i].linked && track[j].linked) {
				node *tempi = new node;
				tempi->sid = i;
				tempi->next = NULL;

				int pos = track[j].listNum;
				node *tempHead = diffList[pos];
				tempi->next = tempHead;
				diffList[pos] = tempi;

				track[i].linked = true;
				track[i].listNum = pos;
			} 
			else if(track[i].linked && !track[j].linked) {
				node *tempj = new node;
				tempj->sid = j;
				tempj->next = NULL;

				int pos = track[i].listNum;
				node *tempHead = diffList[pos];
				tempj->next = tempHead;
				diffList[pos] = tempj;

				track[j].linked = true;
				track[j].listNum = pos;
			}
			else {
				int posi = track[i].listNum;
				int posj = track[j].listNum;
				if (posi == posj) break;
				total--;
				toBeDel[delIdx++] = posj;
				node *tempHeadj = diffList[posj];
				node *tempHeadi = diffList[posi];
				while(tempHeadi->next) tempHeadi = tempHeadi->next;
				tempHeadi->next = tempHeadj;
				while(tempHeadj) { 
					track[tempHeadj->sid].listNum = posi;
					tempHeadj = tempHeadj->next;
				}
			}
		}
		int notCounted = 0;
		for(int k = 0; k < n; k++) {
			if(!track[k].linked) notCounted++;
		}
		for(int k = 0; k < n; k++)
			for(int w = 0; w < delIdx; w++) {
				if(k != toBeDel[w]) {
					node *tempHead = diffList[k];
					while(tempHead) {
						node *temp = tempHead;
						tempHead = tempHead->next;
						delete temp;
					}
				}
			}
		cout << "Case " << number++ << ": " << total+notCounted << endl;
	}
}