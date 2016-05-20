#ifndef __ISPOPORDER_H__
#define __ISPOPORDER_H__

#include <iostream> 
using namespace std;
#include<stack>

bool IsPopOrder(const int* pPush,const int* pPop, int nLength)
{
	bool result = false;
	if (pPush == NULL || pPop== NULL || nLength <= 0)
		return false;

	const int* pPushNext = pPush;
	const int* pPopNext = pPop;

	stack<int> stackData;
	
	//遍历Push数组一个一个的数组Pop中的值
	while (pPopNext - pPop < nLength)
	{
		//如果栈为空，并且栈顶的值不是对应要出栈的值，那么将Push数组的值压入栈中，知道Push数组中的值为空时跳出
		while (stackData.empty() || stackData.top() != *pPopNext)
		{
			if (pPushNext - pPush == nLength)
				break;

			stackData.push(*pPushNext);
			pPushNext++;
		}

		if (stackData.top() != *pPopNext)
			break;
		 
		//找完一个接着找下一个
		stackData.pop();
		pPopNext++;
	}

	//如果栈为空并且pop数组也遍历完了，说明是一个正确出栈的序列
	if (stackData.empty() && pPopNext - pPop == nLength)
		result = true;

	return result;

}

void test()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 4, 5, 3, 1, 2 };
	cout << IsPopOrder(a, b, 5) << endl;
}



#endif //__ISPOPORDER_H__