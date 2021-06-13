#include<iostream>
using namespace std;
bool isBadVersion(int version);
//题目：https://leetcode-cn.com/problems/first-bad-version/
int firstBadVersion(int n)
     {
        int up_border=n;
        int under_border=1;
        while(under_border<up_border)
        {
            //int temp=(up_border+under_border)/2;
	    //不能按上面那么写，因为会导致溢出,如果按照上面那个写法，记得把边界定义为long
            int temp=under_border+(up_border-under_border)/2;
            if(isBadVersion(temp))
            {
                up_border=temp;
            }else
            {
                
                under_border=temp+1;
            }
        }
	return under_border;
    }