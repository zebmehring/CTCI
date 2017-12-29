#include <forward_list>
#include <vector>
#include <iostream>

template <typename T>
struct TreeNode
{
	T data;
	TreeNode *left;
	TreeNode *right;
	TreeNode::TreeNode(T val) : data(val), left(NULL), right(NULL) {};
};

template <typename T>
void deleteTree(TreeNode<T>* root)
{
	if (root->left)
		deleteTree(root->left);
	if (root->right)
		deleteTree(root->right);
	delete root;
}

template <typename T>
void makeTreeList(TreeNode<T> *root, std::vector<std::forward_list<T>> result, int level)
{
	if (!root) return;

	std::forward_list<T> currentLevel;
	if (result.size() == level)
	{
		result.push_front(currentLevel);
	}
	else
	{
		currentLevel = result.at(level);
	}
	currentLevel.push_front(root->data);
	makeTreeList(root->left, result, level + 1);
	makeTreeList(root->right, result, level + 1);
}

template <typename T>
std::vector<std::forward_list<T>> makeTreeList(TreeNode<T> *root)
{
	std::vector<std::forward_list<T>> result;
	makeTreeList(root, result, 0);
	return result;
}