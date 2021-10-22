#include "HashTables.h"
#include <iostream>

HashTable::HashTable()
{
	m_HashTable.resize(TABLE_SIZE);
}


int HashTable::get(int key)
{
	int generatedArrayIndex = hash(key);
	std::list<m_HashItem>& items = m_HashTable[generatedArrayIndex];

	if (m_HashTable[generatedArrayIndex].empty())
		return -1;

	for (const auto& elem : items)
		if (elem.m_key == key)
			return elem.m_value;

	return -1;
}

void HashTable::put(int key, int value)
{
	int hashArrayIndex = hash(key);

	std::list<m_HashItem>& items = m_HashTable[hashArrayIndex];

	if (items.empty())
		std::cout << "No Collision\n";
	else
		std::cout << "Collision at Key: " << key << "\n";

	for (const auto& elem : items)
	{
		if (elem.m_key == key)
		{
			std::cout << "Item is already Inserted\n";
				return;
		}
	}


	items.push_back(m_HashItem{ key, value });
	std::cout << "Size of List is: " << items.size() << "\n";

}

int HashTable::hash(int key)
{
	return key % TABLE_SIZE;
}