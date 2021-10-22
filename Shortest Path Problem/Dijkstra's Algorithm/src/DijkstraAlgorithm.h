#pragma once
#include "Edge.h"
#include "Vertex.h"


class DijkstraAlgorithm
{
public:
	void computePaths(std::shared_ptr<Vertex> sourceVertex);
	std::vector<Vertex* > getShortestPath(std::shared_ptr<Vertex> vertex) const;
};

