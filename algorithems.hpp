#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "graph.hpp"
#include "queue.hpp"
#include "unionfind.hpp"
#include <limits>

const int INF = numeric_limits<int>::max();




namespace graph {
    class Algorithms {
    private:
        static void dfsUtil(const Graph& g, int v, bool visited[], Queue& res) {
            if (!visited[v]) {
                res.push(v);
            }
            
            visited[v] = true;

            for (int u = 0; u < g.getVertices(); ++u) {
                if (g.getEdge(v, u) != 0 && !visited[u]) {
                    dfsUtil(g, u, visited, res);
                }
            }
        }

        static int minDistance(const Graph& g, int dist[], bool sptSet[]) {
            int min = INF, min_index;
        
            for (int v = 0; v < g.getVertices(); v++)
                if (!sptSet[v] && dist[v] <= min)
                    min = dist[v], min_index = v;
        
            return min_index;
        }


        static void sortEdges(Edge* edges, int n) {
            for (int i = 0; i < n - 1; i++) {
                bool swapped = false;
                for (int j = 0; j < n - i - 1; j++) {
                    if (edges[j].weight > edges[j + 1].weight) {
                        Edge temp = edges[j];
                        edges[j] = edges[j + 1];
                        edges[j + 1] = temp;
                        swapped = true;
                    }
                }
                if (!swapped)
                    break;  // No swaps means the array is already sorted
            }
        }
    public:
        static void bfs(const Graph& g, int start, Queue& res){
            bool* visited = new bool[g.getVertices()];
            Queue q = Queue();

            visited[start] = true;
            q.push(start);

            while (!q.empty()) {
                int u = q.pop();
                res.push(u);

                for (int v = 0; v < g.getVertices(); v++) {
                    if (g.getEdge(u, v) != 0 && !visited[v]) {
                        visited[v] = true;
                        q.push(v);
                        
                    }
                }
            }
        }


        static void dfs(const Graph& g, Queue& res){
            bool* visited = new bool[g.getVertices()];
            for (int u = 0; u < g.getVertices(); u++) {
                dfsUtil(g, u, visited, res);
            }
        }


        static int* dijkstra(const Graph& g, int start) {
            int V = g.getVertices();
            int* dist = new int[V];  // Distance of each vertex from the source
            bool* sptSet = new bool[V]; // Shortest path tree set
            for (int i = 0; i < V; i++)
                dist[i] = INF, sptSet[i] = false;

                
            
            // Distance of source vertex from itself is always 0
            dist[start] = 0;
        
            // Find shortest path for all vertices
            for (int count = 0; count < V - 1; count++) {
                // Pick the minimum distance vertex from the set of vertices not yet processed.
                int u = minDistance(g, dist, sptSet);
        
                // Mark the picked vertex as processed
                sptSet[u] = true;
        
                // Update dist value of the adjacent vertices of the picked vertex.
                for (int v = 0; v < V; v++)
                    // Update dist[v] only if is not in sptSet, there is an edge from u to v,
                    // and total weight of path from src to v through u is smaller than current value of dist[v]
                    if (!sptSet[v] && g.getMatrix()[u][v] && dist[u] != INF
                        && dist[u] + g.getMatrix()[u][v] < dist[v])
                        dist[v] = dist[u] + g.getMatrix()[u][v];
            }
            return dist;
        }


        static void prim(const Graph& g, Graph& mst) {
            int V = g.getVertices();
        
            int key[V];
            bool inMST[V];
            int parent[V];

            for (int i = 0; i < g.getVertices(); ++i) {
                key[i] = INF;
                inMST[i] = false;
                parent[i] = -1;
            }
        
            key[0] = 0;
        
            for (int count = 0; count < V - 1; ++count) {
                int u = -1;
        
                for (int v = 0; v < V; ++v) {
                    if (!inMST[v] && key[v] < key[u]) {
                        u = v;
                    }
                }
        
                if (u == -1) break;
        
                inMST[u] = true;
        
                for (int v = 0; v < V; ++v) {
                    if (g.getEdge(u, v) && !inMST[v] && g.getEdge(u, v) < key[v]) {
                        key[v] = g.getEdge(u, v);
                        parent[v] = u;
                    }
                }
            }
        
            for (int v = 1; v < V; ++v) {
                if (parent[v] != -1)
                    mst.addEdge(parent[v], v, g.getEdge(parent[v], v));
            }
        }



        static void kruskal(const Graph& g, Graph& mst) {
            int V = g.getVertices();
        
            Edge* edges = new Edge[V * V];
            int edgeCount = 0;
        
            for (int i = 0; i < V; ++i) {
                for (int j = i + 1; j < V; ++j) {
                    if (g.getEdge(i, j) != 0) {
                        edges[edgeCount++] = {i, j, g.getEdge(i, j)};
                    }
                }
            }
        
            sortEdges(edges, edgeCount);
            UnionFind uf(V);

        
            for (int i = 0; i < edgeCount; ++i) {
                int u = edges[i].src;
                int v = edges[i].dest;
                if (uf.find(u) != uf.find(v)) {
                    uf.unionSet(u, v);
                    mst.addEdge(u, v, edges[i].weight);
                }
            }
        
            delete[] edges;
        }
    };
}




#endif // ALGORITHMS_HPP