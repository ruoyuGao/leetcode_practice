#include<iostream>
using namespace std;

class Solution{
	public:
		//左移补1，对每一位进行判断 O（n）
		int hammingWeight(uint32_t n)
		{
			int ret=0;
			for(int i=0;i<32;i++)
			{
				if(n&(1<<i))
				{
					ret++;
				}
			}
			return ret;
		}
		//logn的复杂度，本质上是每一次去掉n最小位置的1
		int hammingweight(uint32_t n)
		{
			int ret=0;
			while(n)
			{
				n=n&(n-1);
				ret++;
			}
			return ret;
		}

};