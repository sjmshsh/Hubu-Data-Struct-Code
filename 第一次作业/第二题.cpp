// 试用用线性表的顺序存储结构实现约瑟夫(Josephu)问题。约瑟夫问题如下：设有n个人围坐圆桌周围。
// 从某个位置上的人开始从1报数，数到m的人便出列，下一个人(第m+1个)又从1报数开始，数到m的人便是第2个出列的人，
// 依次类推，直到最后一个人出列为止，这样就可以得到一个人员排列的新次序。例如，n=8,m=4,从第1个人数起，得到的新次序为48521376。

#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct node
{
	int number;
	struct node *next;
}person;

person* initLink(int n)
{
	person *head = nullptr;
	person *cyclic = nullptr;
	head = (person*)malloc(sizeof(person));
	head->number = 1;
	head->next = nullptr;
	cyclic = head;
	for (int i = 2; i <= n; i++)
	{
		person *body = (person*)malloc(sizeof(person));
		body->number = i;
		body->next = nullptr;
		cyclic->next = body;
		cyclic = cyclic->next;
	}
	// 首位相连
	cyclic->next = head;
	return head;
}

void findAndKillK(person *head, int k, int m)
{
	person *p = nullptr;
	person *tail = head;
	// 找到链表上的第一个节点，为删除操作做准备
	while (tail->next != head)
	{
		tail = tail->next;
	}
	p = head;
	// 找到编号为k的人
	while (p->number != k)
	{
		tail = p;
		p = p->next;
	}
	// 从编号为K的人开始，只有符合p->next==p的时候，说明链表中除了P节点
	// 所有编号都出列了
	while (p->next != p)
	{
		int i = 0;
		// 找到从P报数1开始，报m的人，并且还要知道数m-1的人的位置，tail，方便做删除曹祖
		for (int i = 1; i < m; i++)
		{
			tail = p;
			p = p->next;
		}
		// 从链表上把p节点摘下来
		tail->next = p->next;
		printf("出列人的编号为: %d\n", p->number);
		free(p);
		// 继续使用P指针指向列编号的下一个编号，游戏继续
		p = tail->next;
	}
	printf("出列人的编号为: %d\n", p->number);
	free(p);
}

int main()
{
	// 有8个人
	int n = 8;
	// 数到m就出列
	int m = 4;
	// 插入数据
	person *head = initLink(n);
	findAndKillK(head, 1, m);
	return 0;
}
