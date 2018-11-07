#include <algorithm>
#include <iomanip>

#include "graph.h"

using namespace std;

/// \brief
/// Constructor sets the number of vertices in this
/// Graph. Initialises the two dimensional array of
/// weights by setting all values to INFINITY (some value
/// larger than any possible edge weight) except the diagonal
/// of the array where the weight is set to 0.
Graph::Graph(unsigned int numVertices)
{
    this->numVertices = numVertices;

    weights = new double*[numVertices];

    for (unsigned int i = 0; i < numVertices; i++)
    {
        weights[i] = new double[numVertices];
        for(unsigned int j = 0; j < numVertices; j++)
        {
            weights[i][j] = INFINITY;
        }
        weights[i][i] = 0;
    }
}

/// \brief
/// Destructor
Graph::~Graph()
{
    for (unsigned i = 0; i < numVertices; i++)
    {
        delete[] weights[i];
    }
    delete[] weights;
}

/// \brief
/// Adds pointer to Vertex to the collection of vertices for this Graph.
void Graph::addVertex(Vertex* vertex)
{
    vertices.push_back(vertex);
}

/// \brief
/// Accessor returns a pointer to the Vertex with the
/// identifier/index in the parameter
Vertex* Graph::getVertex(int index)
{
    return vertices[index];
}

/// \brief
/// Adds pointer to Edge to the edge list for this Graph.
void Graph::addEdge(Edge* edge)
{
    edges.push(edge);
    weights[edge->getSource()->getId()][edge->getDestination()->getId()] = edge->getWeight();
    weights[edge->getDestination()->getId()][edge->getSource()->getId()] = edge->getWeight();
}

/// \brief
/// Uses Kruskal¡¯s algorithm to find the Minimum Spanning
/// Tree (MST) for this Graph. Stores the edges of the MST in
/// the adjacency list of each Vertex. Returns the cost of the minimum spanning tree.
double Graph::minimumSpanningTreeCost()
{
    // store mincost
    double minCost = 0;

    DisjointSet* disjoinset = new DisjointSet(numVertices);
    unsigned int edgeCount = 0;

    while(!(edges.empty()) && edgeCount < numVertices - 1)
    {
        Edge* edge = edges.top();
        edges.pop();

        if(!disjoinset->sameComponent(edge->getSource()->getId(),edge->getDestination()->getId()))
        {
            edgeCount++;
            disjoinset->join(edge->getSource()->getId(), edge->getDestination()->getId());
            edge->getSource()->addAdjacency(edge->getDestination()->getId());
            edge->getDestination()->addAdjacency(edge->getSource()->getId());
            minCost = minCost + edge->getWeight();
        }
    }
    return minCost;
}

/// \brief
/// Determines the shortest path from the source vertex to
/// all other vertices. Prints the length of the path and
/// the vertex identifiers in the path.
void Graph::dijkstra(unsigned int sourceId)
{
    // create queue
    priority_queue<Vertex*, vector<Vertex*>, Vertex> pq;

    // set each vertex
    vector<Vertex*>::iterator iter;
    for(iter = vertices.begin(); iter != vertices.end(); iter++)
    {
        (*iter)->setDiscovered(false);
        (*iter)->setPredecessorId(sourceId);
        (*iter)->setMinDistance(weights[sourceId][(*iter)->getId()]);
        pq.push(*iter);
    }

    while(!pq.empty())
    {
        Vertex* u = pq.top();
        pq.pop();
        u->setDiscovered(true);

        for(unsigned j = 0; j < vertices.size(); j++)
        {
            Vertex* v = vertices[j];
            if(weights[v->getId()][u->getId()] != INFINITY && v->getId() != u->getId())
            {
                if(!v->isDiscovered())
                {
                    if(u->getMinDistance() + weights[u->getId()][v->getId()] < v->getMinDistance())
                    {
                        v->setMinDistance(u->getMinDistance() + weights[u->getId()][v->getId()]);
                        v->setPredecessorId(u->getId());
                        pq.push(v);
                    }
                }
            }
        }
    }

    // output the length of the shortest paths and the paths
    for(int i = 1; i < numVertices; i++)
    {
        // store distance
        double distance = 0;
        int currentId = i;
        // store path vertex
        vector<int> paths;

        while (currentId != sourceId)
        {
            paths.push_back(currentId);
            distance += weights[currentId][getVertex(currentId)->getPredecessorId()];
            currentId = getVertex(currentId)->getPredecessorId();
        }
        paths.push_back(sourceId);

        if(distance == INFINITY)
        {
            cout << "NO PATH  from 0 to  " << i << endl;
        }
        else
        {
            cout << "Distance from 0 to  " << i << " = " ;
            cout << fixed << showpoint << setw(7) << setprecision(2) << distance;
            cout << "  travelling via  ";

            vector<int>::iterator it;
            for(it = paths.end()-1; it != paths.begin()-1; it--)
            {
                cout << setw(3) << *it ;
            }
            cout << endl;
        }
    }

}

/// \brief
/// Determines the shortest path from the source vertex to
/// all other vertices using only the adjacencies in the
/// minimum spanning tree. Prints the length of the path and
/// the vertex identifiers in the path.
void Graph::bfs(unsigned int sourceId)
{
    // set vertex
    for(unsigned i = 0; i < numVertices; ++i)
    {
        getVertex(i)->setDiscovered(false);
    }

    // create queue
    queue<Vertex*> q;

    getVertex(sourceId)->setDiscovered(true);
    q.push(getVertex(sourceId));

    while(!q.empty())
    {
        Vertex* current = q.front();
        q.pop();

        set<unsigned int> adjacencies = *(current->getAdjacencies());
        set<unsigned int>::iterator iter;
        for(iter = adjacencies.begin(); iter != adjacencies.end(); iter++)
        {
            if(!getVertex(*iter)->isDiscovered())
            {
                getVertex(*iter)->setPredecessorId(current->getId());
                getVertex(*iter)->setDiscovered(true);
                q.push(getVertex(*iter));
            }
        }
    }

    // output the length of the shortest paths and the paths
    for(int i = 1; i < numVertices; i++)
    {
        // store distance
        double distance = 0;
        int currentId = i;
        // store path vertex
        vector<int> paths;

        while (currentId != sourceId)
        {
            paths.push_back(currentId);
            distance += weights[currentId][getVertex(currentId)->getPredecessorId()];
            currentId = getVertex(currentId)->getPredecessorId();
        }
        paths.push_back(sourceId);

        if(distance == INFINITY)
        {
            cout << "NO PATH  from 0 to  " << i << endl;
        }
        else
        {
            cout << "Distance from 0 to  " << i << " = " ;
            cout << fixed << showpoint << setw(7) << setprecision(2) << distance;
            cout << "  travelling via  ";

            vector<int>::iterator it;
            for(it = paths.end()-1; it != paths.begin()-1; it--)
            {
                cout << setw(3) << *it ;
            }
            cout << endl;
        }
    }
}

/// \brief
/// Outputs the adjacency matrix for the graph. If an edge
/// weight is INFINITY, - should be printed instead of a number.
ostream& operator << (ostream& out, Graph& graph)
{
    for (unsigned i = 0; i < graph.numVertices; i++)
    {
        for (unsigned j = 0; j < graph.numVertices; j++)
        {
            if (graph.weights[i][j] == INFINITY)
            {
                out << setw(7) << "  -";
            }
            else
            {
                out << fixed << showpoint << setw(7) << setprecision(2) << graph.weights[i][j];
            }
        }
        out << endl;
    }
    return out;
}
