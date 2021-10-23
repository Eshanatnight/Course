// Knuth-Morris-Pratt_Algorithm.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <cstring>

using namespace std;

// Partial Match Table
void constructPITable(const char* pattern, int* table)
{
	size_t m = strlen(pattern);
	table[0] = 0;

	int prefixCounter = 0;
	int i = 1;

	while (i < m)
	{
		if (pattern[i] == pattern[prefixCounter])
		{
			//prefixCounter++;
			table[i] = ++prefixCounter;
			i++;
		}

		else
		{
			if (prefixCounter != 0)
				prefixCounter = table[prefixCounter - 1];
			else
			{
				table[i] = 0;
				i++;
			}
		}

	}
}

void search(const char* pattern, const char* text)
{
	size_t m = strlen(pattern);
	size_t n = strlen(text);

	int table[6];
	constructPITable(pattern, table);

	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (pattern[j] == text[i])
		{
			i++;
			j++;
		}

		if (j == m)
		{
			cout << "Pattern Found at index: " << i - j << endl;
			j = table[j - 1];
		}

		else if (i < n && text[i] != pattern[j])
		{
			if (j != 0)
				j = table[j - 1];
			else
				i++;
		}
	}


}


int main()
{
	char pattern[] = "aabbha";
	char text[] = "agagiusdaabbhaguigdyuafe";

	search(pattern, text);

	return 0;
}
