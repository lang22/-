#pragma once
#include<iostream>
#include<algorithm> 
using namespace std;
class LoopList
{
public:
	LoopList();
	LoopList(int ,int);
	~LoopList();
	void print();
	void Delete(int );
//private:
	int pw;
	int index;
	LoopList* next;
};
