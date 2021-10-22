#include "Vertex.h"
#include "Edge.h"
#include <cassert>

Vertex::Vertex(const std::string& name)
	: name(name)
{
}

std::string Vertex::getName() const
{
	return name;
}

void Vertex::addNeighbour(Edge* edge)
{
	if (edge)
	{
		assert(edge->getStartVertex().get() == this);
		adjacenciesList.push_back(edge);
	}
}

const std::vector<Edge*>& Vertex::getAdjecenciesList()
{
	return adjacenciesList;
}

Vertex* Vertex::getPredesessor() const
{
	return predecessor;
}

void Vertex::setPredesessor(Vertex* predesessor)
{
	this->predecessor = predesessor;
}

double Vertex::getMinDistance() const
{
	return minDistance;
}

void Vertex::setMinDistance(double distance)
{
	minDistance = distance;
}

bool Vertex::operator<(const Vertex& other) const
{
	return minDistance < other.minDistance;
	
}

std::ostream& operator<<(std::ostream& strm, const Vertex& vert)
{
	strm << vert.name;
	return strm;
}
