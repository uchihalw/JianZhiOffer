/*
 * @file   let07_��С�����Ӵ�.cpp
 * @date   2019.3.31.
 * @author GBW
 * @Description: ��֪�ַ���S���ַ���T������S�е���С����(����)��ʹ����������а������ַ���T�е������ַ�
 
 S = "ADOBECODEBANC"
 T = "ABC"
 M = "BANC"

 * @Note:
 
 */
/*
	1. ���������ַ���ϣ�����飬map_s��map_t��map_s����ǰ����Ĵ����������ַ�������map_t�����Ӵ�T���ַ�����
	2. ��������ָ��
	3. iָ��������ɨ���ַ����е��ַ�������������У�ѭ�����beginָ���Ƿ������ǰ�ƶ�:
		1. �����ǰbeginָ����ַ�T��û���֣�ֱ��ǰ��begin
		2. ���beginָ����ַ�T�г����ˣ����ǵ�ǰ���䴰���еĸ��ַ������㹻����ǰ�ƶ�begin,������map_s
		3. �������ƶ�begin,�������
	4. ָ��iÿ��ǰɨ��һ���ַ��������һ���Ƿ���Ը������ս��(�ҵ���С�İ���T�и����ַ��Ĵ���)
	�����������У�ʹ��begin��iά��һ������
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
	const int MAX_ARRAY_LEN = 128; // ���������±��¼�ַ�����
	int map_t[128] = { 0 };        // ��¼t�ַ����и��ַ��ĸ���
	int map_s[128] = { 0 };

	vector<int> vec_t; // ��¼t�ַ���������Щ�ַ�
	for (int i = 0; i < t.length(); i++)
	{
		map_t[t[i]]++;
	}
	for (int j = 0; j < MAX_ARRAY_LEN; j++)
	{
		if (map_t[i] > 0)
			vec_t.push_back(i);
	}

	int window_begin = 0; // ��С������ʼָ��
	string result;		// ��С���ڶ�Ӧ���ַ���
	for (int i = 0; i < s.length(); i++)  // i�����˴��ڵ�βָ��
	{
		map_s[s[i]]++;
		while (window_begin < i)        // ���ڵ�ͷָ�벻�ܳ���βָ��
		{
			char begin_ch = s[window_begin];
			if (map_t[begin_ch] == 0)  // �����ǰͷָ��ָ����ַ���û�����ַ���t�г���
			{
				window_begin++;
			}
			else if (map_s[begin_ch] > map_t[begin_ch]) // ͷָ��ָ����ַ�������T�У��������г���T�и��ַ��������ַ�
			{
				map_s[begin_ch]--;                      // ͷָ��ǰ���ˣ���ָ����ַ�����1��
				window_begin++;
			}
			else                                        // ���������������������������ѭ��
				break;
		}
		// ����ʱ�Ĵ����Ƿ�����ַ���T
		if (is_window_ok(map_s, map_t, vec_t))
		{
			int new_window_len = i - window_begin + 1;
			if (result == "" || result.length() > new_window_len) // ����ַ���Ϊ�ջ��ߵ�ǰ�����ַ�����С��ʱ����½��
			{
				result = s.substr(window_begin, new_window_len);
			}
		}
	}
	return result;
}
