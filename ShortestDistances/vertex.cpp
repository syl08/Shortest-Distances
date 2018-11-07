#include <iostream>
#include "vertex.h"


using namespace std;

/// \brief
/// No argument constructor.
Vertex::Vertex()
{

}

/// \brief
/// Constructor which sets the vertex identifier
Vertex::Vertex(unsigned int identifier)
{
    this->identifier = identifier;
}

/// \brief
/// Destructor
Vertex::~Vertex()
{

}

/// \brief
/// Accessor for this vertex¡¯ identifier
unsigned int Vertex::getId()
{
    return identifier;
}

/// \brief
/// Adds a Vertex¡¯ identifier to this Vertex¡¯
/// adjacency list.
void Vertex::addAdjacency(unsigned int identifier)
{
    adjacencies.insert(identifier);
}

/// \brief
/// Returns a pointer to a collection of int,
/// being the vertices adjacent to this Vertex.
set<unsigned int>* Vertex::getAdjacencies()
{
    return &adjacencies;
}

/// \brief
/// Mutator for the discovered field
void Vertex::setDiscovered(bool discovered)
{
    this->discovered = discovered;
}

/// \brief
/// Accessor for the discovered field
bool Vertex::isDiscovered()
{
    return discovered == true;
}

/// \brief
/// Mutator for the predecessorId field
void Vertex::setPredecessorId(unsigned int predecessorId)
{
    this->predecessorId = predecessorId;
}

/// \brief
/// Accessor for the predecessorId field
unsigned int Vertex::getPredecessorId()
{
    return predecessorId;
}

/// \brief
/// Mutator for the minDistance field
void Vertex::setMinDistance(double minDistance)
{
    this->minDistance = minDistance;
}

/// \brief
/// Accessor for the minDistance field
double Vertex::getMinDistance()
{
    return minDistance;
}

/// \brief
/// Function operator implementation to provide
/// an ordering for two Vertex instances. Returns
/// true if the minDistance of the first parameter
/// is greater than that of the second parameter
bool Vertex::operator()(Vertex* first, Vertex* second)
{
    return (second->getMinDistance() <= first->getMinDistance() );
}

/// \brief
/// Provides a string representation of this object.
ostream& operator << (ostream& out, Vertex& vertex)
{
    out << vertex.getId() << endl;
    return out;
}
