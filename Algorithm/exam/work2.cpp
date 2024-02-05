//
// Created by Lucky_E on 2023-06-15.
//
#include <iostream>

using namespace std;

// 二叉排序树节点结构
struct TreeNode {
    int data;           // 节点数据
    TreeNode* left;     // 左子节点指针
    TreeNode* right;    // 右子节点指针

    // 构造函数
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// 向二叉排序树插入节点
void insertNode(TreeNode*& root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
        return;
    }

    if (value < root->data) {
        insertNode(root->left, value);
    } else {
        insertNode(root->right, value);
    }
}

// 在二叉排序树中查找指定值的节点
TreeNode* searchNode(TreeNode* root, int value) {
    if (root == nullptr || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}

// 中序遍历二叉排序树
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;

    // 从用户输入插入节点
    int numNodes;
    cout << "请输入要插入的节点个数：";
    cin >> numNodes;

    cout << "请输入节点的值：" << endl;
    for (int i = 0; i < numNodes; ++i) {
        int value;
        cin >> value;
        insertNode(root, value);
    }

    // 中序遍历二叉排序树
    cout << "中序遍历结果: ";
    inorderTraversal(root);
    cout << endl;

    // 查找节点
    int targetValue;
    cout << "请输入要查找的节点值：";
    cin >> targetValue;

    TreeNode* result = searchNode(root, targetValue);
    if (result != nullptr) {
        cout << "找到节点 " << targetValue << endl;
    } else {
        cout << "未找到节点 " << targetValue << endl;
    }

    return 0;
}
