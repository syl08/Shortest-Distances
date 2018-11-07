#include "edge.h"

using namespace std;

/// \brief
/// No argument constructor.
Edge::Edge()
{

}

/// \brief
/// Constructor which sets the source vertex,
/// the destination vertex and the weight for
/// this Edge
Edge::Edge(Vertex* source, Vertex* destination, double weight)
{
    this->source = source;
    this->destination = destination;
    this->weight = weight;
}

/// \brief
/// Destructor
Edge::~Edge()
{

}

/// \brief
/// Returns a pointer to the source vertex
Vertex* Edge::getSource()
{
    return source;
}

/// \brief
/// Returns a pointer to the destination vertex
Vertex* Edge::getDestination()
{
    return destination;
}

/// \brief
/// Returns the weight of this Edge
double Edge::getWeight()
{
    return weight;
}

/// \brief
/// Function operator provides an ordering for
/// edges. Returns true if the weight of the first
/// parmeter is greater than that of the second paramter.
bool Edge::operator()(Edge* first, Edge* second)
{
    return (first->getWeight() > second->getWeight());
}

/// \brief
/// Returns a string representation of this Edge.
ostream& operator << (ostream& out, Edge& edge)
{
    out << edge.getSource() << " " << edge.getDestination() << " " << edge.getWeight() << endl;
    return out;
}
