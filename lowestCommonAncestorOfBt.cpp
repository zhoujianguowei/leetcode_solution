#include"leetcode.h"
bool getPath(TreeNode *root, TreeNode *p, vector<TreeNode*>& path)
{
	if (root == NULL || p == NULL)
		return false;
	if (root == p)
	{
		path.push_back(p);
		return true;
	}
	path.push_back(root);
	if (!getPath(root->left, p, path) && (!getPath(root->right, p, path)))
	{
		vector<TreeNode*>::iterator end = path.end();
		end--;
		path.erase(end);
	}
	else
		return true;
	return false;

}
/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: ��The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).��
_______3______
/              \
___5__          ___1__
/      \        /      \
6      _2       0       8
/  \
7   4


For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == NULL)
		return root;
	if (p == NULL)
		return q;
	if (q == NULL)
		return p;
	vector<TreeNode*> pP;
	vector<TreeNode *>qP;
	getPath(root, p, pP);
	getPath(root, q, qP);
	set<TreeNode *> tree_set;
	unsigned int i = 0;
	for (; i < pP.size(); i++)
		tree_set.insert(pP[i]);
	i = qP.size() - 1;
	for (; i >= 0; i--)
	{
		if (tree_set.find(qP[i]) != tree_set.end())
			return qP[i];
	}
	return root;
}
