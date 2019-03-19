/*
 * @file   10.斐波那契.cpp
 * @date   2019.3.16.
 * @author GBW
 * @Description: 斐波那契数列
 
 * @Note:
 
 */
0. 求1+2+3+...+n
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

1. Fibonacci
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
		从下往上算，首先根据f(0)和f(1)->f(2)
						  f(1)和f(2)->f(3)
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

	3.version_3
	long long Fibonacci(int n)
	{
		vector<int> dp(n + 2, 0); // +3是为了防止n=0时候，也正常走流程，不用加判断。
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; i++)  // index默认从0开始，故n =3的时候，需要计算dp[n]
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}

2. 青蛙跳台阶，一次可以跳上一级，也可以跳上二级。求跳上一个n级总共有多少种跳法
如果有1级台阶，有一种跳法
如果有2级台阶，有两种跳法
将n级台阶的跳法看成是n的函数，记为f(n)
当n>2时，第一次跳的时候就有两种不同的选择：
	0.第一次跳1级，此时总的跳法数目等于后面剩下的n-1级台阶的跳法数目，即f(n-1)
	1.第一次跳2级，此时总的跳法数目等于后面剩下的n-2级台阶的跳法数目，即f(n-2)
因此，n级台阶的不同跳法的总数f(n) = f(n-1) + f(n-2)