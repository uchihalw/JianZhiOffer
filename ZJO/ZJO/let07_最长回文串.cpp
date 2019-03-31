/*
 * @file   let07_最长回文串.cpp
 * @date   2019.3.31.
 * @author GBW
 * @Description: 已知一个包括大小写字符的字符串，求用该字符串中的字符可以生成的最长回文字符串长度
 
 * @Note:
 
 */
// version_1
/*
	1. 利用字符哈希方法，统计字符串中所有的字符数量
	2. 设置最长回文串偶数字符长度为max_length = 0;
	3. 设置是否有中心点标记flag = 0
	4. 遍历每一个字符，字符数为count,
		若count为偶数，max_length += count;
		若count为奇数，max_length += count - 1,flag = 1
	5. 最终最长回文字符串子串长度: max_length + flag
*/
int longestPalindrome(string s)
{
	int char_map[128] = { 0 }; // 字符哈希
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























