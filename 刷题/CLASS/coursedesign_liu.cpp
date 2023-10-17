#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ����ͼ��
class DirectedGraph {
public:
    /**
     * @brief ���캯��
     *
     * @param[in] vertices ��������
     */
    DirectedGraph(int vertices) : vertex_count(vertices)
    {
        adjacency_list.resize(vertices);
    }

    /**
     * @brief ���һ�������
     *
     * @param[in] source Դ����
     * @param[in] destination Ŀ�궥��
     */
    void addEdge(int source, int destination) {
        adjacency_list[source].push_back(destination);
    }

    /**
     * @brief ��ӡ����ͼ���ڽӱ�
     */
    void printGraph() const {
        for (int i = 0; i < vertex_count; ++i) {
            cout << "Vertex " << i << " :";
            for (const auto& dest : adjacency_list[i]) {
                cout << " -> " << dest;
            }
            cout << endl;
        }
    }

    /**
     * @brief Ѱ������ͼ�����м�·��
     */
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

    /**
     * @brief �ݹ���Ҽ�·���Ĺ��߷���
     *
     * @param[in] start ��ʼ����
     * @param[in] end ��ֹ����
     * @param[in] visited ��¼�����Ƿ񱻷��ʹ�������
     * @param[in] path ��¼��ǰ·��������
     */
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

    /**
     * @brief ��ӡ·��
     *
     * @param[in] path Ҫ��ӡ��·������
     */
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
