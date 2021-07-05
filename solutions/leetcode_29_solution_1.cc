int Medium::divide(int dividend, int divisor)
{
	int Max_int = 0x7FFFFFFF;
	int Min_int = 0x80000000;
	// 特殊值处理 0x80000000 / -1
	if (divisor == -1 && dividend == Min_int) return Max_int; 
	// 符号同化
	int flag1 = -1;
	int flag2 = -1;
	if (dividend >= 0)
	{
		flag1 = 1;
		dividend = 0 - dividend;
	}
	if (divisor >= 0)
	{
		flag2 = 1;
		divisor = 0 - divisor;
	}
	// 结果符号
	int flag = 1;
	if (flag1 != flag2) flag = -1;
	// 特殊值处理 -2 / -4 
	if (dividend > divisor) return 0;

	int num = 0;
	int count = 0;
	while (dividend < 0)
	{
		int divisor_pow_current = divisor;
		int divisor_pow_last = 0;
		int result = -1;
		while (true)
		{
			divisor_pow_last = divisor_pow_current;
			// 越界处理 防止 divisor_pow_current += divisor_pow_current 越界
			if (Min_int - divisor_pow_current > divisor_pow_current) break;
			divisor_pow_current += divisor_pow_current;
			if (divisor_pow_current < dividend ) break;
			result += result; 
		}
		dividend -= divisor_pow_last;
		num += result;
	}
	if (dividend != 0) num++;
		
	if (flag < 0) return num;
	else return 0 - num;
}

/*
链接：https://leetcode-cn.com/problems/divide-two-integers/solution/c-shi-xian-wu-long-wu-qiang-zhi-zhuan-huan-by-st_a/
*/