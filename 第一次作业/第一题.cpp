// 实验题目：(1)编写程序实现顺序表的各种基本运算。对给定字符数组a[]={'4','9','2','8','0','5','4','6','7','9'}，创建顺序表L，删除大于等于'1'小于等于'5'的元素。

#include "List.h"

using namespace std;


int Test1()
{
	char a[] = { '4','9','2','8','0','5','4','6','7','9' };
	SeqList sl;
	SeqListInit(&sl);
	int n = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < n; i++)
	{
		SeqListPushBack(&sl, a[i]);
	}
	int i = 0;
	while (i < n)
	{
		if (sl.a[i] >= '1' && sl.a[i] <= '5')
		{
			SeqListErase(&sl, i);
		}
		else 
		{
			i++;
		}
	}
	SeqListPrint(&sl);
	return 0;
}
