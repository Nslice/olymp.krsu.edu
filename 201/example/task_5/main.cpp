#include "title.h"
#include <queue>
#include <fstream>


const int N = 15;

int line_y; //координата вывода цифр

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "");
    initwindow(1050, 550, "MY_window");


    bool** arr = new bool*[N];
    for(int i = 0; i < N; i++)
        arr[i] = new bool[N] {};



    //заполнение матрицы единицами из файла:
    std::ifstream in;
    in.open("edge.txt.");
    if (!in.is_open())
    {
        cout << "can not open input file\n";
        return 1;
    }

    int one, two;
    while (!in.eof())
    {
        in >> one >> two;
        arr[one-1][two-1]=arr[two-1][one-1] = true;
    }
    in.close();
    //---------------------------------------


    Node* graph = new Node[N];

    //заполнения координатами вершин из файла:
    in.open("coord.txt");
    if (!in.is_open())
    {
        cout << "can not open input file\n";
        return 1;
    }

    int num;
    while(!in.eof())
    {
        in >> num >> one >> two;
        graph[num-1].x = one;
        graph[num-1].y = two;
        graph[num-1].visited = false;
    }
    in.close();
    //---------------------------------------


    setcolor(WHITE);
    setbkcolor(BLACK);

    //отрисовка ребер:
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(arr[i][j] == true)
                line(graph[i].x, graph[i].y, graph[j].x, graph[j].y);



    //отрисовка вершин:
    setfillstyle(0, WHITE);

    char ch[5]; //sprintf и outtextxy принимают указатель на char
    for(int i = 0; i < N; i++)
    {
        sprintf(ch, "%d", i + 1);
        fillellipse(graph[i].x, graph[i].y, 20, 20);
        outtextxy(graph[i].x - 8, graph[i].y + 10 - 20, ch);
    }


    int choice, vertex;

    while (true)
    {
        line_y = 70;

        setfillstyle(0, BLACK);
        bar(990, 50, 1020, 500);

        cout << "1 - в глубину,  2 - в ширину, 3 - выход из цикла\n";
        cin >> choice;
        if (choice == 3)
            break;
        cout << "Вершина с которой начать обход графа 1-15\n";
        cin >> vertex;


        if (choice == 1)
        {
            DFS(arr, graph, vertex - 1);
        }
        else if (choice == 2)
        {
            BFS(arr, graph, vertex - 1);
        }
        else
            continue;


        clear(graph);
        cout << "Enter для повтора";
        cin.get();
        cin.get();
    }




    delete[] graph;

    for(int i = 0; i < N ; i++)
        delete[] arr[i];
    delete[] arr;


    cout << "END\n";
    closegraph();
    return 0;
}


void DFS(bool** matrix, Node* graph, int vertex)
{
    setcolor(WHITE);
    char ch[5];
    sprintf(ch, "%d", vertex + 1);
    outtextxy(1000, line_y, ch);
    line_y += 20;

    graph[vertex].visited = true;

    circle(graph[vertex].x, graph[vertex].y, 30);
    delay(1000);
    setcolor(BLACK);
    circle(graph[vertex]. x,graph[vertex].y, 30);

    for(int i = 0; i < N; i++)
    {
        if(matrix[vertex][i] == true && graph[i].visited == false)
        {
            circle(graph[vertex].x, graph[vertex].y, 30);
            DFS(matrix, graph, i);
        }
    }

}

void BFS(bool** matrix, Node* graph, int vertex)
{
    std::queue<int> que;

    char ch[5];
    setcolor(WHITE);
    sprintf(ch, "%d ", vertex + 1);
    outtextxy(1000, line_y, ch);
    line_y += 20;

    circle(graph[vertex].x, graph[vertex].y, 30);
    delay(1000);
    setcolor(BLACK);
    circle(graph[vertex].x, graph[vertex].y, 30);

    que.push(vertex);
    graph[vertex].visited = true;

    for(int i = 0; i < N; i++)
        if(matrix[vertex][i] == true && graph[i].visited == false)
            que.push(i);
    que.pop();

    int tmp;
    while(!que.empty())
    {
        setcolor(WHITE);
        tmp = que.front();
        sprintf(ch, "%d ", tmp + 1);
        outtextxy(1000, line_y, ch);
        line_y += 20;

        que.pop();
        graph[tmp].visited = true;
        circle(graph[tmp].x, graph[tmp].y, 30);


        for(int i = 0; i < N; i++)
        {
            if(matrix[tmp][i] == true && graph[i].visited == false)
            {
                que.push(i);
                graph[i].visited = true;
            }
        }
        delay(1000);
        setcolor(BLACK);
        circle(graph[tmp].x, graph[tmp].y, 30);
    }


}

void clear(Node* graph)
{
    for (int i = 0; i < N; i++)
        graph[i].visited = false;
}
