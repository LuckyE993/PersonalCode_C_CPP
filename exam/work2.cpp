//
// Created by Lucky_E on 2023-06-15.
//
#include <iostream>

using namespace std;

// �����������ڵ�ṹ
struct TreeNode {
    int data;           // �ڵ�����
    TreeNode* left;     // ���ӽڵ�ָ��
    TreeNode* right;    // ���ӽڵ�ָ��

    // ���캯��
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// ���������������ڵ�
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

// �ڶ����������в���ָ��ֵ�Ľڵ�
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

// �����������������
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;

    // ���û��������ڵ�
    int numNodes;
    cout << "������Ҫ����Ľڵ������";
    cin >> numNodes;

    cout << "������ڵ��ֵ��" << endl;
    for (int i = 0; i < numNodes; ++i) {
        int value;
        cin >> value;
        insertNode(root, value);
    }

    // �����������������
    cout << "����������: ";
    inorderTraversal(root);
    cout << endl;

    // ���ҽڵ�
    int targetValue;
    cout << "������Ҫ���ҵĽڵ�ֵ��";
    cin >> targetValue;

    TreeNode* result = searchNode(root, targetValue);
    if (result != nullptr) {
        cout << "�ҵ��ڵ� " << targetValue << endl;
    } else {
        cout << "δ�ҵ��ڵ� " << targetValue << endl;
    }

    return 0;
}
