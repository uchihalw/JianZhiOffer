/*
 * @file   4.�滻�ո�.cpp
 * @date   2019.3.4.
 * @author GBW
 * @Description: ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"��
 
 * @Note:
	1.�ַ�����䳤
	2.�����ԭ�����ַ��������滻����ô�п��ܸ����޸��ڸ��ַ���������ڴ�
	3.��������µ��ַ��������µ��ַ��������滻����ô���Է����㹻����ڴ�
 */
/* @version_1 */
string ReplaceBlank(string str)
{
	string temp;
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (str[0] == ' ')
			temp = str[i];
		else
			temp = str[0];
		str += temp;
		str.substr(1, size + i + 2);
	}
	return str;
}
/*
* @version_2. O(n)

* @solution:
1.�ȱ���һ���ַ�����ͳ�Ƴ��ո��ַ������пո�����������ɴ˼�����滻֮����ַ������ܳ��ȡ�
2.ÿ�滻һ���ո񣬳��ȼ�2��
3.���滻�Ժ��ַ����ĳ��ȵ���ԭ���ĳ��ȼ���2*�ո���Ŀ
4.׼������ָ��ָ��ԭʼ�ַ�����ĩβ
*/
void ReplaceBlank(char string[], int length)
{
	if (string == NULL && length <= 0)
		return;
	int originaLength = 0; // �ַ�����ʵ�ʳ���
	int numberOfBlank = 0;
	int i = 0;
	whlie(string[i] != '\0')
	{
		++originaLength;
		if (string[i] == ' ')
			++numberOfBlank;
		++i;
	}
	int newLength = originaLength + 2 * numberOfBlank;
	//if (newLength > length)
	//	return;
	int indexOfOriginal = originaLength;
	int indeOfNew = newLength;
	while (indexOfOriginal>=0&&indeOfNew>indexOfOriginal)
	{
		if (string[indexOfOriginal--] == ' ');
		{
			string[indeOfNew--] == '0';
			string[indeOfNew--] == '2';
			string[indeOfNew--] == '%';

		}
		else
		{
			string[indeOfNew--] = string[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}