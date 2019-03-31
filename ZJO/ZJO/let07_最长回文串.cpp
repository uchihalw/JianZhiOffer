/*
 * @file   let07_����Ĵ�.cpp
 * @date   2019.3.31.
 * @author GBW
 * @Description: ��֪һ��������Сд�ַ����ַ��������ø��ַ����е��ַ��������ɵ�������ַ�������
 
 * @Note:
 
 */
// version_1
/*
	1. �����ַ���ϣ������ͳ���ַ��������е��ַ�����
	2. ��������Ĵ�ż���ַ�����Ϊmax_length = 0;
	3. �����Ƿ������ĵ���flag = 0
	4. ����ÿһ���ַ����ַ���Ϊcount,
		��countΪż����max_length += count;
		��countΪ������max_length += count - 1,flag = 1
	5. ����������ַ����Ӵ�����: max_length + flag
*/
int longestPalindrome(string s)
{
	int char_map[128] = { 0 }; // �ַ���ϣ
	int max_length = 0;
	int flag = 0;
	for (int i=0; i<s.length();i++)
	{
		char_map[s[i]] ++;
	}

	for (int i = 0; i < 128; i++)
	{
		if (char_map[i] & 0x1)
		{
			max_length += char_map[i] - 1;
			flag = 1;
		}
		else
		{
			max_length += char_map[i];
		}
	}
	return max_length + flag;
}























