#include <iostream>
#include <string>

void constructTable(const std::string& s, int* table)
{
	table[0] = 0;

	int left = 0;
	int right = 0;

	for (int k = 1; k < s.length(); k++)
	{
		if (k > right)
		{
			int n = 0;
			while (n + k < s.length() && s[n] == s[n + k])
				n++;

			table[k] = n;

			if (n > 0)
			{
				left = k;
				right = k + n - 1;
			}
		}

		else
		{
			int p = k - left;
			if (table[p] < right - k + 1)
				table[k] = table[p];
			else
			{
				int i = right + 1;
				while (i < s.length() && s[i] == s[i - k])
					i++;
				table[k] = i - k;
				left = k;
				right = i - 1;
			}
		}
	}
}




void search(const std::string& pattern, const std::string& text)
{
	// WE CONCAT THE TXT AND PATTERN
	std::string s = pattern + text;


	// ZTable
	int table[s.length()];
	constructTable(s, table);
	bool flag = true;
	// Now consider the ZTable
	for (int i = 0; i < s.length(); i++)
	{
		if (table[i] >= pattern.length())
		{
			std::cout << "Pattern found at Index: " << i - pattern.length() << "\n";
			flag = false;
		}
	}
	if(flag)
		std::cout << "Pattern not found\n";
}


int main()
{
	char pattern[] = "testyy";
	char text[] = "this is a test";

	search(pattern, text);
	return 0;
}