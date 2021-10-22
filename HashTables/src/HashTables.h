#pragma once

#include <vector>
#include <list>

class HashTable
{
private:
	// Maximum Number of Items in the MAP
	static constexpr int TABLE_SIZE = 10;

	struct m_HashItem
	{
		int m_key{ 0 };
		int m_value{ 0 };

	};

	// An index can have a more than one itme; we store them in a list
	// Collision? not the Most effective solution
	std::vector<std::list<m_HashItem>>m_HashTable;

public:

	HashTable();

	// If the hash function is perfect, the Speed should be O(1)
	int get(int key);

	// If the hash function is perfect, the Speed should be O(1)
	void put(int key, int value);


private:
	static int hash(int key);
};