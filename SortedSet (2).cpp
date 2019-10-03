#include <iostream> 
#include <ostream>
#include "SortedSet.h"
#include "IntList.h"

using namespace std; 

//default constructor (empty list)
SortedSet::SortedSet() : IntList(){
}

//copy constructor
SortedSet::SortedSet(const SortedSet &cpy):IntList(cpy){
}

//constructor that passes through IntList instead of 
//SortedSet. Should initialize using IntList values
SortedSet::SortedSet(const IntList &cpy):IntList(cpy){
    IntList::remove_duplicates();
    IntList::selection_sort(); 
}

//destructor
SortedSet::~SortedSet(){
    clear();
} 

//accessor

//returns true if the calue in data is member of set
bool SortedSet::in(int data)const{
    bool isBool = false; 
    IntNode *current = head; 

    if(empty()){
        return isBool;
    }

    if(head == nullptr){
        return isBool; 
    }
    else{
        while(current != nullptr){
            if (data == current -> data){
                isBool = true; 
            }
            else{
                current = current -> next; 
            }
        }
    }

    return isBool;
} 

//returns object that is the union of 2 SortedSet objects
const SortedSet SortedSet::operator|(const SortedSet &s)const{

    SortedSet upoop; 

    if(empty()){
        if(!(s.empty())){
            upoop = s; 
        }
        return upoop;
    }

    else if(s.empty()){
        for (IntNode *woot = head; woot != nullptr; woot = woot -> next){
            upoop.add(woot -> data);
        }
        return upoop; 
    }

    else{
        for (IntNode *hoot = head; hoot != nullptr; hoot = hoot -> next){
             upoop.add(hoot -> data);
        }
        for (IntNode *woot = s.head; woot != nullptr; woot = woot -> next){
             upoop.add(woot -> data);
        }
    }

    return upoop; 

}

//returns object that is the intersections of 2 SortedSet 
//objects
const SortedSet SortedSet::operator&(const SortedSet &v)const{
    SortedSet ipoop; 

    if (empty() || v.empty()){
        return ipoop; 
    }

    else{
        for (IntNode *woot = v.head; woot != nullptr; woot = woot -> next){
            if(in(woot -> data)){
                ipoop.add(woot -> data);
            }
        }
    }
    return ipoop; 
}

//mutators

//adds the value in data to the set
void SortedSet::add(int data){

    if(!in(data)){
        IntList::insert_ordered(data);
    }
//     IntNode *temp = new IntNode(data);
//     IntNode *current = nullptr; 
//     IntNode *previous = nullptr; 

//     if(head == nullptr){
//         IntList::push_back(data);
//     }
//     else if (data > tail -> data){
//         IntList::push_back(data);
//     }
//     else if(data < head -> data){
//         IntList::push_front(data);
//     }

//     for (previous = head; previous != nullptr; previous = previous -> next){
//         current = previous -> next; 
//         if(previous -> data < temp -> data && current -> data > temp -> data){
//             for (IntNode *last = current; last!= nullptr; last = last -> next){
//                 if(last -> data == temp -> data){
//                     return;
//                 }
//             }
//             previous -> next = temp; 
//             temp -> next = current; 
//         }
//     }
// }
}
//override this function so that it inserts the value in 
//the proper position
void SortedSet::push_front(int data){
    add(data);
}

//overrides this function so that itserts the value in 
//the proper position
void SortedSet::push_back(int data){
    add(data);
}

//overrise this function so that it does not insert duplicates
void SortedSet::insert_ordered(int data){
    add(data);
}

//union-assign operator function 
SortedSet SortedSet::operator|=(const SortedSet &s){
   SortedSet poop; 
   SortedSet upoop; 
   IntNode *temp;
   IntNode *woot; 

   for (temp = head; temp != nullptr; temp = temp -> next){
       poop.add(temp -> data);
   }

    upoop = poop | s; 

    for (woot = upoop.head; woot != nullptr; woot = woot -> next){
        add(woot -> data);
    }

    return upoop;
   
}

//intersection-assign operator function
SortedSet SortedSet::operator&=(const SortedSet &v){
    SortedSet poop;
    SortedSet ipoop;  
    IntNode *woot; 
    IntNode *hoot; 

    for (woot = head; woot != nullptr; woot = woot -> next){
        poop.add(woot -> data);
    }

    if (v.empty()){
        this -> head = nullptr; 
        this -> tail = nullptr; 
        return v; 
    }


    ipoop = poop & v;  
    clear(); 
    
    for(hoot = ipoop.head; hoot != nullptr; hoot = hoot -> next){
        add(hoot -> data);
    }

    return ipoop;
    
}

