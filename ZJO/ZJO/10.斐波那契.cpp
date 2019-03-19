/*
 * @file   10.쳲�����.cpp
 * @date   2019.3.16.
 * @author GBW
 * @Description: 쳲���������
 
 * @Note:
 
 */
0. ��1+2+3+...+n
	0. int Add_Recursive(int n)
		{
			return n <= 0 ? 0 : n + Add_Recursive(n - 1)
		}

	1. int Add_Iterative(int n)
	{
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			res += i;
		}
		return res;
	}

1. Fibonacci   0�� 1��1��2��3��5��8��13
// ֻ�����n��쳲�������
	0.version_0
	long long Fibonacci(int n)
	{
		if (n <= 0)
			return 0;
		if (n == 1)
			return 1;
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}

	1.version_1
	/*
		���������㣬���ȸ���f(0)��f(1)->f(2)
						  f(1)��f(2)->f(3)
	*/
	long long Fibonacci(int n)
	{
		if (n < 2)
			return n;
		long long fir = 0;
		long long sec = 1;
		int fibN = 0;
		for (int i = 2; i <= n; i++)
		{
			fibN = fir + sec;
			fir = sec;
			sec = fibN;
		}
	}

	2.version_2
	/*
	[                    ]     [         ]^n
		f(n)   , f(n-1)    =       1  1
 		f(n-1), f(n-2)     =       1  0
	[                    ]     [         ]
	*/



2. ������̨�ף�һ�ο�������һ����Ҳ�������϶�����������һ��n���ܹ��ж���������
�����1��̨�ף���һ������
�����2��̨�ף�����������
��n��̨�׵�����������n�ĺ�������Ϊf(n)
��n>2ʱ����һ������ʱ��������ֲ�ͬ��ѡ��
	0.��һ����1������ʱ�ܵ�������Ŀ���ں���ʣ�µ�n-1��̨�׵�������Ŀ����f(n-1)
	1.��һ����2������ʱ�ܵ�������Ŀ���ں���ʣ�µ�n-2��̨�׵�������Ŀ����f(n-2)
��ˣ�n��̨�׵Ĳ�ͬ����������f(n) = f(n-1) + f(n-2)


1��1��2��3��5��8��13
// n = 3ʱ��������쳲��������еĵ�3������������̨̤���ж����ַ���

Input : 2
		Output : 2
		Explanation : There are two ways to climb to the top.
		1. 1 step + 1 step
		2. 2 steps

Input : 3
	Output : 3
	Explanation : There are three ways to climb to the top.
	1. 1 step + 1 step + 1 step
	2. 1 step + 2 steps
	3. 2 steps + 1 step

long long Fibonacci(int n)
{
		vector<int> dp(n + 3, 0); // +3��Ϊ�˷�ֹn=0ʱ��Ҳ���������̣����ü��жϡ�
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++)  // indexĬ�ϴ�0��ʼ����n =3��ʱ����Ҫ����dp[n]
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
}