#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include <vector>
#include <queue>
#include <set>

#include "vertex.h"
#include "edge.h"
#include "disjointset.h"


using namespace std;

const int INFINITY = 9999999;

/// \brief
/// This class encapsulates a weighted undirected graph.
class Graph
{
public:

    /// \brief
    /// Constructor sets the number of vertices in this
    /// Graph. Initialises the two dimensional array of
    /// weights by setting all values to INFINITY (some value
    /// larger than any possible edge weight) except the diagonal
    /// of the array where the weight is set to 0.
    Graph(unsigned int);

    /// \brief
    /// Destructor
    ~Graph();

    /// \brief
    /// Adds pointer to Vertex to the collection of vertices for this Graph.
    void addVertex(Vertex*);

    /// \brief
    /// Accessor returns a pointer to the Vertex with the
    /// identifier/index in the parameter
    Vertex* getVertex(int);

    /// \brief
    /// Adds pointer to Edge to the edge list for this Graph.
    void addEdge(Edge*);

    /// \brief
    /// Uses Kruskal¡¯s algorithm to find the Minimum Spanning
    /// Tree (MST) for this Graph. Stores the edges of the MST in
    /// the adjacency list of each Vertex. Returns the cost of the minimum spanning tree.
    double minimumSpanningTreeCost();

    /// \brief
    /// Determines the shortest path from the source vertex to
    /// all other vertices. Prints the length of the path and
    /// the vertex identifiers in the path.
    void dijkstra(unsigned int);

    /// \brief
    /// Determines the shortest path from the source vertex to
    /// all other vertices using only the adjacencies in the
    /// minimum spanning tree. Prints the length of the path and
    /// the vertex identifiers in the path.
    void bfs(unsigned int);

    /// \brief
    /// Outputs the adjacency matrix for the graph. If an edge
    /// weight is INFINITY, - should be printed instead of a number.
    friend ostream& operator << (ostream&,Graph&);

private:

    /// Instance field for the number of vertices in the graph.
    unsigned int numVertices;

    /// The adjacency matrix for this graph. Twodimensional array
    /// of weights.
    double** weights;

    /// Storage for edges to be used by Kruskal¡¯s algorithm for
    /// calculating the minimum cost spanning tree.
    priority_queue<Edge*, vector<Edge*>, Edge> edges;

    /// Storage for graph vertices
    vector<Vertex*> vertices;

};

#endif // GRAPH_H_INCLUDED
