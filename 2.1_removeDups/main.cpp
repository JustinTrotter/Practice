// Write code to remove duplicates from n unsorted linked list

// Learned how to pass by reference instead of passing pointers

#include <iostream>
#include <list>
#include <map>

using namespace std;

void deleteDups (list<int> &);
void printList (list<int> &);

int main(){
	list <int> l;
	list <int> :: iterator it = l.begin();
	for (int i = 0; i < 10; i++) {
		l.push_back(i);
		l.push_back(i);
	}
	printList(l);

	deleteDups(l);
	cout << endl;
	printList(l);

        return 0;
}

void deleteDups (list<int> & n) {
	map <int, bool> map;
	list <int> :: iterator it = n.begin();
	for (it = n.begin(); it != n.end(); it++){
		if (map.count(*it)){
			it = n.erase(it);
			it--;
		} else {
			map.insert(pair<int, int> (*it, true));
		}
	}
}

void printList (list<int> & l) {
	list <int> :: iterator it;
	for (it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
