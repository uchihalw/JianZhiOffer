/*
 * @file   let07_词语模式.cpp
 * @date   2019.3.31.
 * @author GBW
 * @Description: 已知字符串pattern 与字符串str,确认str是否与pattern匹配。
				 str与pattern匹配代表字符串str中的单词与pattern中的字符一对一
 
 * @Note:
 
 */
// version_1
/*
	1. 设置单词(字符串)到pattern字符的映射(哈希)；使用数组used[128]记录pattern字符是否使用
	2. 遍历str,按照空格拆分单词，同时对应的向前移动指向pattern字符的指针，每拆分出一个单词，判断
		1. 如果该单词从未出现在哈希表中:
			如果当前的pattern字符已被使用，则返回false;
			将单词与当前指向的pattern字符做映射；
			标记当前指向的pattern字符已使用
		2. 否则
			如果当前单词在哈希表中的映射字符不是当前指向的pattern字符，则返回false
	3. 若单词个数与pattern字符个数不匹配，则返回false
*/


bool wordPattern(string pattern, string str)
{
	map<string, char> word_map; // 单词到pattern字符的映射
	char used[128] = { 0 };
	string word; // 临时保存拆分出的单词
	int pos = 0;
	str.push_back(" "); // str尾部push一个空格，使得遇到空格拆分单词

	for (int i=0;i <str.length();i++)
	{
		if (str[i] == ' ') // 遇到空格，即拆分一个新单词
		{
			if (pos == pattern.length())
				return false;
			if (word_map.find(word) == word_map[end]) // 若单词未出现在哈希映射中
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