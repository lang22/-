#pragma once
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
#define MAXVEX 31
#define MAXEDGE 436
typedef struct EdgeNode/* �߱���  */
{
	int adjvex;/* �ڽӵ���,�洢�ö����Ӧ���±� */
	struct EdgeNode* next = NULL; /* ����,ָ����һ���ڽӵ� */
}*Edge;

typedef struct Vertex //�����ڽ��
{
	int index;//���к�
	string data;//������
	struct EdgeNode* firstedge;//ָ����,ָ���һ���ڽӵ�(���һ���߱�)

}*V;
struct Graph 
{
	V vertices[MAXVEX];//���㼯
	int vexnum, arcnum;//������,����
};
void checkCin(int b, int min, int max) //�����쳣����
{
	while (cin.fail() || b<min || b>max)
	{
		cin.clear();
		cin.sync();
		cin.ignore();
//		cout << "*************************************************" << endl;
		cout << "***********�Ƿ�����!������������ȷֵ!************" << endl;
//		cout << "*************************************************" << endl;
		cout << "��������: ";
		cin >> b;
	}
}
//��ʼ�û���������
void MakePanel(int &choice) {
	cout << "***********************************************************" << endl;
	cout << "*************************ͼ�ı���**************************" << endl;
	cout << "***********************************************************" << endl;
	cout << "********1:����ͼ**********2:����ͼ***********3:�˳�********" << endl;
	cout << "***********************************************************" << endl;
	cout << "������ѡ��:";
	cin >> choice;
	if (choice == 3)
		exit(0);
}
void CreateGraph(Graph &G) //����һ��ͼ,���ڽӱ�洢
{
	int vn, an, vi, vj;//ͼ�ж�����,����,��(vi,vj)�Ķ˵����
	Edge pEdge;//�м�����߱�
	int choice;//�û�ѡ��
	MakePanel(choice);
	cout<<"******************"<<(choice==1?("��ʼ����һ������ͼ��"):("��ʼ����һ������ͼ��")) << "*****************" <<endl;
	cout << "�����붥����: ";
	cin >> vn;
	checkCin(vn, 1, MAXVEX);
	cout << "���������: ";
	cin >> an;
	checkCin(an, 0, MAXEDGE);
	G.vexnum = vn;
	G.arcnum = an; 
//	cout << "����������ÿ���������Ϣ." << endl;
	for (int i = 1; i <= vn; i++){
		G.vertices[i] = new Vertex();
		G.vertices[i]->index = i;
//		cout << "V" << i << ": ";
//	cin >> G.vertices[i]->data;//��ȡ������Ϣ
		//cout << endl;
		G.vertices[i]->firstedge = NULL;//�ڽ������ÿ�
	}
	cout << "����������ÿ����(vi,vj)�������˵�����к�.(��ʽ��'1 2')" << endl;
	for (int i = 1; i <= an;i++) {
		cout << "E" << i << ": ";
		cin >> vi >> vj;
		while (cin.fail() || vi<1 || vi>an || vj<1 || vj>an )
		{
			cin.clear();
			cin.sync();
			cin.ignore();
			cout << "***********�Ƿ�����!������������ȷֵ!************" << endl;
			cout << "E" << i << ": ";
			cin >> vi >> vj;
		}
		//��vj����vi���ڽӱ���
		pEdge = new EdgeNode();
		pEdge->adjvex = vj;
		pEdge->next = G.vertices[vi]->firstedge;
		G.vertices[vi]->firstedge = pEdge;
		if (choice==1)//��������ͼ,ͬʱ����(vj,vi)��
		{
			//��vi����vj���ڽӱ���
			pEdge = new EdgeNode();
			pEdge->adjvex = vi;
			pEdge->next = G.vertices[vj]->firstedge;
			G.vertices[vj]->firstedge = pEdge;
		}
		//��������ͼ,������(vj,vi)��
	}
//���ڽӱ��������,ð������
	for (int i = 1; i <= vn; i++) {
		Edge pEdge;
		int len = 1;
		//��ý����ڽӵ����
		for (pEdge = G.vertices[i]->firstedge; pEdge != NULL; pEdge = pEdge->next)
			len++;
		//���ڽӱ���next->adjvex����ð������
		for(int j=0;j<len;j++)
			for (pEdge = G.vertices[i]->firstedge; pEdge!=NULL&&pEdge->next!= NULL; pEdge = pEdge->next) {
				if (pEdge->adjvex > pEdge->next->adjvex) {
					//�ڽӱ������С���ŵ�ǰ��
					swap(pEdge->adjvex, pEdge->next->adjvex);
				}
					
			}
	}
}
