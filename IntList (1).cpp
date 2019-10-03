#include <iostream> 
#include <ostream>
#include "IntList.h"
#include "SortedSet.h"

using namespace std; 

IntList::IntList(){
    head = nullptr; 
    tail = nullptr; 
}

IntList::IntList(const IntList &cpy){

    if (cpy.empty()){
    head = nullptr; 
    tail = nullptr; 
    }
    else{
        IntNode *currentPointer = cpy.head; 
        IntNode *copyPointer = new IntNode (currentPointer -> data);
        head = copyPointer; 
        currentPointer = currentPointer -> next; 

        while (currentPointer){
            IntNode *temp = new IntNode(currentPointer -> data);
            copyPointer -> next = temp; 
            copyPointer = temp; 
            currentPointer = currentPointer -> next;
        }
        tail = copyPointer;
    }
}

IntList & IntList::operator=(const IntList &rhs){
    if (this == &rhs){
        return *this;
    }
    if(rhs.empty()) {
        head = nullptr; 
        tail = nullptr; 
    }

    clear();
    IntNode * woot = rhs.head;
    IntNode * hoot = new IntNode (woot -> data);

    while (woot != nullptr) {
        IntNode * toot = new IntNode (woot -> data);
        hoot -> next = toot;
        hoot = toot;
        woot = woot -> next;
    }
    tail = hoot;

    // for(IntNode *woot = rhs.head; woot != nullptr; woot = woot -> next){
    //     push_back(woot -> data);
    // }
    return *this;
}

IntList::~IntList(){
    while (head != 0){
        pop_front(); 
    }
}

bool IntList::empty() const{
    bool isEmpty = false; 

    if (head == nullptr){
        isEmpty = true; 
    }

    return isEmpty;
}

void IntList::display() const{

    if(empty()){
        cout << "hello rachel" << endl;
       return;
    }

    cout << (*head).data;
    IntNode *plcPointer = (*head).next;

    while(plcPointer != nullptr){
        cout << ' ' << (*plcPointer).data;
        plcPointer = (*plcPointer).next; 
    }
}

void IntList::push_front(int value){

    IntNode *tempPointer = new IntNode(value); 

    if(!head){
        head = tempPointer; 
        tail = tempPointer; 
    }
    
    else{
        tempPointer -> next = head;
        head = tempPointer;
    }
}

void IntList::push_back(int value){
 
    IntNode *temp = new IntNode(value);

    if (!head){
        head = temp;
        tail = head; 
    }
    else {
        tail -> next = temp;
        tail = temp;
    }
}

void IntList::pop_front(){

    if (head == 0){
        return;
    }

    IntNode *tempPointer = head -> next;
    delete head;
    head = tempPointer;

    if(head == nullptr){
        tail = nullptr;
    } 
}

void IntList::selection_sort(){

    IntNode *currentPointer = nullptr; 
    IntNode *smallest = nullptr; 
    IntNode *nextNode = nullptr; 

    for (currentPointer = head; currentPointer != 0; currentPointer = currentPointer -> next){
            smallest = currentPointer; 
            for (nextNode = currentPointer -> next; nextNode != 0; nextNode = nextNode -> next){
                       if((nextNode -> data) < (smallest -> data)){
                           smallest = nextNode;
                       } 
                    }
            swap(currentPointer -> data, smallest -> data);
        }
}

void IntList::insert_ordered(int value){
    

    // IntNode *tempPointer = new IntNode(value);
    // IntNode *currentPointer = nullptr; 
    // IntNode *previousPointer = nullptr; 

    // if (!head){
    //     push_front(value);
    // }
    // else if(head -> next == 0){
    //     if(head -> data >= value){
    //         push_front(value);
    //     }
    //     else{
    //         push_back(value);
    //     }
    // }
    // else if(head -> data >= value){
    //     push_front(value);
    // }
    // else if(tail -> data <= value){
    //     push_back(value);
    // }
    // else{
    //     previousPointer = head; 
    //     currentPointer = head -> next; 

    //     for(tempPointer = head; !(previousPointer -> data <= value && value <= currentPointer -> data); tempPointer = tempPointer -> next){
    //         previousPointer = tempPointer -> next; 
    //         currentPointer = tempPointer -> next -> next;
    //     }

    //     IntNode *list = new IntNode(value);
    //     previousPointer -> next = list; 
    //     list -> next = currentPointer;
    // }

    if ((value <= head -> data) || !head){
        push_front(value); 
    }
    else if (value >= tail ->data){
        push_back(value);
    }
    else if (head -> next == nullptr){
        if (head -> data > value){
            push_front(value); 
        }
        else{
            push_back(value); 
        }
    }
    else{
        IntNode *insert = new IntNode(value);
        IntNode *previous = head; 
        IntNode *curr = head -> next;

        for (IntNode *i = head; !((previous -> data <= value)&& (value <= curr -> data)); i = i -> next){
            previous = i; 
            curr = i -> next; 
        }
        previous -> next = insert; 
        insert -> next = curr; 
    }
} 

void IntList::remove_duplicates(){
    // IntNode *previous= nullptr; 
    // IntNode *current = nullptr; 
    // IntNode *node = nullptr;

    // for(node = head; node != 0; node = node -> next){
    //     previous= node;
    //     for(current = node -> next; current!= 0; current = current -> next){
    //         if(node -> data == current -> data){
    //             previous -> next = current -> next;
    //             if(current == tail){
    //                 tail = previous;
    //             }
    //             delete[] current;
    //             current = previous;
    //         }
    //         else{
    //             previous = previous -> next;
    //         }
    //     }
    // }

    IntNode *previousPointer = nullptr; 
    IntNode *currentPointer = nullptr; 
    IntNode *node = nullptr;

    for(currentPointer = head; currentPointer != 0; currentPointer = currentPointer -> next){
        previousPointer = currentPointer;
        for(node = currentPointer -> next; node != 0; node = node -> next){
            if(currentPointer -> data == node -> data){
                previousPointer -> next = node -> next;
                if(node == tail){
                    tail = previousPointer;
                }
                delete node;
                node = previousPointer;
            }
            else{
                previousPointer = previousPointer -> next;
            }
        }
    }
}

void IntList::clear(){
    while (head != 0){
        pop_front();
    }
    head = 0; 
    tail = 0; 
}

ostream & operator<<(ostream &out, const IntList &rhs){

    IntList shtuff (rhs);

   if (shtuff.head == nullptr){
       return out; 
   }

   IntNode *stream = shtuff.head; 
   while(stream != nullptr){
       out << stream -> data;
       if(stream -> next != nullptr){
           out << " ";
       }
    //    out << stream -> data;
       stream = stream -> next; 
   }

    return out; 

}

IntNode IntList::* min(IntNode*){
    return nullptr;
}

void IntList::copy(const IntList &){
    return; 
}

