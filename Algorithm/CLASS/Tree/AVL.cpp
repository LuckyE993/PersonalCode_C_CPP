//
// Created by LuckyE on 2024/9/4.
//
#include "iostream"
#include "algorithm"

using namespace std;

struct TreeNode
{
	int val;
	int height = 0;
	TreeNode* left;
	TreeNode* right;

	explicit TreeNode(int x) : val(x),height(1), left(nullptr), right(nullptr)
	{
	}

};

class AVL
{
public:
	int height(TreeNode* root);

	int balancer(TreeNode* root);

	TreeNode* rotate_right(TreeNode* y);

	TreeNode* rotate_left(TreeNode* x);

	TreeNode* insert_node(TreeNode* root, int val);

	TreeNode* search_node(TreeNode* root, int val);

	TreeNode* delete_node(TreeNode* root, int val);

	void inorder(TreeNode* root);

private:
	TreeNode* findMin(TreeNode* root);
};

int AVL::height(TreeNode* root)
{
	return root ? root->height : 0;
}

int AVL::balancer(TreeNode* root)
{
	return root ? height(root->left)- height(root->right) : 0;
}

TreeNode* AVL::rotate_right(TreeNode* y)
{
	TreeNode* x = y->left;
	TreeNode* T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

TreeNode* AVL::rotate_left(TreeNode* x)
{
	TreeNode* y = x->right;
	TreeNode* T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}


TreeNode* AVL::insert_node(TreeNode* root, int val)
{
	if (!root)
	{
		return new TreeNode(val);
	}

	if (val > root->val)
	{
		root->right = insert_node(root->right, val);
	}
	else if (val < root->val)
	{
		root->left = insert_node(root->left, val);
	}
	else
	{
		return root;
	}

	root->height = 1 + max(height(root->left), height(root->right));

	int balance = balancer(root);

	if (balance > 1)
	{
		if (val < root->left->val)//左左
		{
			return rotate_right(root);
		}
		else
		{
			root->left = rotate_left(root->left);
			return rotate_right(root);
		}
	}
	if (balance < -1)
	{
		if (val > root->right->val)
		{
			return rotate_left(root);
		}
		else
		{
			root->right = rotate_right(root->right);
			return rotate_left(root);
		}
	}

	return root;

}

TreeNode* AVL::search_node(TreeNode* root, int val)
{
	if (!root || val == root->val)
		return root;
	if (val > root->val)
	{
		root->right = search_node(root->right, val);
	}
	if (val < root->val)
	{
		root->left = search_node(root->left, val);
	}
}

void AVL::inorder(TreeNode* root)
{
	if (!root)
		return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

TreeNode* AVL::delete_node(TreeNode* root, int val)
{
	if (!root)
	{
		return nullptr;
	}
	if (val > root->val)
	{
		root->right = delete_node(root->right, val);
	}
	else if (val < root->val)
	{
		root->left = delete_node(root->left, val);
	}
	else
	{
		if (!root->left && !root->right)
		{
			delete (root);
			return nullptr;
		}
		if (!root->left)
		{
			TreeNode* temp = root->right;
			delete (root);
			return temp;
		}
		if (!root->right)
		{
			TreeNode* temp = root->left;
			delete (root);
			return temp;
		}

		TreeNode* min_node = findMin(root->right);
		root->val = min_node->val;
		root->right = delete_node(root->right, min_node->val);
	}

	root->height = 1 + max(height(root->left), height(root->right));

	int balance = balancer(root);

	if (balance > 1)
	{
		if (val < root->left->val)//左左
		{
			return rotate_right(root);
		}
		else
		{
			root->left = rotate_left(root->left);
			return rotate_right(root);
		}
	}
	if (balance < -1)
	{
		if (val > root->right->val)
		{
			return rotate_left(root);
		}
		else
		{
			root->right = rotate_right(root->right);
			return rotate_left(root);
		}
	}

	return root;

}

TreeNode* AVL::findMin(TreeNode* root)
{
	while (root->left)
	{
		root = root->left;
	}
	return root;
}

int main()
{
	AVL avl;  // 创建 AVL 树对象
	TreeNode* root = nullptr;

	// 插入节点
	root = avl.insert_node(root, 10);
	root = avl.insert_node(root, 20);
	root = avl.insert_node(root, 30);
	root = avl.insert_node(root, 40);
	root = avl.insert_node(root, 50);
	root = avl.insert_node(root, 25);

	// 中序遍历并输出 AVL 树中的所有节点值
	std::cout << "Inorder traversal of AVL tree: ";
	avl.inorder(root);  // 输出：10 20 25 30 40 50
	std::cout << std::endl;

	// 删除节点
	std::cout << "Deleting 30...\n";
	root = avl.delete_node(root, 30);  // 删除值为 30 的节点
	std::cout << "Inorder traversal after deletion: ";
	avl.inorder(root);  // 输出：10 20 25 40 50
	std::cout << std::endl;

	return 0;

	return 0;
}