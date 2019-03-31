/*
 * @file   let07_����ģʽ.cpp
 * @date   2019.3.31.
 * @author GBW
 * @Description: ��֪�ַ���pattern ���ַ���str,ȷ��str�Ƿ���patternƥ�䡣
				 str��patternƥ������ַ���str�еĵ�����pattern�е��ַ�һ��һ
 
 * @Note:
 
 */
// version_1
/*
	1. ���õ���(�ַ���)��pattern�ַ���ӳ��(��ϣ)��ʹ������used[128]��¼pattern�ַ��Ƿ�ʹ��
	2. ����str,���տո��ֵ��ʣ�ͬʱ��Ӧ����ǰ�ƶ�ָ��pattern�ַ���ָ�룬ÿ��ֳ�һ�����ʣ��ж�
		1. ����õ��ʴ�δ�����ڹ�ϣ����:
			�����ǰ��pattern�ַ��ѱ�ʹ�ã��򷵻�false;
			�������뵱ǰָ���pattern�ַ���ӳ�䣻
			��ǵ�ǰָ���pattern�ַ���ʹ��
		2. ����
			�����ǰ�����ڹ�ϣ���е�ӳ���ַ����ǵ�ǰָ���pattern�ַ����򷵻�false
	3. �����ʸ�����pattern�ַ�������ƥ�䣬�򷵻�false
*/


bool wordPattern(string pattern, string str)
{
	map<string, char> word_map; // ���ʵ�pattern�ַ���ӳ��
	char used[128] = { 0 };
	string word; // ��ʱ�����ֳ��ĵ���
	int pos = 0;
	str.push_back(" "); // strβ��pushһ���ո�ʹ�������ո��ֵ���

	for (int i=0;i <str.length();i++)
	{
		if (str[i] == ' ') // �����ո񣬼����һ���µ���
		{
			if (pos == pattern.length())
				return false;
			if (word_map.find(word) == word_map[end]) // ������δ�����ڹ�ϣӳ����
			{
				if (used[pattern[pos]])
					return false;
				word_map[word] = pattern[pos];
				used[pattern[pos]] = 1;
			}
			else
			{
				if (word_map[word] != pattern[pos])
					return false;
			}
			word = "";
			pos++;
		}
		else
		{
			word += str[i];
		}
	}
	if (pos != pattern.length())
		return false;
	return true;
}