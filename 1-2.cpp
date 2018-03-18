#include <iostream>

typedef unsigned long long ull;
using namespace std;

ull c[10];

int count_by_bit(int n);
int count_zero_by_bit(int n);
int count_by_group(int h, int n);
void add_count(ull count);

ull num;

int main()
{
	while (cin >> num) {
		//初始化
		int high;
		ull last = 0;
		int bits = 1;
		ull number = num;
		int low;
		//数组置零（也可以用 memset 函数）
		for (ull i = 0; i < 10; i++) {
			c[i] = 0;
		}
		
		if (number > 9) {
			//大于等于 10 才成立
			ull same;
			while (number > 9) {
				low = number % 10;
				last += low * pow(10, bits - 1);
				high = (number / 10) % 10;
				//每个数字都出现了 same 次
				same = count_by_group(high, bits); 
				add_count(same);
				//计算并加上被分解为 组 后，不满足组的前一个位的数字出现次数
				for (int i = 0; i < high; i++)
					c[i] += pow(10, bits);
				c[high] += last + 1;
				//计算并加上个位剩下的数
				if (bits == 1) { 
					for (int i = 0; i <= low; i++)
						c[i]++;
				}
				number /= 10;
				bits++;
			}
			//减去零的个数
			c[0] -= count_zero_by_bit(bits);
		} else {
			//小于 10
			for (int i = 1; i <= number; i++)
				c[i]++;
		}
		//输出
		for (int i = 0; i < 10; i++)
			cout << i << ":" << c[i] << " ";
		cout << endl;
	}
	return 0;
}
//当位数为 n 时补零后每个数字出现的次数
int count_by_bit(int n) {
	return n * pow(10, n - 1);
}
//当位数为 n 时补零的次数
int count_zero_by_bit(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += pow(10, i - 1);
	return sum;
}
//计算位数为 bit 的，组数为 groups 的补零后每个数出现的次数
int count_by_group(int groups, int bit) {
	return groups * count_by_bit(bit);
}

//给每个数字添加 n 次出现次数 
void add_count(ull n) {
	for (int i = 0; i < 10; i++)
		c[i] += n;
}


