// Implement an algorithm to delete a node in the middle of a singly linked list, given only access to that node

#include <iostream>
#include <list>

using namespace std;

void printList (list<int> *);
void deleteNode (list<int> *, int);

int main(){
	list <int> l;
	list <int> :: iterator it = l.begin();
	for (int i = 0; i < 10; i++) {
		l.push_back(i);
	}
	printList(&l);

	it = l.begin();

	advance (it, 4);

	deleteNode(&l, 4);

	cout << endl;
	
	printList(&l);

        return 0;
}

void printList (list<int> * l) {
	list <int> :: iterator it;
	for (it = l->begin(); it != l->end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void deleteNode (list<int> * l, int k) {
	list <int> :: iterator it = l->begin();
	advance(it, k);
	it = l->erase(it);
}
