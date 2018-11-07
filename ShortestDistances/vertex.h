#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED
#include <iostream>
#include <set>

using namespace std;

/// \brief
/// This class encapsulates the identifier of a Vertex object
/// and a collection of Vertex objects in the minimum spanning
/// tree of the graph which are adjacent to this Vertex.
class Vertex
{
public:

    /// \brief
    /// No argument constructor.
    Vertex();

    /// \brief
    /// Constructor which sets the vertex identifier
    Vertex(unsigned int);

    /// \brief
    /// Destructor
    ~Vertex();

    /// \brief
    /// Accessor for this vertex¡¯ identifier
    unsigned int getId();

    /// \brief
    /// Adds a Vertex¡¯ identifier to this Vertex¡¯
    /// adjacency list.
    void addAdjacency(unsigned int);

    /// \brief
    /// Returns a pointer to a collection of int,
    /// being the vertices adjacent to this Vertex.
    set<unsigned int>* getAdjacencies();

    /// \brief
    /// Mutator for the discovered field
    void setDiscovered(bool);

    /// \brief
    /// Accessor for the discovered field
    bool isDiscovered();

    /// \brief
    /// Mutator for the predecessorId field
    void setPredecessorId(unsigned int);

    /// \brief
    /// Accessor for the predecessorId field
    unsigned int getPredecessorId();

    /// \brief
    /// Mutator for the minDistance field
    void setMinDistance(double);

    /// \brief
    /// Accessor for the minDistance field
    double getMinDistance();

    /// \brief
    /// Function operator implementation to provide
    /// an ordering for two Vertex instances. Returns
    /// true if the minDistance of the first parameter
    /// is greater than that of the second parameter
    bool operator()(Vertex*, Vertex*);

    /// \brief
    /// Provides a string representation of this object.
    friend ostream& operator << (ostream&, Vertex&);

private:

    /// Instance field to store the identifier for this Vertex
    unsigned int identifier;

    /// Stores vertex identifiers for vertices adjacent to
    /// this vertex as discovered
    set<unsigned int> adjacencies;

    /// Keeps track of whether or not this vertex has been visited
    bool discovered;

    /// Stores the predecessor vertex identifier for path discovery
    unsigned int predecessorId;

    /// Store the minimum distance from the source to this vertex.
    double minDistance;

};


#endif // VERTEX_H_INCLUDED
