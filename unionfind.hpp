#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP

#include <iostream>
using namespace std;

namespace graph {
    struct Edge {
		int src, dest, weight;
	};
	
	class UnionFind {
	private:
		int *parent, *rank;
	
	public:
		UnionFind(int n) {
			parent = new int[n];
			rank = new int[n];
			for (int i = 0; i < n; ++i) {
				parent[i] = i;
				rank[i] = 0;
			}
		}
	
		~UnionFind() {
			delete[] parent;
			delete[] rank;
		}
	
		int find(int u) {
			if (u != parent[u])
				parent[u] = find(parent[u]);  // Path compression
			return parent[u];
		}
	
		void unionSet(int u, int v) {
			int rootU = find(u);
			int rootV = find(v);
			if (rootU != rootV) {
				if (rank[rootU] > rank[rootV]) {
					parent[rootV] = rootU;
				} else if (rank[rootU] < rank[rootV]) {
					parent[rootU] = rootV;
				} else {
					parent[rootV] = rootU;
					rank[rootU]++;
				}
			}
		}
	};
}

#endif // QUEUE_HPP
