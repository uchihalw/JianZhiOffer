/*
 * @file   let07_最小窗口子串.cpp
 * @date   2019.3.31.
 * @author GBW
 * @Description: 已知字符串S与字符串T，求在S中的最小窗口(区间)，使得这个区间中包含了字符串T中的所有字符
 
 S = "ADOBECODEBANC"
 T = "ABC"
 M = "BANC"

 * @Note:
 
 */
/*
	1. 设置两个字符哈希表数组，map_s和map_t。map_s代表当前处理的窗口区间中字符数量，map_t代表子串T的字符数量
	2. 设置两个指针
	3. i指针向后逐个扫描字符串中的字符，在这个过程中，循环检测begin指针是否可以向前移动:
		1. 如果当前begin指向的字符T中没出现，直接前移begin
		2. 如果begin指向的字符T中出现了，但是当前区间窗口中的该字符数量足够，向前移动begin,并更新map_s
		3. 否则不能移动begin,跳出检查
	4. 指针i每向前扫描一个字符，即检查一下是否可以更新最终结果(找到最小的包含T中各个字符的窗口)
	在整个过程中，使用begin与i维护一个窗口
*/





bool is_window_ok(int map_sp[], int map_t[], vector<int>& vec)
{
	for (int i=0;i<vec_t.size();i++)
	{
		if (map_s[vec_t[i]] < map_t[vec_t[i]])
		{
			return false;
		}
	}
	return true;
}


int main()
{
	const int MAX_ARRAY_LEN = 128; // 利用数组下标记录字符个数
	int map_t[128] = { 0 };        // 记录t字符串中各字符的个数
	int map_s[128] = { 0 };

	vector<int> vec_t; // 记录t字符串中有哪些字符
	for (int i = 0; i < t.length(); i++)
	{
		map_t[t[i]]++;
	}
	for (int j = 0; j < MAX_ARRAY_LEN; j++)
	{
		if (map_t[i] > 0)
			vec_t.push_back(i);
	}

	int window_begin = 0; // 最小窗口起始指针
	string result;		// 最小窗口对应的字符串
	for (int i = 0; i < s.length(); i++)  // i代表了窗口的尾指针
	{
		map_s[s[i]]++;
		while (window_begin < i)        // 窗口的头指针不能超过尾指针
		{
			char begin_ch = s[window_begin];
			if (map_t[begin_ch] == 0)  // 如果当前头指针指向的字符串没有在字符串t中出现
			{
				window_begin++;
			}
			else if (map_s[begin_ch] > map_t[begin_ch]) // 头指针指向的字符出现在T中，窗口内有超过T中该字符个数的字符
			{
				map_s[begin_ch]--;                      // 头指针前移了，它指向的字符减少1个
				window_begin++;
			}
			else                                        // 除了上面两种情况，其他都跳出循环
				break;
		}
		// 检查此时的窗口是否包含字符串T
		if (is_window_ok(map_s, map_t, vec_t))
		{
			int new_window_len = i - window_begin + 1;
			if (result == "" || result.length() > new_window_len) // 结果字符串为空或者当前窗口字符串更小的时候更新结果
			{
				result = s.substr(window_begin, new_window_len);
			}
		}
	}
	return result;
}
