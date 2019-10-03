#include <iostream>
#include "IntList.h"

using namespace std;
//initializes empty list
IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}
//Deallocates all remaining dynamically allocated memory (all remaining IntNodes)
IntList::~IntList(){
    while(head != 0){
        pop_front();
    }
}
//Displays to a single line all of the int values stored in the list, each separated by a space. This function does NOT output a newline or space at the end
void IntList::display() const{
    if(head){
        cout << head->data;
        for(IntNode * current = head->next;current != 0;current = current->next){
            cout << " " << current->data;
        }
    }
    
}
//Inserts a data value (within a new node) at the front end of the list
void IntList::push_front(int var){
    IntNode * temp = new IntNode(var);
    if(!head){
        head = temp;
        tail = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}
//Removes the value (actually removes the node that contains the value) at the front end of the list. Does nothing if the list is already empty.
void IntList::pop_front(){
    if(!head){
        return;
    }
    IntNode * temp = head->next;
    delete head;
    head = temp;
    
    if(!head){
        tail = 0;
    }
}
//Returns true if the list does not store any data values (does not have any nodes), otherwise returns false.
bool IntList::empty() const{
    if(!head){
        return true;
    }
    return false;
}
//Returns a reference to the first value in the list. Calling this on an empty list causes undefined behavior.
// const int & IntList::front() const{
//     return head->data;
// }=
// //Returns a reference to the last value in the list. Calling this on an empty list causes undefined behavior.
// const int & IntList::back() const{
//     return tail->data;
// }
//the copy constructor. Make sure this performs deep copy.
IntList::IntList(const IntList &cpy){
    if(cpy.empty()){
        head = nullptr;
        tail = nullptr; 
    }
    else{
        IntNode *temp = cpy.head;
        IntNode *copy = new IntNode(temp->data);
        head = copy;
        temp = temp->next;
        while(temp){
            IntNode *donut = new IntNode(temp->data);
            copy->next = donut;
            copy = donut;
            temp = temp->next;
        }
        tail = copy;
    }
}
//the overloaded assignment operator. Make sure this performs deep copy.
IntList & IntList::operator=(const IntList &rhs){
    if(this != &rhs){
    if(rhs.empty()){
        head = nullptr;
        tail = nullptr;
    }
    else{
        clear();
        IntNode * temp = rhs.head;
        IntNode * copy = new IntNode(temp->data);
        head = copy;
        temp = temp->next;
    
    while(temp){
        IntNode *boba = new IntNode(temp->data);
        copy->next = boba;
        copy = boba;
        temp = temp->next;
    }
    tail = copy;
    }
    }
    return *this;
}
//Inserts a data value (within a new node) at the back end of the list.
void IntList::push_back(int value){
    IntNode *temp = new IntNode(value);
    
    if(head == 0){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
    
}
//all IntNodes in the IntList. Don't forget to set both head and tail to appropriate values for an empty list.
void IntList::clear(){
    while(head != 0){
        pop_front();
    }
    head = nullptr;
    tail = nullptr;
    
} 
//Sorts the integers in the list into ascending order. Do NOT move the nodes, just the integers.
void IntList::selection_sort(){
    for(IntNode *i = head; i != 0; i = i->next){
        IntNode *min = i;
        for(IntNode *j = i->next; j != 0; j = j->next){
            if(j->data < min->data){
                min = j;
            }
        }
        swap(min->data, i->data);
    }
}
//Inserts a data value (within a new node) in an ordered list. Assumes the list is already sorted in ascending order
//(i.e., Do not sort the list first, assume the list is already is sorted.) This function loops through the list until if finds the correct position for the new data value and then inserts the new IntNode in that location. This function may NOT ever sort the list.
void IntList::insert_ordered(int value){
    if(head == 0){
        push_front(value);
    }
    else if(head->next == 0){
        if(head->data >= value){
            push_front(value);
        }
        else{
            push_back(value);
        }
    }
    else if(head->data >= value){
        push_front(value);
    }
    else if(tail->data <= value){
        push_back(value);
    }
    else {
        IntNode *past = head;
        IntNode *temp = head->next;
        
        for(IntNode *i = head; !(past->data <= value && value <= temp->data); i = i->next){
            past = past->next;
            temp = i->next->next;
        }
        IntNode *cookie = new IntNode(value);
        past->next = cookie;
        cookie->next = temp;
    }
}
    
//Removes all duplicate data values (actually removes the nodes that contain the values) within the list. Always remove just the later value within the list when a duplicate is found. This function may NOT ever sort the list.
void IntList::remove_duplicates(){
    for(IntNode *current = head; current != 0; current = current-> next){
        IntNode *past = current;
        for(IntNode *curr = current->next; curr != 0; curr = curr->next){
            if(current->data == curr->data){
                past->next = curr->next;
                if(curr == tail){
                    tail = past;
                }
                delete curr;
                curr = past;
            }
            else{
                past = past->next;
            }
        }
    } 
}
//A global friend function that outputs to the stream all of the integer values within the list on a single line, each separated by a space. This function does NOT send to the stream a newline or space at the end.
ostream & operator<<(ostream &out, const IntList &rhs){
    if(rhs.head){
        out << rhs.head->data;
        for(IntNode *current = rhs.head->next; current != 0; current = current->next){
            out << " " << current->data;
        }
    }
    return out;
}
IntNode * IntList::min(IntNode*){
    return nullptr;
}
void IntList::copy(const IntList &){
    return;
}
