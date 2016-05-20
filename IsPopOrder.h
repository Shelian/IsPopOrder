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
	
	//����Push����һ��һ��������Pop�е�ֵ
	while (pPopNext - pPop < nLength)
	{
		//���ջΪ�գ�����ջ����ֵ���Ƕ�ӦҪ��ջ��ֵ����ô��Push�����ֵѹ��ջ�У�֪��Push�����е�ֵΪ��ʱ����
		while (stackData.empty() || stackData.top() != *pPopNext)
		{
			if (pPushNext - pPush == nLength)
				break;

			stackData.push(*pPushNext);
			pPushNext++;
		}

		if (stackData.top() != *pPopNext)
			break;
		 
		//����һ����������һ��
		stackData.pop();
		pPopNext++;
	}

	//���ջΪ�ղ���pop����Ҳ�������ˣ�˵����һ����ȷ��ջ������
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