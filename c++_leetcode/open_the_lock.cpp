#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
//代码被误删了，难受；(
//题目https://leetcode-cn.com/problems/open-the-lock/
//本题写了DFS，无限递归崩了
//BFS,先开一个队列存放状态和变化次数，再开一个表示见过的状态
//BFS中，auto定义函数的用法：https://zhuanlan.zhihu.com/p/343507680
// emplace()比insert（）少创建一个对象而是直接指向地址，效率更高https://zhuanlan.zhihu.com/p/54486697
//move()函数会在传递完变量后，删除原先变量中保存的内容https://blog.csdn.net/p942005405/article/details/84644069
//A*方法是估算从起点经过节点x到终点的距离 fx=hx+gx h是预估的x到终点的距离，这里是每个数字转到target的次数和，g是从起点到x的距离，我们因为每次都要去除最小的fx进行搜索，所以
//要使用优先队列https://blog.csdn.net/weixin_36888577/article/details/79937886    剩下的和BFS一样，因为减少了不变要的探索效率提升了三倍在本题中