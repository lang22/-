#include<iostream>
#include"ADL.h"
#include"Traverse.h"
using namespace std;
int main() {
	Graph G;
	CreateGraph(G);
	DFSTraverse(G);
	BFSTraverse(G);
	return  0;
}