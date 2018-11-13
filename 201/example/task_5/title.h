#ifndef TITLE_H_INCLUDED
#define TITLE_H_INCLUDED

#include <iostream>
#include <graphics.h>
#include <windows.h>

using std::cout;
using std::endl;
using std::cin;

struct Node
{
    int x;
    int y;
    bool visited;
};

//������ � �������
void DFS(bool** matrix, Node* graph, int vertex);

//������ � ������
void BFS(bool** matrix, Node* graph, int vertex);

void clear(Node* graph);


#endif // !TITLE_H_INCLUDED
