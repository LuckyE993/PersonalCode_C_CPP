//
// Created by Lucky_E on 2023-06-11.
//
#include <iostream>
#include <queue>

using namespace std;
//���ڵ��� 9
const int MAX_VERTICES = 9;

// ͼ���ڽӱ�洢�ṹ
struct Graph {
    int adj[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

    Graph(int vertices) : numVertices(vertices) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int v, int w) {
        adj[v][w] = 1;
        adj[w][v] = 1;
    }

    // ������ȱ���
    void DFS(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < numVertices; i++) {
            if (adj[v][i] && !visited[i]) {
                DFS(i, visited);
            }
        }
    }

    // ������ȱ���
    void BFS(int v) {
        bool visited[MAX_VERTICES] = {false};
        queue<int> q;
        visited[v] = true;
        q.push(v);

        while (!q.empty()) {
            v = q.front();
            cout << v << " ";
            q.pop();

            for (int i = 0; i < numVertices; i++) {
                if (adj[v][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main()
{
    bool visited[MAX_VERTICES] = {false};
    // ����һ������9�������ͼ
    Graph g(9);

    // ��ӱ�
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    g.addEdge(6, 5);
    g.addEdge(6, 7);
    g.addEdge(6, 8);
    g.addEdge(7, 8);

    int node_BFS,node_DFS;
    cout << "��ֱ�����BFS�ڵ��DFS�ڵ�"<<endl;
    cin>>node_BFS>>node_DFS;

    cout << "������ȱ������: ";
    g.BFS(node_BFS);
    cout << endl;

    cout << "������ȱ������: ";
    g.DFS(node_DFS, visited);
    cout<< endl;

    return 0;
}
