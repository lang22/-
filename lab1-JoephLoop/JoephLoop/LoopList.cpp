#include"LoopList.h"
LoopList::LoopList()
{
	pw = 0;
	index = 0;
	next = NULL;
}
LoopList::LoopList(int a, int b) {
	index = a;
	pw = b;

}
LoopList::~LoopList()
{
}
void LoopList::print() {
	cout << endl << pw << "  ";
}
void Delete(int a) {

}