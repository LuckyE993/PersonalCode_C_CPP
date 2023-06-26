//
// Created by Lucky_E on 2023-06-26.
//
#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* CreateTreeNode(int value)
{
    TreeNode* node = new TreeNode;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

TreeNode* Insert(TreeNode* root, int value)
{
    if(root == nullptr||root->data == value)
    {
        return CreateTreeNode(value);
    }

    if(root->data < value)
    {
        root->left = Insert(root->left, value);
    }
    else if(root->data > value)
    {
        root->right = Insert(root->right, value);
    }
    return root;
}

TreeNode* SearchNode(TreeNode* root, int value)
{
    if(root == nullptr||root->data == value)
    {
        return root;
    }

    if(root->data < value)
    {
        return SearchNode(root->right, value);
    }
    else if(root->data > value)
    {
        return SearchNode(root->left, value);
    }
}

TreeNode* DeleteNode(TreeNode* root,int value)
{
    if(root == nullptr)
    {
        return root;
    }

    if(value > root->data)
    {
        root->right = DeleteNode(root,value);
    }
    else if (value < root->data)
    {
        root->left = DeleteNode(root,value);
    }
    else//找到要删除的节点
    {
        if(root->left == nullptr)
        {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr)
        {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* minRight = root->right;
        while(minRight -> left!= nullptr)
        {
            minRight = minRight->left;
        }

        root->data = minRight -> data;
        root->right = DeleteNode(root->right,minRight->data);

    }
}

void InorderTraversal(TreeNode* root)
{

    if(root == nullptr)
    {
        return;
    }
    InorderTraversal(root->left);
    cout<<root->data<<" ";
    InorderTraversal(root->right);

}

int main()
{
    TreeNode* root = nullptr;
    cout << "啊实打实的" << endl;
    cout<<"asdas撒旦大苏打撒旦"<<endl;
    cout<<"sadas十大地方"<<endl;
    int data;
    while(true)
    {
        cin>>data;
        if(data!=-1)
        {
            break;
        }
        root = Insert(root,data);
    }

    cout<<"中序遍历结果: "<<endl;
    InorderTraversal(root);
    cout<<endl;

    cout<<"输入要查询的节点: "<<endl;
    cin>>data;
    TreeNode* searchresult = SearchNode(root,data);
    if(searchresult == nullptr)
    {
        cout<<"节点"<<data<<"不在二叉排序树中"<<endl;
    }
    else
    {
        cout<<"节点"<<data<<"在二叉排序树中"<<endl;
    }

    cout<<"输入要删除的节点值："<<endl;
    cin>>data;
    root = DeleteNode(root,data);

    cout<<"中序遍历结果: "<<endl;
    InorderTraversal(root);
    cout<<endl;

    return 0;
}