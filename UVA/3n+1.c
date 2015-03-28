//UVA 100

#include <stdio.h>

int dist[1000001];

int algo(unsigned i) {
	int count = 1;
	while(i != 1) {
		if(i&1) {
			i = i + (i<<1) + 1;
			i >>= 1;
			count += 2;
		}
		else {
			i >>= 1;
			count++;
		}
	}
	return count;
}

void swap(int *i, int *j) {
	*i ^= *j;
	*j ^= *i;
	*i ^= *j;
}

int main() {
	int i, j, k, max, temp;
	int tmpi, tmpj;
	for(i = 0; i <= 1000000; i++) dist[i] = 0;
	while(scanf("%d %d", &i, &j) == 2) {
		tmpi = i;
		tmpj = j;
		max = 0;
		if(i > j) swap(&i, &j);  
		for(k = i; k <= j; k++) {
			if(dist[k]) {
				temp = dist[k];
			}
			else {
				temp = algo(k);
				dist[k] = temp;
			}

			if(temp > max) max = temp;
		}
		printf("%d %d %d\n", tmpi, tmpj, max);
	}
}