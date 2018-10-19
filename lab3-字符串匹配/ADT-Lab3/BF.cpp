#include"Daclaration.h"
#include<iostream>
using namespace std;
int Index_BF(string m, string sub, int & cnt) {
	int i = 0, j = 0;
	while (i<m.length()&&j<sub.length())
	{
		if (m[i] == sub[j])
			i++, j++;
		else
			i = i - j + 1, j = 0;
		cnt++;
	}
	if (j == sub.length())
		return i - j;
	else
		return -1;

}