#pragma once
#include "Vertex.h"

class Edge
{
private:
	double weight;
	std::shared_ptr<Vertex> startVertex;
	std::shared_ptr<Vertex> targetVertex;

public:
	Edge(double weight, const std::shared_ptr<Vertex>& startVertex, const std::shared_ptr<Vertex>& targetVertex);

	double getWeight() const;
	std::shared_ptr<Vertex> getStartVertex() const;
	std::shared_ptr<Vertex> getTargetVertex() const;
};

