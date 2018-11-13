#include <iostream>
using namespace std;

/*
	1 2    5
	1 4   10
	2 3    6
	2 4    5
	3 4    8
*/


const int N = 4; //vertex                                         
const int M = 5; //edge

int listEdge[M * 2][3];
bool matrix[N][N]{};

int edges[M]{};
int graph[N]{};


void DFS(int vertex = 0)
{
	graph[vertex]++;

	for (int i = 0; i < N; i++)
	{
		if (matrix[vertex][i] == true && graph[i] < 2)
		{

		}
	}
}

int main()
{
	int v1, v2, weight;
	for (int i = 0; i < M * 2; i += 2)
	{
		cin >> v1 >> v2 >> weight;

		listEdge[i][0] = v1;
		listEdge[i][1] = v2;
		listEdge[i][2] = weight;
		
		listEdge[i + 1][0] = v2;
		listEdge[i + 1][1] = v1;
		listEdge[i + 1][2] = weight;

		matrix[v1 - 1][v2 - 1] = matrix[v2 - 1][v1 - 1] = true;
	}

	cout << endl << endl;

	for (int i = 0; i < M * 2; i++)
	{
		cout << i + 1 << ") ";
		for (int j = 0; j < 3; j++)
			cout << listEdge[i][j] << " ";

		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < N; i++)
	{
		for (int  j = 0; j < N; j++)
			cout << matrix[i][j] << " ";
		
		cout << endl;
	}




	



	return 0;
}