//
// Created by Lucky_E on 2023-06-11.
//
#include <iostream>
#include <queue>

using namespace std;

// �������ڵ�ṹ
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

// ����������
TreeNode* createBinaryTree() {
    int data;
    cin >> data;

    if (data == -1) {  // ����-1��ʾ�սڵ�
        return nullptr;
    }

    TreeNode* node = new TreeNode;
    node->data = data;
    node->left = createBinaryTree();
    node->right = createBinaryTree();

    return node;
}

// ����������ݹ飩����������ȷ��ʵ�ǰ�ڵ㣬Ȼ��ݹ�������������������������
void Precedence_traversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    Precedence_traversal(root->left);
    Precedence_traversal(root->right);
}

// ��α������ǵݹ飩��α��������ö��е�����ʵ�֡��Ӹ��ڵ㿪ʼ����ÿ���ڵ�������ӣ�Ȼ����Ӳ����ʣ�ͬʱ���������ӽڵ���ӣ�ֱ������Ϊ�ա�
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
    cout << "������������Ľڵ����ݣ�-1��ʾ���ӽڵ�Ϊ�սڵ㣩��" << endl;
    TreeNode* root = createBinaryTree();

    cout << "������������" << endl;
    Precedence_traversal(root);
    cout << endl;

    cout << "��α��������" << endl;
    Hierarchical_traversal(root);
    cout << endl;

    return 0;
}
//