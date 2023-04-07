#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;
int main()
{
    DoublyLinkedList<int> a;
    a.insertAtTail(1);
    a.insertAtTail(2);
    a.insertAtTail(3);
    a.insertAtTail(4);
    a.insertAtHead(0);
    a.insertAt(66, 1);
    a.removeAt(1);
    a.replaceAt(100, 1);
    a.forwardTraversal();
    a.swap(1, 2);
    cout << "---------------------\n";
    a.forwardTraversal();
    cout << "---------------------\n";
    a.reverse();
    a.forwardTraversal();
    a.insertAtTail(50);
    cout << "---------------------\n";
    a.forwardTraversal();
    cout << "---------------------\n";
    a.backwardTraversal();
    cout << "---------------------\n";
    a.clear();
    a.forwardTraversal();
}