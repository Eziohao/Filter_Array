// Counting_Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

typedef struct node
{
	double val;
	struct node* pNext;
	
}NODE,*PNODE;

class MyList
{
public:
	MyList();
	~MyList();
	void Init();
	void DelAt(double k);
	int GetNodeCnt();
	void GetResult();
	void Travel();

private:
	PNODE pHead;

};

MyList::MyList()
{
	this->pHead = NULL;
}

MyList::~MyList()
{
	while (this->pHead != NULL)
	{
		PNODE pTemp = pHead->pNext;
		delete pHead;
		pHead = pTemp;
	}
}
void MyList::Init(){
	double a[] = { 5, 4, 2.5, 4.5, -3.5, 1.5, 0.5, 3.5, 2.5, 4.5, -2.5, 1.5, -1.5, 5, 0, 4, 0, -2, 4, 2.5, 4.5, -3.5, 1.5, 0.5, 3.5, 2.5, 4.5, -2.5, 1.5, -1.5, 5 };
	
	int i,NoA;
	PNODE pTail, pNew;
	NoA = sizeof(a) / sizeof(double);
	for (i = 0; i < NoA; i++){
		if (pHead == NULL)
		{
			pHead = new NODE;
			pHead->val = a[i];
			pHead->pNext = NULL;
			pTail = pHead;

		}
		else
		{
			pTail = pHead;
			while (pTail->pNext!=NULL)
			{
				pTail = pTail->pNext;

			}
			pNew = new NODE;
			pNew->val = a[i];
			pNew->pNext = NULL;

			pTail->pNext = pNew;
			pTail = pTail->pNext;
		}
	}
	

}
void MyList::DelAt(double k){
	PNODE p1, pTemp;
	p1 = pHead;
	if (pHead == NULL){
		return ;
	}
	else if (k==pHead->val)
	{
		pTemp = pHead;
		pHead = pHead->pNext;
		delete pTemp;
	}
	else
	{
		while (p1->pNext!=NULL)
		{
			if (p1->pNext->val == k){
				pTemp = p1->pNext;
				p1->pNext = pTemp->pNext;
				delete pTemp;
				return;
			}
			p1 = p1->pNext;
		}
	}
   
	return ;
}
int MyList::GetNodeCnt(){
	int cnt = 0;
	PNODE pTemp = pHead;
	while (pTemp != NULL){
		cnt++;
		pTemp = pTemp->pNext;

	}
	return cnt; 
    
}
void MyList::GetResult(){
	PNODE p1, p2,p3,p1Temp,p2Temp;
	double b[50];
	for (int i = 0; i < 50; i++){
		b[i] = NULL;
	}
	int j = 0, cnt;
	
	if (pHead != NULL){
		cnt = GetNodeCnt();
		p1 = pHead;
		p2 = p1->pNext;
		p3 = p2->pNext;
		while (cnt>3&&p1!=NULL)
		{
		
			
				if (p1->val>p2->val&&p1->val <= p3->val){

					b[j] = p1->val;
					b[j + 1] = p2->val;
					p1Temp = p1;
					p2Temp = p2;
					DelAt(p1Temp->val);
					DelAt(p2Temp->val);
						p1 = pHead;
						p2 = p1->pNext;
						p3 = p2->pNext;
						
						j = j + 2;

				
					
				}
				else if (p1->val < p2->val&&p1->val>=p3->val)
				{
					b[j] = p1->val;
					b[j + 1] = p2->val;
					p1Temp = p1;
					p2Temp = p2;
					DelAt(p1Temp->val);
					DelAt(p2Temp->val);
						p1 = pHead;
						p2 = p1->pNext;
						p3 = p2->pNext;
						
						j = j + 2;

					
				}
				else
				{
					if (p2 != NULL&&p3 != NULL&&p3->pNext != NULL){
						p1 = p2;
						p2 = p3;
						p3 = p3->pNext;
				

					}
				
				}
			
			cnt = GetNodeCnt();
			
			
		}
	}
	for (int i = 0; i <=j; i++){
		cout << b[i] << " ";
	}
	return;

}
void MyList::Travel(){
	PNODE pTemp = this->pHead;
	while (pTemp!=NULL)
	{
		cout << pTemp->val << " ";
		pTemp = pTemp->pNext;
	}
	cout << endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	
	int cnt;
	MyList list;
	list.Init();
	
	list.GetResult();

	
	return 0;
}

