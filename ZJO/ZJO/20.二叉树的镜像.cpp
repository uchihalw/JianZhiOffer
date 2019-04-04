/*
 * @file   20.二叉树的镜像.cpp
 * @date   2019.4.2.
 * @author GBW
 * @Description: 完成一个函数，输入一个二叉树，该函数输出它的镜像 
 
 * @Note:
 
 */
void MirrorRecursively(BinaryTreeNode* pNode)
{
	if (pNode == NULL)return;
	swap(pNode->left, pNode->right);
	MirrorRecursively(pNode->left);
	MirrorRecursively(pNode->right);
}


//栈的非递归
void Mirror(TreeNode *pRoot) {
	if (pRoot == NULL)return;
	stack<TreeNode*> st;
	TreeNode* p = NULL;
	st.push(pRoot);
	while (st.size())
	{
		p = st.top();
		st.pop();
		swap(p->left, p->right);
		if (p->left) st.push(p->left);
		if (p->right) st.push(p->right);
	}
}