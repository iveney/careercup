#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// simple implementation of single linked list in C++

class Node
{
public:
	Node (int v) : value(v), next(NULL) {}
	virtual ~Node (){}

	int value;
	Node *next;
};

class LinkList
{
public:
	LinkList ();
	void append(int value);
	bool remove(int value);
	Node *find(int value);
	int size() { return count; }
	bool empty() { return head == last; }
	virtual ~LinkList ();
	void print();

//private:
	Node *head;
	Node *last;
	int count;
};

#endif /* end of include guard: LINKED_LIST_H */