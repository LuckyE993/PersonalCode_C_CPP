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

    if(root->data > value)
    {
        root->left = Insert(root->left, value);
    }
    else if(root->data < value)
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

    if(root->data > value)
    {
        return SearchNode(root->right, value);
    }
    else if(root->data < value)
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
    else
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
        TreeNode* minRightParent = nullptr;

        while (minRight->left != nullptr)
        {
            minRightParent = minRight;
            minRight = minRight->left;
        }

        if (minRightParent != nullptr)
        {
            minRightParent->left = minRight->right;
        }
        else
        {
            root->right = minRight->right;
        }

        root->data = minRight->data;
        delete minRight;

    }
    return root;
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

    cout<<"请输入二叉排序树的元素，以-1结束"<<endl;

    int data;
    while(true)
    {
        cin>>data;
        if(data==-1)
        {
            break;
        }
        root = Insert(root,data);
    }

    cout<<"中序遍历结果: "<<endl;
    InorderTraversal(root);
    cout<<endl;

    cout<<"请输入要搜索的节点"<<endl;
    cin>>data;
    TreeNode* searchresult = SearchNode(root,data);
    if(searchresult == nullptr)
    {
        cout<<"节点"<<data<<"搜索失败"<<endl;
    }
    else
    {
        cout<<"节点"<<data<<"搜索成功"<<endl;
    }

    cout<<"请输入要删除的节点"<<endl;
    cin>>data;
    root = DeleteNode(root,data);

    cout<<"中序遍历结果: "<<endl;
    InorderTraversal(root);
    cout<<endl;

    return 0;
}