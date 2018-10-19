#pragma once
#include"ADL.h"
#include<queue>
bool visited[MAXVEX];//���ʱ�־����
int SpanningTree[MAXEDGE][2];//�������߼�����
int start = 1;//�������
int tj;//�߼��������
void printTree() //��ӡ�������߼�
{
	cout << endl<< "�������ı߼����£�" << endl;
	cout << "{";
	for (int i = 0; i<tj; i++) {
		cout << "(V" << SpanningTree[i][0] << "," << "V" << SpanningTree[i][1] << "),";
	}
	cout << "\b" << " ";
	cout << "}" << endl;
}
int FindRoot(int vn) //ѡ���û�ָ���Ľ����Ϊ�������
{
	cout << "***********************************************************" << endl;
	cout << "��ѡ�������������: ";
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
			//�洢�������ı�
			SpanningTree[tj][0] = i;
			SpanningTree[tj][1] = pEdge->adjvex;
			tj++;
			DFS(G, pEdge->adjvex);
		}			
	}
 }
void DFSTraverse(Graph G) {
	FindRoot(G.vexnum);//ָ���������
	cout << "***********************************************************" << endl;
	cout << "������ȱ�����������:" << endl;
	for (int i = 1; i <= G.vexnum; i++)//��ʼ���������飬ȫΪfalse
		visited[i] = false;
	DFS(G,  start);
	cout << "\b\b" << "  " ;
	printTree();//��ӡ�������߼�
	cout << "***********************************************************" << endl;
}
void BFSTraverse(Graph G) 
{
	tj = 0;//������������0
	cout << "������ȱ�����������:" << endl;
	queue<V> q;//��������
	Edge pEdge = new EdgeNode();
	for (int i = 1; i <= G.vexnum; i++)//������������
		visited[i] = false;
	for (int i = start; i <= G.vexnum; i++)
	{
		if (!visited[i]) {
			q.push(G.vertices[i]);//��ǰ���ʽ�����
			cout << "V" << i ;
			visited[i] = true;
			while (!q.empty())
			{
				int j = q.front()->index;
				q.pop();//�ոշ��ʵĽ�����
				for (pEdge = G.vertices[j]->firstedge; pEdge != NULL; pEdge = pEdge->next) {
					if (!visited[pEdge->adjvex]) {
						q.push(G.vertices[pEdge->adjvex]);//��ǰ���ʽ�����
						cout << "->" << "V" << pEdge->adjvex;
						visited[pEdge->adjvex] = true;
						//�洢�������ı�
						SpanningTree[tj][0] = j;
						SpanningTree[tj][1] = pEdge->adjvex;
						tj++;
					}
						
				}
			}
		}
	}
	printTree();//��ӡ�������ı߼�
	cout << "***********************************************************" << endl;
}