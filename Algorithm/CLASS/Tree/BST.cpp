//
// Created by LuckyE on 2024/9/4.
//
#include "iostream"

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{
	}
};

class BST
{
public:
	TreeNode* insert(TreeNode* root, int val);

	TreeNode* search(TreeNode* root, int val);

	void inorder(TreeNode* root);

	TreeNode* del(TreeNode* root, int val);

	TreeNode* findmin(TreeNode* root);
};

TreeNode* BST::insert(TreeNode* root, int val)
{
	if (!root)
		return new TreeNode(val);

	if (val >= root->val)
	{
		root->right = insert(root->right, val);
	}
	else
	{
		root->left = insert(root->left, val);
	}
	return root;
}

TreeNode* BST::search(TreeNode* root, int val)
{
	if (!root || root->val == val)
		return root;
	if (val > root->val)
	{
		root->right = search(root->right, val);
	}
	else
	{
		root->left = search(root->left, val);
	}
}

void BST::inorder(TreeNode* root)
{
	if (!root)
		return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

TreeNode* BST::del(TreeNode* root, int val)
{
	if (!root)
	{
		return nullptr;
	}
	else if (val < root->val)
	{
		root->left = del(root->left, val);
	}
	else if (val > root->val)
	{
		root->right = del(root->right, val);
	}
	else
	{
		// equal
		if (!root->left && !root->right)
		{
			delete (root);
			return nullptr;
		}
		//右节点为空，使其指向左子树
		if (!root->right)
		{
			TreeNode* temp = root->left;
			delete (root);
			return temp;
		}
		//左节点为空，指向右子树
		if (!root->left)
		{
			TreeNode* temp = root->right;
			delete (root);
			return temp;
		}
		//同时有两个节点
		TreeNode* min = findmin(root->right);
		root->val = min->val;
		root->right = del(root->right, min->val);
	}
	return root;
}

TreeNode* BST::findmin(TreeNode* root)
{
	while (root->left)
	{
		root = root->left;
	}
	return root;
}

int main()
{
	BST bst;
	TreeNode* root = nullptr;

	root = bst.insert(root, 5);
	root = bst.insert(root, 3);  // 插入值3
	root = bst.insert(root, 7);  // 插入值7
	root = bst.insert(root, 2);  // 插入值2
	root = bst.insert(root, 4);  // 插入值4
	root = bst.insert(root, 6);  // 插入值6
	root = bst.insert(root, 8);  // 插入值8

	cout << "root->val = " << root->val << endl;

	// 中序遍历并输出二叉搜索树中的所有节点值
	bst.inorder(root);  // 输出：2 3 4 5 6 7 8
	std::cout << std::endl;

	// 删除节点
	root = bst.del(root, 3);  // 删除值为3的节点
	bst.inorder(root);  // 输出：2 4 5 6 7 8
	std::cout << std::endl;

	root = bst.del(root, 7);  // 删除值为7的节点
	bst.inorder(root);  // 输出：2 4 5 6 8
	std::cout << std::endl;

	root = bst.del(root, 5);  // 删除值为5的节点
	bst.inorder(root);  // 输出：2 4 6 8
	std::cout << std::endl;
	return 0;
}