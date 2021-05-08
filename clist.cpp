// //
// // Created by Christopher Dowd on 4/20/21.
// //

// #include "clist.hpp"

// //-----------------------------------------
// template <class T>
// Clist<T>::~Clist()
// {
//     while (head != nullptr)
//     {
//         Cell<T> *temp = head;
//         if (temp->next == head)
//         {
//             head = nullptr;
//             tail = nullptr;
//             current = nullptr;
//             delete temp;
//         }
//         else
//         {
//             head = head->next;
//             tail->next = head;
//             delete temp;
//         }
//     }
// }
// //-----------------------------------------
// template <class T>
// int Clist<T>::count()
// {
//     current = head;
//     // Iterate till end of list
//     do
//     {
//         current = next();
//         counter++;
//     } while (current != head);
//     return counter;
// }
// //-----------------------------------------
// template <class T>
// void Clist<T>::print(ostream &out) const
// {
//     Cell<T> *temp = head;
//     if (head == nullptr)
//     {
//         cout << "List is empty!\n";
//     }
//     else
//     {
//         while (temp != head)
//         {
//             return out << *temp->data;
//             temp = temp->next;
//         }
//     }
// }
// //-----------------------------------------
// template <class T>
// void Clist<T>::addItem(Cell<T> *item)
// {
// }
// //-----------------------------------------
// template <class T>
// void Clist<T>::init()
// {
//     if (head == nullptr)
//     {
//         cout << "List head is empty\n";
//     }
//     current = head;
// }
// //-----------------------------------------
// template <class T>
// void Clist<T>::remove()
// {
//     if (current == head)
//     {
//         if (tail == head)
//         {
//             head == nullptr;
//             tail = nullptr;
//             current == nullptr;
//         }
//         else
//         {
//             tail->next = head->next;
//             head = head->next;
//             current = tail;
//         }
//     }
// }
// //-----------------------------------------
// template <class T>
// T *Clist<T>::next()
// {
//     if (empty)
//     {
//         cout << "List is empty\n";
//     }
//     else
//     {
//         current = current->next;
//         return current->data;
//     }
// }
// //-----------------------------------------
// template <class T>
// bool Clist<T>::empty()
// {
//     if (counter == 0)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// //-----------------------------------------
