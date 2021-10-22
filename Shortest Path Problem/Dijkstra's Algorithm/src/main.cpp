#include <iostream>
#include <memory>
#include <vector>
#include "DijkstraAlgorithm.h"

int main()
{
	std::vector<std::shared_ptr<Vertex>> vertexList;

	vertexList.push_back(std::make_shared<Vertex>("A"));
	vertexList.push_back(std::make_shared<Vertex>("B"));
	vertexList.push_back(std::make_shared<Vertex>("C"));
	vertexList.push_back(std::make_shared<Vertex>("D"));
	vertexList.push_back(std::make_shared<Vertex>("E"));
	vertexList.push_back(std::make_shared<Vertex>("F"));
	vertexList.push_back(std::make_shared<Vertex>("G"));
	vertexList.push_back(std::make_shared<Vertex>("H"));




	std::shared_ptr<Edge> edge01 = std::make_shared<Edge>(5, vertexList[0], vertexList[1]);
	std::shared_ptr<Edge> edge04 = std::make_shared<Edge>(9, vertexList[0], vertexList[4]);
	std::shared_ptr<Edge> edge07 = std::make_shared<Edge>(8, vertexList[0], vertexList[7]);
	std::shared_ptr<Edge> edge13 = std::make_shared<Edge>(12, vertexList[1], vertexList[3]);
	std::shared_ptr<Edge> edge14 = std::make_shared<Edge>(15, vertexList[1], vertexList[4]);
	std::shared_ptr<Edge> edge17 = std::make_shared<Edge>(4, vertexList[1], vertexList[7]);
	std::shared_ptr<Edge> edge23 = std::make_shared<Edge>(3, vertexList[2], vertexList[3]);
	std::shared_ptr<Edge> edge26 = std::make_shared<Edge>(11, vertexList[2], vertexList[6]);
	std::shared_ptr<Edge> edge36 = std::make_shared<Edge>(9, vertexList[3], vertexList[6]);
	std::shared_ptr<Edge> edge45 = std::make_shared<Edge>(4, vertexList[4], vertexList[5]);
	std::shared_ptr<Edge> edge46 = std::make_shared<Edge>(20, vertexList[4], vertexList[6]);
	std::shared_ptr<Edge> edge47 = std::make_shared<Edge>(5, vertexList[4], vertexList[7]);
	std::shared_ptr<Edge> edge52 = std::make_shared<Edge>(1, vertexList[5], vertexList[2]);
	std::shared_ptr<Edge> edge56 = std::make_shared<Edge>(13, vertexList[5], vertexList[6]);
	std::shared_ptr<Edge> edge72 = std::make_shared<Edge>(7, vertexList[7], vertexList[2]);
	std::shared_ptr<Edge> edge75 = std::make_shared<Edge>(6, vertexList[7], vertexList[5]);

	vertexList[0]->addNeighbour(edge01.get());
	vertexList[0]->addNeighbour(edge04.get());
	vertexList[0]->addNeighbour(edge07.get());
	vertexList[1]->addNeighbour(edge13.get());
	vertexList[1]->addNeighbour(edge14.get());
	vertexList[1]->addNeighbour(edge17.get());
	vertexList[2]->addNeighbour(edge23.get());
	vertexList[2]->addNeighbour(edge26.get());
	vertexList[3]->addNeighbour(edge36.get());
	vertexList[4]->addNeighbour(edge45.get());
	vertexList[4]->addNeighbour(edge46.get());
	vertexList[4]->addNeighbour(edge47.get());
	vertexList[5]->addNeighbour(edge52.get());
	vertexList[5]->addNeighbour(edge56.get());
	vertexList[7]->addNeighbour(edge72.get());
	vertexList[7]->addNeighbour(edge75.get());

	DijkstraAlgorithm sp;
	sp.computePaths(vertexList[0]);

	auto path = sp.getShortestPath(vertexList[6]);

	for (auto v : path)
	{
		std::cout << *v << "\t";
	}
	std::cout << std::endl;

	return 0;
}