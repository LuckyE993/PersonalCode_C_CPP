//
// Created by Lucky_E on 2023-06-11.
//
#include <iostream>
#include <queue>

using namespace std;

// 二叉树节点结构
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

// 创建二叉树
TreeNode* createBinaryTree() {
    int data;
    cin >> data;

    if (data == -1) {  // 输入-1表示空节点
        return nullptr;
    }

    TreeNode* node = new TreeNode;
    node->data = data;
    node->left = createBinaryTree();
    node->right = createBinaryTree();

    return node;
}

// 先序遍历（递归）先序遍历，先访问当前节点，然后递归地先序遍历左子树和右子树。
void Precedence_traversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    Precedence_traversal(root->left);
    Precedence_traversal(root->right);
}

// 层次遍历（非递归）层次遍历，利用队列的特性实现。从根节点开始，将每个节点依次入队，然后出队并访问，同时将其左右子节点入队，直到队列为空。
void Hierarchical_traversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        cout << node->data << " ";

        if (node->left != nullptr) {
            nodeQueue.push(node->left);
        }

        if (node->right != nullptr) {
            nodeQueue.push(node->right);
        }
    }
}

int main() {
    cout << "请输入二叉树的节点数据（-1表示其子节点为空节点）：" << endl;
    TreeNode* root = createBinaryTree();

    cout << "先序遍历结果：" << endl;
    Precedence_traversal(root);
    cout << endl;

    cout << "层次遍历结果：" << endl;
    Hierarchical_traversal(root);
    cout << endl;

    return 0;
}
//