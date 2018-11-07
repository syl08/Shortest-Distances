#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

#include <iostream>
#include "vertex.h"

/// \brief
/// This class encapsulates pointers to the source and
/// destination Vertex objects and the weight of the Edge.
class Edge
{

public:

    /// \brief
    /// No argument constructor.
    Edge();

    /// \brief
    /// Constructor which sets the source vertex,
    /// the destination vertex and the weight for
    /// this Edge
    Edge(Vertex*, Vertex*, double);

    /// \brief
    /// Destructor
    ~Edge();

    /// \brief
    /// Returns a pointer to the source vertex
    Vertex* getSource();

    /// \brief
    /// Returns a pointer to the destination vertex
    Vertex* getDestination();

    /// \brief
    /// Returns the weight of this Edge
    double getWeight();

    /// \brief
    /// Function operator provides an ordering for
    /// edges. Returns true if the weight of the first
    /// parmeter is greater than that of the second paramter.
    bool operator()(Edge*, Edge*);

    /// \brief
    /// Returns a string representation of this Edge.
    friend ostream& operator << (ostream&, Edge&);

private:

    /// Instance field for the source vertex
    Vertex* source;

    /// Instance field for the destination vertex
    Vertex* destination;

    /// Instance field for the edge weight
    double weight;
};

#endif // EDGE_H_INCLUDED
