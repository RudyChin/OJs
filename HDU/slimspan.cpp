//Slim Span


#include <iostream>
#include <algorithm>

using namespace std;

struct edge
{
	/* data */
	int a;
	int b;
	int w;
};

bool comparator(edge a, edge b) {
	return a.w < b.w;
}

int find(int *p, int x) {
	if(p[x] == x)	return x;
	else	return find(p,p[x]);
}

int main() {
	int v, e;
	while(cin >> v >> e, v || e) {
		edge edgelist[e];
		int p[v+1];
		int tot = 0;
		int prevAns = 0;
		int ans = 0;
		for(int i = 0; i < v+1; i++) p[i] = i;
		for(int i = 0; i < e; i++) {
			int a, b, w;
			cin >> a >> b >> w;
			edgelist[i].a = a;
			edgelist[i].b = b;
			edgelist[i].w = w;
			if(find(p,a) != find(p,b)) {
				tot++;
				p[find(p,a)] = find(p,b);
			}
		}
		if (tot != v-1) prevAns = -1;
		else {
			prevAns = 2147483647;
			sort(edgelist, edgelist+e, comparator);
			ans = 2147483647;
			for(int i = 0; i < e; i++) {
				if (i == 0 || edgelist[i].w != edgelist[i-1].w) {
					tot = 0;
					for(int k = 0; k < v+1; k++) p[k] = k;
					for(int j = i; j < e; j++) {
						if(find(p,edgelist[j].a) != find(p,edgelist[j].b)) {
							tot++;
							p[find(p,edgelist[j].a)] = find(p,edgelist[j].b);
							if(tot == v-1) {
								ans = ans < (edgelist[j].w - edgelist[i].w) ? ans : (edgelist[j].w - edgelist[i].w);
								break;
							}
						}
					}
					if(tot == v-1) prevAns = ans;
					else break;
				}
			}
		}
		cout << prevAns << endl;
	}
}