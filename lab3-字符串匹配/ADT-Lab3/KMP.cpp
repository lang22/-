#include"Daclaration.h"
#include<string>
#define MAXSIZE 1000000
using namespace std;

int Next[MAXSIZE];
int nextVal[MAXSIZE];

void getNext(string s) {
	int length = s.length();
	int j = 1, k = 0;
	Next[0] = Next[1] = 0;
	while (j<length)
	{
		if (k == 0 || s[j] == s[k]) {
			j++;
			k++;
			Next[j] = k;
		}
		else {
			k = Next[k];
		}
	}
}
void getNextVal(string s) {
	int length = s.length();
	int j = 1, k = 0;
	nextVal[0] = nextVal[1] = 0;
	while (j<length)
	{
		if (k == 0 || s[j] == s[k]) {
			j++, k++;
			if (s[j] == s[k])
				nextVal[j] = nextVal[k];
			else
				nextVal[j] = k;
		}
		else
			k = nextVal[k];
	}
}
int Index_KMP(string s, string p, int& cnt) {
	getNext(p);
	int i = 0;
	int j = 0;
	int sLen = s.length();
	int pLen = p.length();
	while (i < sLen && j < pLen)
	{
		//�����j = 0�����ߵ�ǰ�ַ�ƥ��ɹ�����S[i] == P[j]��
		//����i++��j++      
		if (j == 0 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//�����j != 0���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���S[i] != P[j]����
			//���� i ���䣬j = next[j]      
			//next[j]��Ϊj����Ӧ��nextֵ        
			j = Next[j];
		}
		cnt++;
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}
int Index_KMP_PLUS(string s,string p, int& cnt) {
	getNextVal(p);
	int i = 0;
	int j = 0;
	int sLen = s.length();
	int pLen = p.length();
	while (i < sLen && j < pLen)
	{
		//�����j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�����S[i] == P[j]��
		//������i++��j++      
		if (j == 0 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//�����j != -1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���S[i] != P[j]����
			//���� i ���䣬j = nextVal[j]      
			//nextVal[j]��Ϊj����Ӧ��nextValֵ        
			j = nextVal[j];
		}
		cnt++;
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}