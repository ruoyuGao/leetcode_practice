#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<math.h>
using namespace std;
//https://leetcode-cn.com/problems/max-points-on-a-line/
//思路：遍历所有点，一个点和任意两个点组成的直线斜率相同，则这三个点在同一条直线上，因此本题只研究斜率
class Solution{
	//辗转相除法求最大公因数
	//算法原理：若a除以b的余数为r , 则有 (a , b) = ( b ,r ) 
	public: 
	int gcd(int a,int b)
	{
		return b==0?a:gcd(b,a % b);
	}
	int maxPoints(vector<vector<int>>& points)
	{
		int n=points.size();
		int result=0;
		
		if(n<=2)
		{
			return n;
		}
		for(int i=0;i<n;i++)
		{	//当一个直线过超过一半的直线的时候，这个群就是最大的群
			if (result >= n - i || result > n / 2) 
			{
   			    break;
   		        }
			unordered_map<int,int> mp;
			for(int j=i+1;j<n;j++)
			{
				
				int dx=points[j][0]-points[i][0];
				int dy=points[j][1]-points[i][1];
				if(dx==0)dy=1;
				if(dy==0)dx=1;
				if(dy<0)dx=-dx,dy=-dy;
				//保证符号位在一个上
				//这样做的原因是卡住了y的范围，使其只有x的一半，但是如果不这样卡，字符串是最优解，因为字符串出来是一样的，可以举例（10，-5） （-10，5）
				int temp=gcd(abs(dx),abs(dy));
				dx/=temp;
				dy/=temp;
				mp[dy+dx*20001]++;
				//将x和y表示在不同的位数上，同时也可以用字符串替代这个方法
				//mp[dx_dy]字符串表示方法
			}
			//两种遍历map的方法，分别是直接使用迭代器指针和默认的auto方法,上面的遍历方法比下面的更消耗时间
			int max_number=0;
			for(unordered_map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
			{
				max_number=max(max_number,it->second+1);
			}
			result=max(result,max_number);
			//for(auto&[_,num]:mp)
			//{
			//	max_number=max(max_number,num+1);
		        //	}
		
		}
		return result;
			
	}
};
int main()
{
	vector<vector<int>> points(6,vector<int>(2));
	int points2[6][2]={{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<2;j++)
		{
			points[i][j]=points2[i][j];
		}
	}
	Solution a;
	cout<<a.maxPoints(points)<<endl;
	system("pause");
	return 0;
	
}

