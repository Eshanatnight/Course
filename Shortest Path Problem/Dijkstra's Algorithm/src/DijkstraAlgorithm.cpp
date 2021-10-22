#include "DijkstraAlgorithm.h"
#include <set>
#include <iostream>
#include <algorithm>

void DijkstraAlgorithm::computePaths(std::shared_ptr<Vertex> sourceVertex)
{
	auto fCompare = [&](std::shared_ptr<Vertex> const& l, std::shared_ptr<Vertex> const& r)
	{
		return *l < *r;
	};

	sourceVertex->setMinDistance(0.0);
	std::multiset<std::shared_ptr<Vertex>, decltype(fCompare)> queue(fCompare);
	queue.insert(sourceVertex);

	while (!queue.empty())
	{
		auto iBegin = queue.begin();
		auto actualVertex = *iBegin;
		queue.erase(iBegin);

		for (const Edge* edge : actualVertex->getAdjecenciesList())
		{
			std::shared_ptr<Vertex> from = edge->getStartVertex();
			std::shared_ptr<Vertex> to = edge->getTargetVertex();
			
			double newDistance = actualVertex->getMinDistance() + edge->getWeight();
			if (newDistance < to->getMinDistance())
			{
				for (auto it = queue.begin(); it != queue.end(); it++)
				{
					// Note if we used a Fibornacci Heap this would 
					// have taken O(1) running time complexity
					// Here we are looking for the item to be removed 
					// Hence it takes O(V) running time complexity
					if ((*it)->getName() == to->getName())
					{
						queue.erase(it);
						break;
					}
				}
				to->setMinDistance(newDistance);
				to->setPredesessor(actualVertex.get());
				queue.insert(to);
			}
		}
	}
}

std::vector<Vertex*> DijkstraAlgorithm::getShortestPath(std::shared_ptr<Vertex> vertex) const
{
	std::cout << "Minimum Distance: " << vertex->getMinDistance() << "\n";
	std::vector<Vertex* > path;
	for (Vertex* it = vertex.get(); it != nullptr; it = it->getPredesessor())
		path.push_back(it);
	std::ranges::reverse(path.begin(), path.end());
	return path;
}
