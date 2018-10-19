#pragma once
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
#define MAXVEX 31
#define MAXEDGE 436
typedef struct EdgeNode/* 边表结点  */
{
	int adjvex;/* 邻接点域,存储该顶点对应的下标 */
	struct EdgeNode* next = NULL; /* 链域,指向下一个邻接点 */
}*Edge;

typedef struct Vertex //顶点表节结点
{
	int index;//序列号
	string data;//数据域
	struct EdgeNode* firstedge;//指针域,指向第一个邻接点(后跟一个边表)

}*V;
struct Graph 
{
	V vertices[MAXVEX];//顶点集
	int vexnum, arcnum;//顶点数,边数
};
void checkCin(int b, int min, int max) //输入异常处理
{
	while (cin.fail() || b<min || b>max)
	{
		cin.clear();
		cin.sync();
		cin.ignore();
//		cout << "*************************************************" << endl;
		cout << "***********非法输入!请重新输入正确值!************" << endl;
//		cout << "*************************************************" << endl;
		cout << "重新输入: ";
		cin >> b;
	}
}
//开始用户交互界面
void MakePanel(int &choice) {
	cout << "***********************************************************" << endl;
	cout << "*************************图的遍历**************************" << endl;
	cout << "***********************************************************" << endl;
	cout << "********1:无向图**********2:有向图***********3:退出********" << endl;
	cout << "***********************************************************" << endl;
	cout << "请作出选择:";
	cin >> choice;
	if (choice == 3)
		exit(0);
}
void CreateGraph(Graph &G) //创建一个图,用邻接表存储
{
	int vn, an, vi, vj;//图中顶点数,边数,边(vi,vj)的端点序号
	Edge pEdge;//中间变量边表
	int choice;//用户选择
	MakePanel(choice);
	cout<<"******************"<<(choice==1?("开始创建一个无向图！"):("开始创建一个有向图！")) << "*****************" <<endl;
	cout << "请输入顶点数: ";
	cin >> vn;
	checkCin(vn, 1, MAXVEX);
	cout << "请输入边数: ";
	cin >> an;
	checkCin(an, 0, MAXEDGE);
	G.vexnum = vn;
	G.arcnum = an; 
//	cout << "请依次输入每个顶点的信息." << endl;
	for (int i = 1; i <= vn; i++){
		G.vertices[i] = new Vertex();
		G.vertices[i]->index = i;
//		cout << "V" << i << ": ";
//	cin >> G.vertices[i]->data;//读取顶点信息
		//cout << endl;
		G.vertices[i]->firstedge = NULL;//邻接链表置空
	}
	cout << "请依次输入每条边(vi,vj)的两个端点的序列号.(格式如'1 2')" << endl;
	for (int i = 1; i <= an;i++) {
		cout << "E" << i << ": ";
		cin >> vi >> vj;
		while (cin.fail() || vi<1 || vi>an || vj<1 || vj>an )
		{
			cin.clear();
			cin.sync();
			cin.ignore();
			cout << "***********非法输入!请重新输入正确值!************" << endl;
			cout << "E" << i << ": ";
			cin >> vi >> vj;
		}
		//将vj插入vi的邻接表中
		pEdge = new EdgeNode();
		pEdge->adjvex = vj;
		pEdge->next = G.vertices[vi]->firstedge;
		G.vertices[vi]->firstedge = pEdge;
		if (choice==1)//对于无向图,同时建立(vj,vi)边
		{
			//将vi插入vj的邻接表中
			pEdge = new EdgeNode();
			pEdge->adjvex = vi;
			pEdge->next = G.vertices[vj]->firstedge;
			G.vertices[vj]->firstedge = pEdge;
		}
		//对于有向图,不建立(vj,vi)边
	}
//对邻接表进行重排,冒泡排序
	for (int i = 1; i <= vn; i++) {
		Edge pEdge;
		int len = 1;
		//求该结点的邻接点个数
		for (pEdge = G.vertices[i]->firstedge; pEdge != NULL; pEdge = pEdge->next)
			len++;
		//对邻接表中next->adjvex进行冒泡排序
		for(int j=0;j<len;j++)
			for (pEdge = G.vertices[i]->firstedge; pEdge!=NULL&&pEdge->next!= NULL; pEdge = pEdge->next) {
				if (pEdge->adjvex > pEdge->next->adjvex) {
					//邻接表中序号小的排到前面
					swap(pEdge->adjvex, pEdge->next->adjvex);
				}
					
			}
	}
}
