#include <iostream>
#include "HashTables.h"

int main()
{
	HashTable table{};

	table.put(1, 1);
	table.put(2, 2);
	table.put(2, 3);

	std::cout << table.get(1) << "\n" << table.get(2) << std::endl;
	return 0;
}