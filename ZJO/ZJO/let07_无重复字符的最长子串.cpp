/*
 * @file   let07_���ظ��ַ�����Ӵ�.cpp
 * @date   2019.3.31.
 * @author GBW
 * @Description: ��֪һ���ַ��������ø��ַ��������ظ��ַ�����Ӵ��ĳ���
 
 * @Note:
 
 */
// version_1. ���ڻ���˫ָ��ɨ��
/*
	1.����һ����¼�ַ��������ַ���ϣ��char_map
	2.����һ����¼��ǰ������������Ӵ�����word
	3.��������ָ��ָ���ַ�����һ���ַ�
	4.����������������Ӵ��ĳ���result
	5.iָ��������ɨ���ַ����е��ַ�������������У�ʹ��char_map��¼�ַ�����
		���word���Ǹ�û���ֹ����ַ�:��wordβ������ַ������result�Ƿ���Ҫ����
		����:beginָ����ǰ�ƶ�������char_map�е��ַ�������ֱ���ַ�s[i]������Ϊ1������word����word��ֵΪbegin��i֮����Ӵ�
	6.���������У�ʹ��begin��iά��һ�����ڣ��ô����е��Ӵ�������Ŀ����������������ǰ����������ʱ�临�Ӷ�ΪO(n)
*/
int lengthOfLongSubString(string s)
{
	int begin = 0;
	int result = 0;
	string word = "";
	int char_map[128] = { 0 };
	for (int i = 0; i < s.length(); i++)
	{
		char_map[s[i]]++;
		if (char_map[s[i]] == 1) // workd��û���ֹ����ַ�
		{
			word += s[i];
			if (result < word.length())
				result = word.length();
		}
		else //���ظ����ַ�s[i]ɾȥ
		{
			while (begin < i && char_map[s[i]] > 1)
			{
				char_map[s[begin]] --;
				begin++;
			}
			word = "";
			for (int j = begin; j <= i; j++)
			{
				word += s[j];
			}

		}
	}
	return result;
}