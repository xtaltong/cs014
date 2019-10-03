#ifndef INTLIST_H
#define INTLIST_H
#include <iostream>
#include <ostream>

using namespace std;

struct IntNode {
	int data;
	IntNode *next;
	IntNode(int data) : data(data), next(nullptr) { }
};

class IntList {
 protected:
	IntNode *head;
	IntNode *tail;
 public:
	IntList();
	~IntList();
	void display() const;
	void push_front(int);
	void pop_front();
	bool empty() const;
    //the copy constructor. Make sure this performs deep copy.
    IntList(const IntList &cpy);
    //the overloaded assignment operator. Make sure this performs deep copy.
    IntList & operator=(const IntList &rhs); 
    //Inserts a data value (within a new node) at the back end of the list.
    void push_back(int value);
    //all IntNodes in the IntList. Don't forget to set both head and tail to appropriate values for an empty list.
    void clear(); 
    //Sorts the integers in the list into ascending order. Do NOT move the nodes, just the integers.
    void selection_sort();
    //Inserts a data value (within a new node) in an ordered list. Assumes the list is already sorted in ascending order
    //(i.e., Do not sort the list first, assume the list is already is sorted.) This function loops through the list until if finds the correct position for the new data value and then inserts the new IntNode in that location. This function may NOT ever sort the list.
    void insert_ordered(int value);
    //Removes all duplicate data values (actually removes the nodes that contain the values) within the list. Always remove just the later value within the list when a duplicate is found. This function may NOT ever sort the list.
    void remove_duplicates();
    //A global friend function that outputs to the stream all of the integer values within the list on a single line, each separated by a space. This function does NOT send to the stream a newline or space at the end.
    friend ostream & operator<<(ostream &out, const IntList &rhs);
    private:
    IntNode * min(IntNode*);
    void copy(const IntList &);

};

#endif

