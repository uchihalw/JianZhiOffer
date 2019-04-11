/*
* @file   
* @date   2019.4.11.
* @author GBW
* @Description: 

* @Note:

*/
void leftView(TreeNode* root, queue<TreeNode*> & que, int level)
{
	if (root == NULL)
		return;
	if (que.size() == level)
		que.push(root);
	leftView(root->left, que, level + 1);
	leftView(root->right, que, level + 1);
}
void rightView(TreeNode* root, queue<TreeNode*> & que, int level)
{
	if (root == NULL)
		return;
	if (que.size() == level)
		que.push(root);
	rightView(root->right, que, level + 1);
	rightView(root->left, que, level + 1);

}
void view(TreeNode* root)
{
	if (root == NULL)
		return;
	queue<TreeNode*> que_left;
	queue<TreeNode*> que_right;
	int level = 0;
	leftView(root, que_left, level);
	while (!que_left.empty())
	{
		cout << que_left.front()->val << endl;
		que_left.pop();
	}

	rightView(root, que_right, level);
	while (!que_right.empty())
	{
		cout << que_right.front()->val << endl;
		que_right.pop();
	}

}
