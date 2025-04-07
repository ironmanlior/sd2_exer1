#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "algorithems.hpp"
#include <vector>
#include <queue>

using namespace graph;

TEST_CASE("BFS Traversal") {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);

    Queue res = Queue();
	Algorithms::bfs(g, 0, res);

    vector<int> expected = {0, 1, 4, 2, 3};
	for (int i = 0; i < 5; ++i) {
    	CHECK(res.pop() == expected[i]);
	}
}

TEST_CASE("DFS Traversal") {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);

    Queue res = Queue();
    Algorithms::dfs(g, res);

    vector<int> expected = {0, 1, 2, 3, 4};
	for (int i = 0; i < 5; ++i) {
    	CHECK(res.pop() == expected[i]);
	}
}


TEST_CASE("Dijkstra Shortest Paths") {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 4, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 0, 7);
    g.addEdge(4, 2, 9);
    g.addEdge(4, 3, 2);

	vector<int> expected = {0, 7, 8, 7, 5};
	int* actual = Algorithms::dijkstra(g, 0);
    for (int i = 0; i < 5; ++i) {
    	CHECK(actual[i] == expected[i]);
	}
}


TEST_CASE("Prim Minimum Spanning Tree") {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);
    g.print();
    cout << endl;

    Graph mst(5);
    mst.print();
    cout << endl;
    Algorithms::prim(g, mst);
    mst.print();
    cout << endl;
    int total_weight = 0;
    for (int i = 0; i < mst.getVertices(); ++i) {
        for (int j = i + 1; j < mst.getVertices(); ++j) {
            total_weight += mst.getEdge(i, j);
        }
    }
    CHECK_EQ(total_weight, 16); // MST total weight for this graph
}

TEST_CASE("Kruskal Minimum Spanning Tree") {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    Graph mst(5);
    
    Algorithms::kruskal(g, mst);
    int total_weight = 0;
    for (int i = 0; i < mst.getVertices(); ++i) {
        for (int j = i + 1; j < mst.getVertices(); ++j) {
            total_weight += mst.getEdge(i, j);
        }
    }
    CHECK_EQ(total_weight, 16); // MST total weight for this graph
}