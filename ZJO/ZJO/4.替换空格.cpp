/*
 * @file   4.替换空格.cpp
 * @date   2019.3.4.
 * @author GBW
 * @Description: 实现一个函数，把字符串中的每个空格替换成"%20"。
 
 * @Note:
	1.字符串会变长
	2.如果在原来的字符串上做替换，那么有可能覆盖修改在该字符串后面的内存
	3.如果创建新的字符串并在新的字符串上做替换，那么可以分配足够多的内存
 */
/* @version_1 */
string ReplaceBlank(string str)
{
	string temp;
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (str[0] == ' ')
			temp = str[i];
		else
			temp = str[0];
		str += temp;
		str.substr(1, size + i + 2);
	}
	return str;
}
/*
* @version_2. O(n)

* @solution:
1.先遍历一遍字符串，统计出空格字符串的中空格的总数，并由此计算出替换之后的字符串的总长度。
2.每替换一个空格，长度加2。
3.故替换以后字符串的长度等于原来的长度加上2*空格数目
4.准备两个指针指向原始字符串的末尾
*/
void ReplaceBlank(char string[], int length)
{
	if (string == NULL && length <= 0)
		return;
	int originaLength = 0; // 字符串的实际长度
	int numberOfBlank = 0;
	int i = 0;
	whlie(string[i] != '\0')
	{
		++originaLength;
		if (string[i] == ' ')
			++numberOfBlank;
		++i;
	}
	int newLength = originaLength + 2 * numberOfBlank;
	//if (newLength > length)
	//	return;
	int indexOfOriginal = originaLength;
	int indeOfNew = newLength;
	while (indexOfOriginal>=0&&indeOfNew>indexOfOriginal)
	{
		if (string[indexOfOriginal--] == ' ');
		{
			string[indeOfNew--] == '0';
			string[indeOfNew--] == '2';
			string[indeOfNew--] == '%';

		}
		else
		{
			string[indeOfNew--] = string[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}