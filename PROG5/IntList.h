#include <iostream>
#ifndef INTLIST_H
#define INTLIST_H
using namespace std;

struct IntNode {
    int value;
    IntNode *next;
    IntNode(int value) : value(value), next(nullptr) {}
};

class IntList {
 private:
	IntNode *head;
	IntNode *tail;
 public:
	IntList();
	~IntList();
    IntList(const IntList& cpy);
	void push_front(int value);
	void pop_front();
	bool empty() const;
	const int & front() const;
	const int & back() const;
    void push_back(int value);
    void clear();
    void selection_sort();
    void insert_ordered(int value);
    void remove_duplicates();
    IntList & operator=(const IntList&rhs);
	friend ostream & operator<<(ostream &, const IntList &);

};










#endif