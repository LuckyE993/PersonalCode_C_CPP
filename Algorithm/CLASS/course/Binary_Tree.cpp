//
// Created by Lucky_E on 2023-06-29.
//
#include <iostream>
#include <queue>
using namespace std;
struct Tree_Node
{
    int data;
    Tree_Node* left;
    Tree_Node* right;
};

Tree_Node* createBinaryTree()
{
    int value;
    cin>>value;
    if(value==-1)
    {
        return nullptr;
    }
    else
    {
        Tree_Node* node = new Tree_Node;
        node->data = value;
        node->left = createBinaryTree();
        node->right = createBinaryTree();
        return node;
    }
}

void PrecedenceBinaryTree(Tree_Node* BinaryTree)
{
    if(BinaryTree==nullptr)
    {
        return;
    }
    else
    {
        cout<<BinaryTree->data<<" ";
        PrecedenceBinaryTree(BinaryTree->left);
        PrecedenceBinaryTree(BinaryTree->right);
    }
}

void Inorder(Tree_Node* BinaryTree)
{
    if(BinaryTree==nullptr)
    {
        return;
    }
    else
    {
        cout<<BinaryTree->data<<" ";
        PrecedenceBinaryTree(BinaryTree->left);
        PrecedenceBinaryTree(BinaryTree->right);
    }
}

void Postorder(Tree_Node* BinaryTree)
{
    if(BinaryTree==nullptr)
    {
        return;
    }
    else
    {
        cout<<BinaryTree->data<<" ";
        PrecedenceBinaryTree(BinaryTree->left);
        PrecedenceBinaryTree(BinaryTree->right);
    }
}

void HierarchicalOrder(Tree_Node* BinaryTree)
{
    if(BinaryTree==nullptr)
    {
        return;
    }
    else
    {
        queue<Tree_Node*> nodeQueue;
        nodeQueue.push(BinaryTree);
        while(!nodeQueue.empty())
        {
            Tree_Node* node = nodeQueue.front();
            nodeQueue.pop();

            cout<<node->data<<" ";
            if(node->left!= nullptr)
            {
                nodeQueue.push(node->left);
            }
            if(node->right!= nullptr)
            {
                nodeQueue.push(node->right);
            }


        }
    }
}

int main()
{
    cout << "������������Ľڵ����ݣ�-1��ʾ���ӽڵ�Ϊ�սڵ㣩��" << endl;
    Tree_Node* root = createBinaryTree();

    cout << "������������" << endl;
    PrecedenceBinaryTree(root);
    cout << endl;

    cout << "��α��������" << endl;
    HierarchicalOrder(root);
    cout << endl;

    return 0;
}