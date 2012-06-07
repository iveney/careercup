// 2.1 Write code to remove duplicates from an unsorted linked list
#include <list>
#include <algorithm>
#include <iterator>
#include "linked_list.h"
using namespace std;

typedef LinkList List;
//typedef std::list<int> List;
//typedef std::list<int>::iterator ListIterator;

void remove_duplicate(List &l) {
	if(l.empty())
	{
		return;
	}
	Node *p = l.head->next, *q = NULL, *r = NULL;
	while(p != NULL) {
		q = p;
		r = p->next;
		while (r != NULL) {
			if(r->value == p->value)
			{
				q->next = r->next;
				delete r;
				r = q->next;
				l.count--;
				continue;
			}
			q = r;
			r = r->next;
		}
		p = p->next;
	}
}

int main (int argc, char const *argv[])
{
	List l;
	l.append(1);
	l.append(4);
	l.append(1);
	l.append(5);
	l.append(4);
	l.append(3);
	l.append(1);
	l.print();
	remove_duplicate(l);
	l.print();
//	copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
	return 0;
}