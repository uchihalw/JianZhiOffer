/*
 * @file   let07_重复的DNA序列.cpp
 * @date   2019.3.31.
 * @author GBW
 * @Description: 将DNA序列看做是只包含[A.C.G.T]4个字符的字符串，给一个DNA字符串，找到所有长度为10的且出现超过1次的子串
 
 * @Note:
 
 */
// version_1
/*
	枚举DNA字符串中所有长度为10的子串，将其插入到哈希map中，并记录子串数量；
	遍历哈希map，将所有出现超过一次的子串存储到结果中。O(n)
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