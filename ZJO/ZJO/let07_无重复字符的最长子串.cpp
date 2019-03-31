/*
 * @file   let07_无重复字符的最长子串.cpp
 * @date   2019.3.31.
 * @author GBW
 * @Description: 已知一个字符串，求用该字符串的无重复字符的最长子串的长度
 
 * @Note:
 
 */
// version_1. 窗口或者双指针扫描
/*
	1.设置一个记录字符数量的字符哈希，char_map
	2.设置一个记录当前满足条件的最长子串变量word
	3.设置两个指针指向字符串第一个字符
	4.设置最长满足条件的子串的长度result
	5.i指针向后逐个扫描字符串中的字符，这这个过程中，使用char_map记录字符数量
		如果word找那个没出现过该字符:对word尾部添加字符并检查result是否需要更新
		否则:begin指针向前移动，更新char_map中的字符数量，直到字符s[i]的数量为1；更新word，将word赋值为begin与i之间的子串
	6.整个过程中，使用begin与i维护一个窗口，该窗口中的子串满足题目条件，窗口线性向前滑动，整体时间复杂度为O(n)
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
		if (char_map[s[i]] == 1) // workd中没出现过该字符
		{
			word += s[i];
			if (result < word.length())
				result = word.length();
		}
		else //将重复的字符s[i]删去
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