#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node *next;
    Node *prev;
};
template <class T>
class DoublyLinkedList
{

    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    DoublyLinkedList()
    {
        head = tail = NULL;
        size = 0;
    }
    void insertAtHead(T value)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = value;
        if (head == NULL)
        {
            head = tail = newNode;
            newNode->next = newNode->prev = NULL;
        }
        else
        {
            newNode->next = head;
            newNode->prev = NULL;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    void insertAtTail(T value)
    {
        if (head == NULL)
        {
            insertAtHead(value);
        }
        else
        {
            Node<T> *newNode = new Node<T>;
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void insertAt(T value, int index)
    {
        if (index > size || index < 0)
        {
            cout << "ERROR: Index Out Of Range" << endl;
        }
        else
        {
            if (index == 0)
            {
                insertAtHead(value);
            }
            else if (index == size)
            {
                insertAtTail(value);
            }
            else
            {
                Node<T> *current = new Node<T>;
                current = head;
                Node<T> *newNode = new Node<T>;
                newNode->data = value;
                for (int i = 1; i < index; i++)
                {
                    current = current->next;
                }
                current->next->prev = newNode;
                newNode->next = current->next;
                newNode->prev = current;
                current->next = newNode;
            }
            size++;
        }
    }
    void forwardTraversal()
    {
        Node<T> *current = new Node<T>;
        current = head;
        cout << "[";
        while (current != NULL)
        {
            cout << current->data;
            if (current->next != NULL)
            {
                cout << "->";
            }
            current = current->next;
        }
        cout << "]" << endl;
    }
    void removeAtHead()
    {
        if (head == NULL)
        {
            cout << "List is already empty" << endl;
        }
        else if (head->next = NULL)
        {
            delete head;
            tail = head = NULL;
        }
        else
        {
            Node<T> *newNode = head;
            head = head->next;
            head->prev = NULL;
            delete newNode;
        }
        size--;
    }
    void removeAtTail()
    {
        if (head == NULL)
        {
            cout << "List is already empty" << endl;
        }
        else if (head->next == NULL)
        {
            delete head;
            tail = head = NULL;
        }
        else
        {
            Node<T> *newNode = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete newNode;
        }
        size--;
    }
    void removeAt(int index)
    {
        if (index > size - 1 || index < 0)
        {
            cout << "ERROR: Index Out Of Range" << endl;
        }
        else
        {
            if (index == 0)
            {
                removeAtHead();
            }
            else if (index == size - 1)
            {
                removeAtTail();
            }
            else
            {
                Node<T> *current = head;
                Node<T> *deletedNode = new Node<T>;
                for (int i = 1; i < index; i++)
                {
                    current = current->next;
                }
                deletedNode = current->next;
                current->next->next->prev = current;
                current->next = deletedNode->next;
                delete deletedNode;
            }
            size--;
        }
    }
    T retrieveAt(int index)
    {
        if (index > size - 1 || index < 0)
        {
            cout << "ERROR: Index Out Of Range" << endl;
            return 0;
        }
        else
        {
            if (index == 0)
            {
                return head->data;
            }
            else if (index == size - 1)
            {
                return tail->data;
            }
            else
            {
                Node<T> *current = head;
                for (int i = 1; i <= index; i++)
                {
                    current = current->next;
                }
                return current->data;
            }
        }
    }
    void replaceAt(T newValue, int index)
    {
        if (index > size - 1 || index < 0)
        {
            cout << "ERROR: Index Out Of Range" << endl;
        }
        else
        {
            if (index == 0)
            {
                head->data = newValue;
            }
            else if (index == size - 1)
            {
                tail->data = newValue;
            }
            else
            {
                Node<T> *current = head;
                for (int i = 1; i <= index; i++)
                {
                    current = current->next;
                }
                current->data = newValue;
            }
        }
    }
    bool isExist(T value)
    {
        Node<T> *current = head;
        while (current != NULL)
        {
            if (current->data == value)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    bool isItemAtEqual(T value, int index)
    {
        if (index < size && index >= 0)
        {
            if (index == 0)
            {
                if (head->data == value)
                {
                    return true;
                }
            }
            else if (index == size - 1)
            {
                if (tail->data == value)
                {
                    return true;
                }
            }
            else
            {
                Node<T> *current = head;
                for (int i = 1; i <= index; i++)
                {
                    current = current->next;
                }
                if (current->data == value)
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            cout << "ERROR: Index Out Of Range" << endl;
            return 0;
        }
    }
    void swap(int index1, int index2)
    {

        if (index1 >= 0 && index1 < size && index2 >= 0 && index2 < size)
        {
            Node<T> *firstEl = head, *secondEL = head;
            for (int i = 1; i <= index1; i++)
            {
                firstEl = firstEl->next;
            }
            for (int i = 1; i <= index2; i++)
            {
                secondEL = secondEL->next;
            }
            T temp = firstEl->data;
            firstEl->data = secondEL->data;
            secondEL->data = temp;
        }
        else
        {
            cout << "ERROR: Index Out Of Range" << endl;
        }
    }
    void reverse()
    {
        Node<T> *prev, *current, *after = new Node<T>;
        prev = NULL;
        current = head;
        after = current->next;
        while (after != NULL)
        {
            after = current->next;
            current->next = prev;
            current->prev = after;
            prev = current;
            current = after;
        }
        // current->next = prev;
        // current->prev = NULL;
        head = prev;
        current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        tail = current;
    }
    bool isEmpty()
    {
        if (size == 0)
        {
            return true;
        }
        return false;
    }
    int Size()
    {
        return size;
    }
    void clear()
    {
        Node<T> *current = head;
        Node<T> *prev = NULL;
        while (current != NULL)
        {
            prev = current;
            current = current->next;
            delete prev;
        }
        head = tail = NULL;
    }
    void backwardTraversal()
    {
        Node<T> *current = tail;
        cout << "[";
        while (current != NULL)
        {
            cout << current->data;
            if (current->prev != NULL)
            {
                cout << "->";
            }
            current = current->prev;
        }
        cout << "]" << endl;
    }
};