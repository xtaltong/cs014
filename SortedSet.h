#include "IntList.h"
using namespace std;
//SortedSet(): The default constructor initializes an empty set.
class SortedSet: public IntList{
    public:
    SortedSet();
    //The copy constructor initializes the set to be a copy of the set passed in. Use the IntList copy constructor.
    SortedSet(const SortedSet &);
    //A constructor that is passed an IntList instead of a SortedSet. It should initialize the set using the values in the IntList. 
    //Again, you can use the IntList copy constructor and then remove all of the duplicates and sort the remaining values.
    SortedSet(const IntList &); 
    //The destructor needs to deallocate all dynamically allocated memory that the IntList destructor will not already deallocate.
    //You may very well find that this function does not need to do anything.
    ~SortedSet();
    //This function returns true if the value in data is a member of the set, otherwise false.
    bool in(int data)const;
    //This function returns a SortedSet object that is the union of 2 SortedSet objects, the left and right operands of this binary operator. 
    //A union of 2 sets is a set that consists of all of the distinct elements of both sets combined. That is, all of the values in both sets, minus any duplicates.
    //sset1=sset2 | sset3
    const SortedSet operator|(const SortedSet &)const;
    //This function returns a SortedSet object that is the intersection of 2 SortedSet objects, the left and right operands of this binary operator. 
    //An intersection of 2 sets is a set of all elements that are in both sets. That is, all of the values that are in both the left operand and the right operand.
    //sset1 = sset2 & sset3;
    const SortedSet operator&(const SortedSet &)const;
    //This function adds the value in data to the set. 
    //It needs to make sure data does not already exist in the set (no duplicates) and that it is inserted in the proper position (in ascending order).
    void add(int data);
    //Override this function so that it inserts the value in data in the proper position (in ascending order) 
    //only if the value does not already exist in the set (no duplicates).
    void push_front(int data);
    //Override this function so that it inserts the value in data in the proper position (in ascending order) 
    //only if the value does not already exist in the set (no duplicates).
    //See specs for push_front above. The same rationale for overriding applies to this function
    void push_back(int data);
    //Override this function so that it does not insert duplicates.
    void insert_ordered(int data);
    //This function is the union-assign operator function. It returns a union of the left and right operands, 
    //but also sets the left operand's value to be that union as well.
    //See operator| function specs above.
    SortedSet operator|=(const SortedSet &);
    //This function is the intersection-assign operator function. 
    //It returns an intersection of the left and right operands, but also sets the left operand's value to be that intersection as well.
    SortedSet operator&=(const SortedSet &);
    

}; 