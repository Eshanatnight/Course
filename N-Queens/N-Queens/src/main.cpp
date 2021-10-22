#include "nQueens.hpp"
#include <iostream>

int main()
{
	QueenProblem QueenProblem1{ 8 };
	QueenProblem1.solve();
	std::cin.get();
	return 0;
}