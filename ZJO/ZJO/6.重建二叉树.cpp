/*
 * @file   6.�ؽ�������.cpp
 * @date   2019.3.6.
 * @author GBW
 * @Description: ����ĳ��������ǰ���������������Ľ�����ؽ����ö�������
				 ���������ǰ���������������Ľ���������ظ�������
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
	// ǰ������ĵ�һ�������Ǹ�����ֵ
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;

	// ǰ������б�ͺ�������б�ֻ��һ��Ԫ��ʱ�����ظ�Ԫ��
	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw std::exception("Invalid input.");
	}

	// ������������ҵ�������ֵ,�������ȷ����������������
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;


	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("Invalid input.");

	int leftLength = rootInorder - startInorder;// ��������б����������Ŀ�ͷ
	int* leftPreorderEnd = startPreorder + leftLength;// ��������б����������Ľ�β
	if (leftLength > 0) // ����������
	{
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}

	if (leftLength < endPreorder - startPreorder) // ����������
	{
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder+1, endInorder);
	}

}