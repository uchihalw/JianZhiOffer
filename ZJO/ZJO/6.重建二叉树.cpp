/*
 * @file   6.重建二叉树.cpp
 * @date   2019.3.6.
 * @author GBW
 * @Description: 输入某二叉树的前序遍历和中序遍历的结果，重建出该二叉树。
				 假设输入的前序遍历和中序遍历的结果都不含重复的数字
				 Preorder =[1,2,4,7,3,5,6,8]
				 Inorder  =[4,7,2,1,5,3,8,6]
 * @Note:
 
 */
struct BinaryTreeNode
{
	int              m_nValue;
	BinaryTreeNode*  m_pLeft;
	BinaryTreeNode*  m_pRight;
};

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	// 前序遍历的第一个数字是根结点的值
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;

	// 前序遍历列表和后序遍历列表只有一个元素时，返回该元素
	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw std::exception("Invalid input.");
	}

	// 在中序遍历中找到根结点的值,因而可以确定左右子树的数量
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;


	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("Invalid input.");

	int leftLength = rootInorder - startInorder;// 中序遍历列表中左子树的开头
	int* leftPreorderEnd = startPreorder + leftLength;// 中序遍历列表中左子树的结尾
	if (leftLength > 0) // 构建左子树
	{
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}

	if (leftLength < endPreorder - startPreorder) // 构建右子树
	{
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder+1, endInorder);
	}

}