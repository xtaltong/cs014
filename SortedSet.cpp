#include <iostream>
#include <ostream>
#include "IntList.h"
#include "SortedSet.h"

using namespace std;

SortedSet::SortedSet():IntList(){}
SortedSet::SortedSet(const SortedSet &set):IntList(set){}
SortedSet::SortedSet(const IntList &list):IntList(list){
    remove_duplicates();
    selection_sort();
}
SortedSet::~SortedSet(){
    clear();
}    
//This function returns true if the value in data is a member of the set, otherwise false.
bool SortedSet::in(int data)const{
    IntNode *ptr = this->head;
    if(empty()){
        return false;
    }
    else{
        while(ptr != nullptr){
            if (data == ptr -> data){
                return true; 
            }
            else{
                ptr = ptr -> next; 
            }
        }
        //comparing data inside IntNode to user inputted data
    }
    return false;
}
//This function returns a SortedSet object that is the union of 2 SortedSet objects, the left and right operands of this binary operator. 
//A union of 2 sets is a set that consists of all of the distinct elements of both sets combined. That is, all of the values in both sets, minus any duplicates.
//sset1=sset2 | sset3
const SortedSet SortedSet::operator|(const SortedSet & setA)const{
    SortedSet temp;
    if(empty()){
        if(!setA.empty()){
            temp = setA;
        }
        return temp;
    }
    else if(setA.empty()){
        for(IntNode *i = head; i != nullptr; i = i->next){
            temp.add(i->data);
        }
        return temp;
    }
    else{
        for(IntNode *i = head; i != nullptr; i = i->next){
            temp.add(i->data);
        }
        for(IntNode *i = setA.head; i != nullptr; i = i->next){
            temp.add(i->data);
        }
    }
    return temp; 
}
//This function returns a SortedSet object that is the intersection of 2 SortedSet objects, the left and right operands of this binary operator. 
//An intersection of 2 sets is a set of all elements that are in both sets. That is, all of the values that are in both the left operand and the right operand.
//sset1 = sset2 & sset3;
const SortedSet SortedSet::operator&(const SortedSet & setA)const{
    SortedSet intersect;
    if(empty() || setA.empty()){
        return intersect;
    }
    else{
        for(IntNode *i = setA.head; i != nullptr; i = i->next){
            if(in(i->data)){
                intersect.add(i->data);
            }
        }
    }
    return intersect;
}
//This function adds the value in data to the set. 
//It needs to make sure data does not already exist in the set (no duplicates) and that it is inserted in the proper position (in ascending order).
void SortedSet::add(int data){

    if(!(in(data))){
        IntList::insert_ordered(data);
    }
}
//Override this function so that it inserts the value in data in the proper position (in ascending order) 
//only if the value does not already exist in the set (no duplicates).
void SortedSet::push_front(int data){
    add(data);
}
//Override this function so that it inserts the value in data in the proper position (in ascending order) 
//only if the value does not already exist in the set (no duplicates).
//See specs for push_front above. The same rationale for overriding applies to this function
void SortedSet::push_back(int data){
    add(data);
}
//Override this function so that it does not insert duplicates.
void SortedSet::insert_ordered(int data){
    add(data);
}
//This function is the union-assign operator function. It returns a union of the left and right operands, 
//but also sets the left operand's value to be that union as well.
//See operator| function specs above.
SortedSet SortedSet::operator|=(const SortedSet & setA){
    SortedSet temp;
    SortedSet unionTemp;
    
    for(IntNode *i = head; i != nullptr; i = i->next){
        temp.add(i->data);
    }
    unionTemp = temp | setA;
    
    for(IntNode *i = unionTemp.head; i != nullptr; i = i->next){
        add(i->data);
    }
    return unionTemp;   
}
//This function is the intersection-assign operator function. 
//It returns an intersection of the left and right operands, but also sets the left operand's value to be that intersection as well.
SortedSet SortedSet::operator&=(const SortedSet &setA){
    SortedSet temp;
    SortedSet interTemp;
    
    for(IntNode *i = head; i != nullptr; i = i->next){
        temp.add(i->data);
    }
    if(setA.empty()){
        this->head = nullptr;
        this->tail = nullptr;
        return setA;
    }
    interTemp = temp & setA;
    clear();
    
    for(IntNode *i = interTemp.head; i != nullptr; i = i->next){
        add(i->data);
    }
    return interTemp;
}
    