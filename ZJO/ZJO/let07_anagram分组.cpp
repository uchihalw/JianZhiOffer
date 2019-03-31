/*
 * @file   let07_anagram分组.cpp
 * @date   2019.3.31.
 * @author GBW
 * @Description: 若某两个字符串，出现的各个字符数相同，则它们应该为同一分组 
 
 * @Note:
 
 */
// version_1
/*
	1.设置字符串到字符串向量的哈希表anagram，遍历字符串向量strs中的单词str[i]
	2.设置临时变量str = str[i],对str进行排序
	3.若str未出现在anagram中，设置str到一个空字符串向量的映射
	4.将str[i]添加至字符串向量anagram[str]中，
	5.遍历哈希表anagram，将全部key对应的value push至最终结果中
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
