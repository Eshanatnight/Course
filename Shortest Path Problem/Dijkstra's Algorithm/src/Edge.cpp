#include "Edge.h"

Edge::Edge(double weight, const std::shared_ptr<Vertex>& startVertex, const std::shared_ptr<Vertex>& targetVertex)
    : weight(weight), startVertex(startVertex), targetVertex(targetVertex)
{

}


double Edge::getWeight() const
{
    return weight;
}

std::shared_ptr<Vertex> Edge::getStartVertex() const
{
    return startVertex;
}

std::shared_ptr<Vertex> Edge::getTargetVertex() const
{
    return targetVertex;
}
