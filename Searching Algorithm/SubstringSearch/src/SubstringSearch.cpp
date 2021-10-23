#include <iostream>

void search(const char* pattern, const char* text)
{
	std::size_t m = strlen(pattern);
	std::size_t n = strlen(text);

	for (int i = 0; i < n - m + 1; ++i)
	{
		int j{ 0 };
		for (j = 0; j < m; j++)
		{
			if (pattern[j] != text[i + j])
				break;
		}

		if (j == m)
			std::cout << "Pattern Found at index: " << i << "\n";
	}
}


int main()
{
	char pattern[] = "asd";
	char text[] = "This is a test";

	search(pattern, text);

	return 0;
}