#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <chrono>

#include "roy_floyd.h"

using namespace std;
using namespace std::chrono;

int main()

{
	char ch;
	int x, y, n, m;
	vector< vector<int>> cost;
	vector< vector<int>> matrice_in;

	try {
		for (int i = 1; i < 12; i++)
		{

			initial_cost(cost, n, m, i);

			matrice_in = cost;

			//printf("\n The weight matrix is:\n");
			//display_matrix(cost, n);
			cout << "N = " << n << endl;

			auto start1 = high_resolution_clock::now();

			roy_floyd(cost, n);

			auto stop1 = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop1 - start1);

			cout << "\t Time taken by function: " << duration.count() << " microseconds ~ " << duration.count() / 1000 << " milliseconds ~ " << duration.count() / 1000000 << " seconds " << endl;


			//printf("\n The minimum cost matrix is:\n");
			//display_matrix(cost, n);

			/*for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (matrice_in[i][j] != cost[i][j])
					{
						printf("\n The path from %d to %d has the weight %d", i, j, cost[i][j]);
						printf("\n The minimum cost path is: %d  ", i);
						compute_path(i, j, n, cost);
					}
				}
			}

			do
			{
				printf("\n\nDetermine which is the minimum cost path between two nodes of the graph\n");
				printf("x= ");
				scanf_s("%d", &x);

				printf("y= ");
				scanf_s("%d", &y);
				print_path(x-1, y-1, cost, n);

				printf("\n\n\n Do you want to find a path between other nodes from the graph? <y/n>");
				ch = _getch();
			} while (ch == 'y' || ch == 'Y');*/
		}
		_getch();
	}
	catch (exception e)
	{

	}

	return 0;
}
