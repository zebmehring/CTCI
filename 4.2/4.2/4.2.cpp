#include <vector>
#include <iostream>
#include <algorithm>
#include <vld.h>

template <class T>
class TreeNode
{
public:
	T data;
	TreeNode *left;
	TreeNode *right;

public:
	TreeNode::TreeNode(T val)
	{
		this->data = val;
		this->left = NULL;
		this->right = NULL;
	}

	void TreeNode::printInOrder()
	{
		if (this->left)		this->left->printInOrder();
		std::cout << this->data << std::endl;
		if (this->right)	this->right->printInOrder();
	}
};

template <typename T>
TreeNode<T>* makeMinimalTree(std::vector<T> data, int start, int end)
{
	if (end < start)	return NULL;
	int mid = (start + end) / 2;
	TreeNode<T>* btree = new TreeNode<T>(data.at(mid));
	btree->left = makeMinimalTree(data, start, mid-1);
	btree->right = makeMinimalTree(data, mid+1, end);
	return btree;
}

template <typename T>
void deleteTree(TreeNode<T>* root)
{
	if (root->left)
		deleteTree(root->left);
	if (root->right)
		deleteTree(root->right);
	delete root;
}

int main()
{
	std::vector<int> data;
	int x;
	while ((std::cin >> x) && x != 0)
		data.push_back(x);
	std::cout << std::endl;
	std::sort(data.begin(), data.end());
	TreeNode<int>* btree = makeMinimalTree(data, 0, data.size()-1);
	btree->printInOrder();
	deleteTree(btree);
	std::cin.get();
}