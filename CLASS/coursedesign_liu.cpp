//
// Created by Lucky_E on 2023-06-30.
//
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ����ͼ��
class DirectedGraph {
public:
    DirectedGraph(int vertices) : vertex_count(vertices)//����
    {
        adjacency_list.resize(vertices);
    }

    // ���һ����
    void addEdge(int source, int destination) {
        adjacency_list[source].push_back(destination);
    }

    // ��ӡ�ڽӱ�
    void printGraph() const {
        for (int i = 0; i < vertex_count; ++i) {
            cout << "Vertex " << i << " :";
            for (const auto& dest : adjacency_list[i]) {
                cout << " -> " << dest;
            }
            cout << endl;
        }
    }

    // Ѱ�����м�·��
    void findAllSimplePaths() {
        for (int i = 0; i < vertex_count; ++i) {
            for (int j = 0; j < vertex_count; ++j) {
                if (i != j) {
                    list<int> path;
                    vector<bool> visited(vertex_count, false);
                    findSimplePathsUtil(i, j, visited, path);
                }
            }
        }
    }

private:
    int vertex_count;
    vector<list<int>> adjacency_list;

    // �ݹ���Ҽ�·���Ĺ��߷���
    void findSimplePathsUtil(int start, int end, vector<bool>& visited, list<int>& path) {
        visited[start] = true;
        path.push_back(start);

        if (start == end) {
            printPath(path);
        }
        else {
            for (const auto& neighbor : adjacency_list[start]) {
                if (!visited[neighbor]) {
                    findSimplePathsUtil(neighbor, end, visited, path);
                }
            }
        }

        visited[start] = false;
        path.pop_back();
    }

    // ��ӡ·��
    void printPath(const list<int>& path) const {
        for (const auto& vertex : path) {
            cout << vertex << " ";
        }
        cout << endl;
    }
};

int main() {
    int vertices, edges;
    cout << "�����붥����V�ͱ���E: ";
    cin >> vertices >> edges;

    DirectedGraph graph(vertices);

    cout << "������� (source destination):" << endl;
    for (int i = 0; i < edges; ++i) {
        int source, destination;
        cin >> source >> destination;
        graph.addEdge(source, destination);
    }

    cout << "ͼ�νṹ:" << endl;
    graph.printGraph();

    cout << "����·��:" << endl;
    graph.findAllSimplePaths();

    return 0;
}