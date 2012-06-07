#include <stdio.h>
#include "linked_list.h"
void LinkList::print() {
	Node *p = head;
	while (p->next != NULL) {
		p = p->next;
		printf("%4d", p->value);
	}
	printf("\n");
}

LinkList::LinkList() {
	// head is a sentinal
	Node *nd = new Node(-1);
	head = last = nd;
	count = 0;
}

LinkList::~LinkList() {
	while(head != NULL) {
		Node *p = head;
		head = head->next;
		delete p;
	}
}

void LinkList::append(int value) {
	Node *nd = new Node(value);
	last->next = nd;
	last = nd;
	count++;
}

bool LinkList::remove(int value) {
	if(this->empty()) {
		return false;
	}
	Node *p = head->next, *q = head;
	while (p != NULL) {
		if (p->value == value) {
			q->next = p->next;
			if(p == last)
				last = q;
			delete p;
			count--;
			return true;
		}
		q = p;
		p = p->next;
	}
	return false;
}