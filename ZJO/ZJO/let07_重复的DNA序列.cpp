/*
 * @file   let07_�ظ���DNA����.cpp
 * @date   2019.3.31.
 * @author GBW
 * @Description: ��DNA���п�����ֻ����[A.C.G.T]4���ַ����ַ�������һ��DNA�ַ������ҵ����г���Ϊ10���ҳ��ֳ���1�ε��Ӵ�
 
 * @Note:
 
 */
// version_1
/*
	ö��DNA�ַ��������г���Ϊ10���Ӵ���������뵽��ϣmap�У�����¼�Ӵ�������
	������ϣmap�������г��ֳ���һ�ε��Ӵ��洢������С�O(n)
*/
vector<string> findRepeatDnaSequence(string s)
{
	map<string, int> word_map;
	vector<string> result;
	for (int i=0; i<s.length();i++)
	{
		string word = s.substr(i, 10);
		if (word_map.find(word) != word_map.end())
		{
			word_map[word] += 1;
		}
		else
		{
			word_map[word] = 1;
		}
	}

	map<string, int>::iterator it;
	for (it = word_map.begin();it!=word_map.end();it++)
	{
		if (it->second > 1)
			result.push_back((it->first);
	}
	return result;
}