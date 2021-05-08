// /*  ----------------------------------------------------------------------------
// //  clist Header file                          clist.hpp
// //  Created by Eyad Esmail and Chris Dowd 
// //  Created on 5/7/2021
// */
#ifndef CANT_STOP_CLIST_HPP
#define CANT_STOP_CLIST_HPP
#include "tools.hpp"
#include "player.hpp"

template <class T> class CList;
template <class T> class Cell{
    friend class CList<T>;
    private:
        T* data;
        Cell* next;
        Cell(T* d, Cell* nx = NULL): data(d), next(nx) {}
        ~Cell() {}
};
//-----------------------------------------------------------------------------
template <class T> class CList{
    private:
        int counter;
        Cell<T>* head;
        Cell<T>* tail;
        Cell<T>* current;
    public:
        CList():counter(0), head(nullptr), tail(nullptr), current(nullptr) {}
        ~CList(){
            while(head != nullptr){
                if(head == tail){                 
                    head = NULL;
                    tail = NULL;
                    current = NULL;
                }else{
                    current = head;
                    head = head->next;
                    delete current;
                }
            }
        };
        int  count() const {return counter;}
        bool empty() const {return counter == 0;}
        void addItem (T* data);
        void init();
        T* next();
        void remove();
        ostream& printlist( ostream& out ) const;
        ostream& printcurrent( ostream& out ) const;
};
//-----------------------------------------------------------------------------
template <class T>
ostream& CList<T>::printlist( ostream& out) const{
   // cout << "in print" << endl;
    Cell<T> *temp = head;
    if (empty()) {
        return out << "list is empty" << endl;
    }else{
        out << left << setw(20) 
        <<"Name"<< setw(10) << "Color"<< setw(7) << "Score" << endl;
        for (int n = 0; n < counter; n++){
            temp->data->print(out);
            if (counter > 1){
                temp = temp->next;
            }
        }
        //cout << "exited print loop" << endl;
    }
    return out;
}
//-----------------------------------------------------------------------------
template <class T>
void CList<T>::addItem(T* data){
    Cell<T> * temp = new Cell<T>(data);
    //cout << "in add" << endl;
    if (empty()){
        head = temp;
        tail = head;
    }else{
        tail->next = temp;
        tail = tail->next;
        tail->next = head;
    }
    counter++;
}
//-----------------------------------------------------------------------------
template <class T>
void CList<T>::init(){  //sets current pointer to the first cell in the CList.
    if (empty()){
        cout << "List is empty\n";
    }else { 
        current = head;
    }
}
//-----------------------------------------------------------------------------
template <class T>
T* CList<T>::next() { //sets current pointer to the next cell in the CList.
    if(empty()){
        cout << "List is empty" << endl;
    }
    current = current->next;
    return current->data;
}
//-----------------------------------------------------------------------------
template <class T>
void CList<T>::remove(){ //remove the current Item
    Cell <T> * temp = current;
    if(empty()){
        cout << "List is empty" << endl;
    }else if (current == head){             //if item is head, set head to next
        tail->next = head->next;
        head = head->next;
        current = tail;
        //current -> next = head -> next;
        counter--;
    }else if (current == tail){             // if item is at tail 
        while (current->next != temp){
            current = current->next;
        }
        tail = current;
        current->next = temp->next;
        counter--;
    }else {                                 // normal condition
        while(current->next != temp){
            current = current->next; 
        }
        current->next = temp->next;
        counter--;
    }
    delete temp;
}
//-----------------------------------------------------------------------------
template <class T> // prints the data on current pointer
ostream& CList<T>::printcurrent( ostream& out) const{
    out << "current: " << endl;
    current->data->print(out);
    return out;
}

#endif //CANT_STOP_CLIST_HPP