/*
 * @file   20.�������ľ���.cpp
 * @date   2019.4.2.
 * @author GBW
 * @Description: ���һ������������һ�����������ú���������ľ��� 
 
 * @Note:
 
 */
void MirrorRecursively(BinaryTreeNode* pNode)
{
	if (pNode == NULL)return;
	swap(pNode->left, pNode->right);
	MirrorRecursively(pNode->left);
	MirrorRecursively(pNode->right);
}


//ջ�ķǵݹ�
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