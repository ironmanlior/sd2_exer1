#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream> // for print only
using namespace std;

namespace graph {
    class Graph {
    private:
        int vertices;
		int** matrix;
    
    public:
        Graph(int vertices) {
			this->vertices = vertices;
			this->matrix = new int*[vertices];
			for (int i = 0; i < vertices; i++){
				this->matrix[i] = new int[vertices];
				for (int j = 0; j < vertices; j++)
					this->matrix[i][j] = 0;
			}
		}

        ~Graph(){
			for (int i = 0; i < vertices; i++)
			    delete[] this->matrix[i];
			delete[] this->matrix;
		}

        void addEdge(int src, int dest, int weight = 1){
			this->matrix[src][dest] = weight;
			this->matrix[dest][src] = weight;
		}

        void removeEdge(int src, int dest){
			this->matrix[src][dest] = 0;
			this->matrix[dest][src] = 0;
		}
        void print() const{
			for (int v = 0; v < vertices; ++v) {
				cout << v << ": ";
				for (int i = 0; i < vertices; i++){
					cout << matrix[v][i] << ",";
				}
				cout << endl;
			}
		}
        int getVertices() const {
			return this->vertices;
		}
        int getEdge(int src, int dest) const {
			return this->matrix[src][dest];
		}

		int** getMatrix() const {
			return this->matrix;
		}
    };
}

#endif // GRAPH_HPP
