#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector<int> parent(30010);
int counter[30010] = {1};

int find (int item) {
	if (parent[item] == item) return item;
	return find(parent[item]);
}

void unify (int set1, int set2) {
	int p1 = find(set1), p2 = find(set2);
	if (p1 == p2) return;
	counter[parent[p1]] += counter[find(parent[p2])];
	parent[p1] = parent[p2];
}

int main () {
	fill_n(counter, 30010, 1);
	parent.clear();
	for (int i = 1; i <=n; i++) {
			parent[i] = i;
		}
	/* Enter logic here */
}