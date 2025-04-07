#include "algorithems.hpp"

using namespace std;
using namespace graph;

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.print();

    Queue res = Queue();
    Algorithms::bfs(g, 0, res);
    res.print();
    res.clear();

    Algorithms::dfs(g, res);
    res.print();

    int* actual = Algorithms::dijkstra(g, 0);
    for (int i = 0; i < 5; ++i) {
        cout << actual[i] << " ";
	}
    cout << endl;
    Graph res1(5);
    Algorithms::prim(g, res1);
    res1.print();
    cout << endl;
    
    Graph res2(5);
    Algorithms::kruskal(g, res2);
    res2.print();
    return 0;
}