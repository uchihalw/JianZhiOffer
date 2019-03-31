/*
 * @file   let07_anagram����.cpp
 * @date   2019.3.31.
 * @author GBW
 * @Description: ��ĳ�����ַ��������ֵĸ����ַ�����ͬ��������Ӧ��Ϊͬһ���� 
 
 * @Note:
 
 */
// version_1
/*
	1.�����ַ������ַ��������Ĺ�ϣ��anagram�������ַ�������strs�еĵ���str[i]
	2.������ʱ����str = str[i],��str��������
	3.��strδ������anagram�У�����str��һ�����ַ���������ӳ��
	4.��str[i]������ַ�������anagram[str]�У�
	5.������ϣ��anagram����ȫ��key��Ӧ��value push�����ս����
*/
vector<vector<string>> groupAnagram(vector<string>& strs)
{
	map<string, vector<string>> anagram;

	vector<string> result;

	for (int i = 0; i < strs.size(); i++)
	{
		string str = strs[i];
		sort(str.begin(), str.end());
		if (anagram.find(str) == anagram.end())
		{
			vector<string> item;
			anagram[str] = item;
		}
		anagram[str].push_back(str[i]);
	}
	map<string, vector<string>>::iterator it;
	for (it = anagram.begin(); it!= anagram.end(); it++)
	{
		result.push_back((*it).second);
	}
	return result;
}
