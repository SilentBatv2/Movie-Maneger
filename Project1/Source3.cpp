/*
#include<iostream>

void event1(int**& a, int x1, int y1, int x2, int y2)
{
	static int b = 0;
	b++;
	for (int i = x1; i < x2 + 1; i++)
		for (int j = y1; j < y2 + 1; j++)
			*(*(a+i)+j) = b;
}

bool event2(int**& a, int x1, int y1, int x2, int y2)
{
	if (a[x1][y1] == a[x2][y2])
		return true;
	else
		return false;
}

int main()
{
	int n, m, q, i, z, x1, y1, x2, y2;
	std::cin >> n >> m >> q;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	for (i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = 0;
	for (i = 0; i < q; i++)
	{
		std::cin >> z;
		std::cout << " ";
		std::cin >> x1;
		std::cout << " ";
		std::cin >> y1;
		std::cout << " ";
		std::cin >> x2;
		std::cout << " ";
		std::cin >> y2;
		if (z == 1)
			event1(a, x1, y1, x2, y2);

		else if (z == 2)
			if (event2(a, x1, y1, x2, y2))
				std::cout << "yes\n";
			else
				std::cout << "no\n";
		else
			std::cout << "invalid input\n";
	}

	std::cin.get();
}
*/