#pragma once
#include"ADL.h"
#include<queue>
bool visited[MAXVEX];//访问标志数组
int SpanningTree[MAXEDGE][2];//生成树边集数组
int start = 1;//遍历起点
int tj;//边集数组计数
void printTree() //打印生成树边集
{
	cout << endl<< "生成树的边集如下：" << endl;
	cout << "{";
	for (int i = 0; i<tj; i++) {
		cout << "(V" << SpanningTree[i][0] << "," << "V" << SpanningTree[i][1] << "),";
	}
	cout << "\b" << " ";
	cout << "}" << endl;
}
int FindRoot(int vn) //选择用户指定的结点作为遍历起点
{
	cout << "***********************************************************" << endl;
	cout << "请选择遍历的起点序号: ";
	cin >> start;
	checkCin(start, 1, vn);
	return start;
}
void DFS(Graph G,int i) 
{
	
	Edge pEdge = new EdgeNode();
	visited[i] = true;
	cout << "V" << i << "->";
	for (pEdge = G.vertices[i]->firstedge; pEdge != NULL; pEdge = pEdge->next) {
		if (!visited[pEdge->adjvex]) {	
			//存储生成树的边
			SpanningTree[tj][0] = i;
			SpanningTree[tj][1] = pEdge->adjvex;
			tj++;
			DFS(G, pEdge->adjvex);
		}			
	}
 }
void DFSTraverse(Graph G) {
	FindRoot(G.vexnum);//指定遍历起点
	cout << "***********************************************************" << endl;
	cout << "深度优先遍历序列如下:" << endl;
	for (int i = 1; i <= G.vexnum; i++)//初始化访问数组，全为false
		visited[i] = false;
	DFS(G,  start);
	cout << "\b\b" << "  " ;
	printTree();//打印生成树边集
	cout << "***********************************************************" << endl;
}
void BFSTraverse(Graph G) 
{
	tj = 0;//生成树边数置0
	cout << "广度优先遍历序列如下:" << endl;
	queue<V> q;//创建队列
	Edge pEdge = new EdgeNode();
	for (int i = 1; i <= G.vexnum; i++)//访问数组重置
		visited[i] = false;
	for (int i = start; i <= G.vexnum; i++)
	{
		if (!visited[i]) {
			q.push(G.vertices[i]);//当前访问结点入队
			cout << "V" << i ;
			visited[i] = true;
			while (!q.empty())
			{
				int j = q.front()->index;
				q.pop();//刚刚访问的结点出队
				for (pEdge = G.vertices[j]->firstedge; pEdge != NULL; pEdge = pEdge->next) {
					if (!visited[pEdge->adjvex]) {
						q.push(G.vertices[pEdge->adjvex]);//当前访问结点入队
						cout << "->" << "V" << pEdge->adjvex;
						visited[pEdge->adjvex] = true;
						//存储生成树的边
						SpanningTree[tj][0] = j;
						SpanningTree[tj][1] = pEdge->adjvex;
						tj++;
					}
						
				}
			}
		}
	}
	printTree();//打印生成树的边集
	cout << "***********************************************************" << endl;
}