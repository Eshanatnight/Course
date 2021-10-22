#pragma once
#include <string>
#include <memory>
#include <ostream>
#include <vector>
#include <numeric>

class Node;
class Edge;

const int MAX_VALUE = 10e7;

class Vertex
{
private:
	std::string name;
	std::vector<Edge* > adjacenciesList;
	Vertex* predecessor = nullptr;
	double minDistance = MAX_VALUE;


public:
	Vertex(const std::string& name);
	
	// Maybe this should be const reference ?
	std::string getName() const;

	void addNeighbour(Edge* edge);
	const std::vector<Edge* >& getAdjecenciesList();
	Vertex* getPredesessor() const;
	void setPredesessor(Vertex* predesessor);
	double getMinDistance() const;
	void setMinDistance(double distance);


	friend std::ostream& operator<<(std::ostream& strm, const Vertex& vert);
	bool operator<(const Vertex& other) const;
};

