#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 有向图类
class DirectedGraph {
public:
    /**
     * @brief 构造函数
     *
     * @param[in] vertices 顶点数量
     */
    DirectedGraph(int vertices) : vertex_count(vertices)
    {
        adjacency_list.resize(vertices);
    }

    /**
     * @brief 添加一条有向边
     *
     * @param[in] source 源顶点
     * @param[in] destination 目标顶点
     */
    void addEdge(int source, int destination) {
        adjacency_list[source].push_back(destination);
    }

    /**
     * @brief 打印有向图的邻接表
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
     * @brief 寻找有向图中所有简单路径
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
     * @brief 递归查找简单路径的工具方法
     *
     * @param[in] start 起始顶点
     * @param[in] end 终止顶点
     * @param[in] visited 记录顶点是否被访问过的向量
     * @param[in] path 记录当前路径的链表
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
     * @brief 打印路径
     *
     * @param[in] path 要打印的路径链表
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
    cout << "请输入顶点数V和边数E: ";
    cin >> vertices >> edges;

    DirectedGraph graph(vertices);

    cout << "请输入边 (source destination):" << endl;
    for (int i = 0; i < edges; ++i) {
        int source, destination;
        cin >> source >> destination;
        graph.addEdge(source, destination);
    }

    cout << "图形结构:" << endl;
    graph.printGraph();

    cout << "所有路径:" << endl;
    graph.findAllSimplePaths();

    return 0;
}
