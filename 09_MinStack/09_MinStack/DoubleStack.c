#include "DoubeStack.h"

void DoubleStackInit(DoubleStack* ds)
{
	assert(ds);
	StackInit(&(ds->st));
	NStackInit(&(ds->nst));
}

void DoubleStackDestory(DoubleStack* ds)
{
	assert(ds);
	StackDestory(&(ds->st));
	NStackDestory(&(ds->nst));
}

IDataType DoubleStackTop(const DoubleStack* ds)
{
	assert(ds);
	if ((ds->st)._top == 0)
	{
		printf("空栈\n");
		return -1;
	}
	return StackTop(&ds->st);
}

void DoubleStackPush(DoubleStack* ds, IDataType x)
{
	SDataType s;
	SDataType ret;
	assert(ds);

	//如果结构体栈为空
	if(NStackEmpty(&ds->nst) == 0)
	{
		s.count = 1;
		s.num = x;
		StackPush(&ds->st,x);
		NStackPush(&ds->nst, s);
	}
	else
	{
		
		StackPush(&ds->st, x);
		//如果入栈的元素小于最小值记录栈的栈顶
		if(x < NStackTop(&ds->nst).num)
		{
			s.num = x;
			s.count = 1;
			//将此元素的对应结构体入栈
			NStackPush(&ds->nst, s);
		}
		else if (x == NStackTop(&ds->nst).num) 
		{
			//相等的情况
			ret = NStackTop(&ds->nst);
			NStackPop(&ds->nst);
			ret.count += 1;
			NStackPush(&ds->nst, ret);
		}
	}
}
void DoubleStackPop(DoubleStack* ds)
{
	SDataType ret;
	assert(ds);
	//先获取结构体栈的栈顶元素
	ret = NStackTop(&ds->nst);

	//如果像个相等就做结构体计数-1或者出栈操作
	if(ret.num == StackTop(&ds->st))
	{
		if(ret.count == 1)
		{
			NStackPop(&ds->nst);
		}
		else 
		{
			ret.count--;
			NStackPop(&ds->nst);
			NStackPush(&ds->nst, ret);
		}
	}
	//将原本存数字出栈
	StackPop(&ds->st);
}

int DoubleStackEmpty(const DoubleStack* ds)
{
	assert(ds);
	return StackEmpty(&ds->st);
}

int DoubleStackSize(const DoubleStack* ds)
{
	assert(ds);
	return StackSize(&ds->st);
}

//获取最小值
int GetMinNum(const DoubleStack* ds)
{
	assert(ds);
	return (NStackTop(&ds->nst)).num;
}

void TestDoubleStack()
{
	int ret = INT_MIN;
	DoubleStack ds;
	DoubleStackInit(&ds);
	DoubleStackPush(&ds, 1);
	DoubleStackPush(&ds, 2);
	DoubleStackPush(&ds, -1);
	DoubleStackPush(&ds, 1);
	DoubleStackPush(&ds, 0);
	DoubleStackPush(&ds, 0);
	DoubleStackPush(&ds, -1);
	DoubleStackPush(&ds, 1);

	DoubleStackPop(&ds);
	DoubleStackPop(&ds);
	DoubleStackPop(&ds);
	DoubleStackPop(&ds);

	ret = GetMinNum(&ds);
	printf("最小值为：%d\n",ret);
	DoubleStackDestory(&ds);
}