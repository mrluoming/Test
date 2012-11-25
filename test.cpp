// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// using namespace std;
// // struct C180
// // {
// // 	C180() {
// // 		foo();
// // 		this->foo();
// // 	}
// // 	virtual foo() {
// // 		cout << "<< C180.foo this: " << this << " vtadr: " << *(void**)this << endl;
// // 	}
// // };
// // struct C190 : public C180
// // {
// // 	C190() {}
// // 	virtual foo() {
// // 		cout << "<< C190.foo this: " << this << " vtadr: " << *(void**)this << endl;
// // 	}
// // }; 
// 
// // class CLS{
// // public:
// // 	int m_Is;
// // 	CLS(int i):m_Is(i){cout << "constructor" << endl;}
// // 	CLS()
// // 	{
// // 		cout << "default constructor" << endl;
// // 		m_Is = 1;
// // 		//CLS(0);
// // 	}
// // };
// // 
// // void OutPut()
// // {
// // 	static int a = 1;
// // 	a++;
// // 	cout << a << endl;
// // }
// // struct A
// // {
// // 	A(){cout << "A()"<<endl;}
// // 	~A(){cout << "~A()" << endl;}
// // 	
// // };
// // 
// // int *GetMem()
// // {
// // 	int *a = new int;
// // 	return a;
// // }
// // 
// // void DelNum(char * str)
// // {
// // 	if (str == NULL)
// // 	{
// // 		return;
// // 	}
// // 
// // }
// 
// class stData
// {
// public:
// 	int i;
// 	double j;
// 
// 	stData(const int iParam,const double jParam):i(iParam),j(jParam)
// 	{
// 	}
// 	stData()
// 	{
// 
// 	}
// };
// class CTest
// {
// public:
// 	stData c;
// 	stData a;
// 	stData & b;
// 	
// 
// 	CTest():b(a),a(c){}
// 
// };
// 
// //判断一个数是否为素数
// bool IsPrimeNum(int dwNum)
// {
// 	if (dwNum < 1)
// 	{
// 		return false;
// 	}
// 
// 	int i=2,j=(int)sqrt(dwNum);
// 	while( i<=j ){
// 		if( dwNum%i==0 ) break;
// 		i++;
// 	}
// 	if( i>j )
// 		return true;
// 	else
// 		return false;
// }
// 
// 
// int main()
// {
// // 	C190 obj;
// // 	obj.foo();
// 
// // 	OutPut();
// // 	OutPut();
// 
// // 	int nSize = 8;
// // 	char *pMem;
// // 	pMem = (char*)malloc(nSize);
// // 	free(pMem);
// // 	
// // 	char str1[] = "abcde";
// // 	char str2[] = "abcde";
// // 	const char str3[] = "abcde";
// // 	const char str4[] = "abcde";
// // 	
// // 	char *str5 = "abcde";
// // 	char *str6 = "abcde";
// // 
// // 	const char *str7 = "abcde";
// // 	const char *str8 = "abcde";
// // 
// // 	cout << (str1 == str2) << endl;
// // 	cout << (str3 == str4) << endl;
// // 	cout << (str5 == str6) << endl;
// // 	cout << (str7 == str8) << endl;
// // 
// // 	CLS obj;
// // 	cout << obj.m_Is << endl;
// 
// // 	vector<int> t(3);
// // 	vector<int>::iterator it;
// //     for (it = t.begin(); it != t.end(); it++)
// //     {
// // 		cout << *it << endl;
// //     }
// 	//for_each(t.begin(),t.end(),OutPut);
// 
// 
// // 	int *p = NULL;
// // 	p = GetMem();
// // 	*p = 1;
// // 	return *p;
// 
// 	//CTest t;
// 
// 	int i;
// 	cin >> i;
// 	if (IsPrimeNum(i))
// 	{
// 		cout << i << "是1个素数。" <<endl;
// 	}
// 	else
// 	{
// 		cout << i << "不是1个素数。" <<endl;
// 	}
// 
// 
// 	return 1;

//}

// #include<iostream>
// 
// #include<windows.h>
// 
// using namespace std;
// 
// HANDLE hMutex;
// 
// 
// DWORD TEMP=1000;
// 
// 
// DWORD WINAPI Xfun(LPVOID LpParameter)
// 
// {
// 	
// 	while(1)
// 		
// 	{
// 		
// 		WaitForSingleObject(hMutex,INFINITE);  // 申请资源
// 		
// 		cout<<"XFun display:"<<TEMP--<<endl;
// 		
// 		Sleep(10000);
// 		
// 		ReleaseMutex(hMutex);  // 释放申请的资源	
// 	}
// 	
// 	
// }
// 
// 
// DWORD WINAPI Fun(LPVOID lpParameter)  // 线程函数
// 
// {
// 	
// 	HANDLE hThread = CreateThread(NULL,0,Xfun,NULL,0,NULL);   // 创建一个线程
// 	
// 	hMutex = CreateMutex(NULL,FALSE,"screen");
// 	
// 	while(1)
// 		
// 	{
// 		
// 		WaitForSingleObject(hMutex,INFINITE);  // 申请资源
// 		
// 		cout<<"Fun display:"<<TEMP--<<endl;
// 		
// 		Sleep(10000);
// 		
// 		ReleaseMutex(hMutex);  // 释放申请的资源
// 		
// 	}
// 	
// }
// 
// 
// 
// int main()
// 
// {
// 	
// 	HANDLE hThread = CreateThread(NULL,0,Fun,NULL,0,NULL);   // 创建一个线程
// 	
// 	hMutex = CreateMutex(NULL,FALSE,"screen");//创建一个独占资源
// 	
// 	CloseHandle(hThread);
// 	
// 	while(1)
// 		
// 	{
// 		
// 		WaitForSingleObject(hMutex,INFINITE);
// 		
// 		
// 		cout<<"main display:"<<TEMP--<<endl;
// 		
// 		
// 		Sleep(2000);
// 		
// 		
// 		ReleaseMutex(hMutex);
// 			
// 	}
// 	
// 	return 0;
// 	
// }




//#include "stdafx.h"
#include <iostream>
using namespace std;

class T
{
public:
	int a;
//	char b;
//	double c;

	virtual void SetA(const int _a)
	{
		a = _a;
	}

	

	virtual void Print(const int _b)
	{
		cout << "Virtual Print Fuction!" << endl;
	}

    static T* GetInstance()
	{
		T *pInstance = new T();
		return pInstance;
	}
	static void DestroyInstance(T* pInst)
	{
		if(pInst)
		{
			delete pInst;
			pInst = NULL;
		}
	}

private:
	T(){cout << "T() is called" << endl;}
	~T(){cout << "~T() is called!" << endl;}
	void func(int n) {cout << "ddddd" << endl;}
public:
	void Test(){func(100);}
};

int main()
{
	T* Inst = NULL;
	Inst = T::GetInstance();
	T::DestroyInstance(Inst);

//	if(Inst)
//		delete Inst;

	cout << "a wanderful test program." <<endl;
		
	return 1;
}