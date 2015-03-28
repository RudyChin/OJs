//106 miles to chicago


#include <iostream>

using namespace std;

int main() {
	int v, e;
	while(cin >> v, v) {
		cin >> e;
		float weight[v*v];
		float ans = 1;
		for(int i = 0; i < v*v; i++) weight[i] = 0;
		for(int i = 0; i < e; i++) {
			int a, b, w;
			cin >> a >> b >> w;
			a--;
			b--;
			weight[a*v+b] = w/100.0;
			weight[b*v+a] = w/100.0;
		}
		for(int k = 0; k < v; k++) {
			for(int i = 0; i < v; i++) {
				for(int j = 0; j < v; j++) {
					if(weight[i*v+j] < weight[i*v+k] * weight[k*v+j]) weight[i*v+j] = weight[i*v+k] * weight[k*v+j];
				}
			}
		}
		cout << weight[0*v+v] * 100.0 << " percent" << endl;
	}
}