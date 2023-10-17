#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    int id;
};

struct Edge {
    int from;
    int to;
    int weight;
};

class WeightedGraph {
private:
    std::vector<Node> nodes;
    std::vector<Edge> edges;

public:
    // 插入节点
    void insertNode(int nodeId) {
        nodes.push_back({ nodeId });
    }

    // 删除节点及相关边
    void deleteNode(int nodeId) {
        // 删除节点
        nodes.erase(std::remove_if(nodes.begin(), nodes.end(), [nodeId](const Node& node) {
            return node.id == nodeId;
        }), nodes.end());

        // 删除与节点相关的边
        edges.erase(std::remove_if(edges.begin(), edges.end(), [nodeId](const Edge& edge) {
            return edge.from == nodeId || edge.to == nodeId;
        }), edges.end());
    }

    // 插入边
    void insertEdge(int fromNode, int toNode, int weight) {
        edges.push_back({ fromNode, toNode, weight });
    }

    // 删除边
    void deleteEdge(int fromNode, int toNode) {
        edges.erase(std::remove_if(edges.begin(), edges.end(), [fromNode, toNode](const Edge& edge) {
            return edge.from == fromNode && edge.to == toNode;
        }), edges.end());
    }

    // 显示图
    void displayGraph() {
        std::cout << "Nodes:" << std::endl;
        for (const auto& node : nodes) {
            std::cout << node.id << std::endl;
        }
        std::cout << "Edges:" << std::endl;
        for (const auto& edge : edges) {
            std::cout << edge.from << " -> " << edge.to << " (weight: " << edge.weight << ")" << std::endl;
        }
    }
};

int main() {
    WeightedGraph graph;

    // 根据输入数据生成带权图
    std::vector<Node> inputNodes = { {1}, {2}, {3}, {4}, {5} };
    std::vector<Edge> inputEdges = { {1, 2, 1}, {1, 3, 2}, {2, 4, 3}, {3, 4, 4}, {3, 5, 5} };

    // 插入初始节点
    for (const auto& node : inputNodes) {
        graph.insertNode(node.id);
    }

    // 插入初始边
    for (const auto& edge : inputEdges) {
        graph.insertEdge(edge.from, edge.to, edge.weight);
    }

    // 输出初始状态
    graph.displayGraph();

    // 插入节点
    graph.insertNode(6);
    graph.insertNode(7);

    // 插入边
    graph.insertEdge(4, 6, 2);
    graph.insertEdge(5, 7, 3);

    // 删除节点及相关边
    graph.deleteNode(3);

    // 删除边
    graph.deleteEdge(1, 2);

    // 输出最终状态
    graph.displayGraph();

    return 0;
}
