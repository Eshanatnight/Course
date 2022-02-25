#include <iostream>
#include <cstdlib>

template<typename T>
void show(T data[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << data[i] << " ";
}


template<typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
bool isSorted(T data[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (data[i + 1] < data[i])
			return false;
	}
		
	return true;
}

// Fisher-Yates Algorithm
template<typename T>
void shuffle(T data[], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		auto j = (( rand() / RAND_MAX) * i);

		swap(data[i], data[j]);
	}
}


template<typename T>
void sort(T data[], int n)
{
	int counter(0);

	while (!isSorted(data, n))
	{
		counter++;
		shuffle(data, n);
	}

	std::cout << "Steps Required to Sort The array: " << counter << "\n";
}

int main()
{
	int data[] = { 1, 33, 65, 33, -11, 33 };
	int n = sizeof(data) / sizeof(data[0]);

	sort(data, n);
	show(data, n);

}