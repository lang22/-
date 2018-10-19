#include"LoopList.h"
void MakePanel() {
	cout << "***************************************" << endl;
	cout << "JoeohLoop Game!" << endl;
	cout << "1.Create a new JoephLoop." << endl;
	cout << "2.Start game!" << endl;
	cout << "3.Exit!" << endl;
	cout << "Please enter a number as your choice! " << endl;
	cout << "***************************************" << endl;
}
void Initiate(int n) {
	LoopList* head = new LoopList();
	LoopList* tail = new LoopList();
	for (int i = 1; i <= n; i++) {
		int password = 0;
		cin >> password;
		LoopList* temp = new LoopList(i,password);
		head->next = temp;
		temp->next = tail;
		head = temp;
		tail = temp;
	}
	tail->next = head;
}
int main() {
	int choice = 0;
	while (true)
	{
		MakePanel();
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "How much passwords do you want? Enter a number!" << endl;
			int n ; cin >> n;

		case 2:
		case 3: return 0; break;
		default:
			cout << "Warning! You bad!Invalid number!" << endl;
			cout << "Please resume a new number!" << endl;
			break;
		}
	}
	
	return 0;
}