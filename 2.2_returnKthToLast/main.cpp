// Implement an algorithm to find the kth to last element of a singly linked list

#include <list>
#include <iostream>
using namespace std;

int kthToLast (list <int> *, int);
void printList (list <int> *);

int main(){
	list <int> l;
	list <int> :: iterator it = l.begin();
	for (int i = 0; i < 10; i++) {
		l.push_back(i);
	}
	printList(&l);

	cout << "Enter k: ";
	int k;
	cin >> k;
	cout << "kthToLast is: " << kthToLast(&l, k) << endl;
        return 0;
}

void printList (list<int> * l) {
	list <int> :: iterator it;
	for (it = l->begin(); it != l->end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int kthToLast (list <int> * l, int k) {
	list <int> :: iterator it1 = l->begin();
	list <int> :: iterator it2 = l->begin();

	// Move p1 k nodes into the list
	advance (it1, k + 2);

	while (*it1) {
		it1++;
		it2++;
	}
	return *it2;
}
