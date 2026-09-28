#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d) : data(d) { next = prev = nullptr; }
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    int size;

    DoublyLinkedList() : size(0) { head = tail = nullptr; }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void insertAtHead(int d)
    {
        Node *toInsert = new Node(d);
        if (isEmpty())
        {
            head = tail = toInsert;
        }
        else
        {
            toInsert->next = head;
            head->prev = toInsert;
            head = toInsert;
        }
        size++;
    }

    void display()
    {
        Node *temp = head;
        cout << "NULL";
        while (temp != nullptr)
        {
            if (temp == head)
            {
                cout << "<-";
            }
            else
            {
                cout << "<=>";
            }
            cout << '[' << temp->data << "]";
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }

    int tripletChecker(int X)
    {
        int count = 0;
        cout << "All triplets checked:" << endl
             << endl;
        for (Node *i = head; i != nullptr; i = i->next)
        {
            for (Node *j = i->next; j != nullptr; j = j->next)
            {
                for (Node *k = j->next; k != nullptr; k = k->next)
                {
                    int sum = i->data + j->data + k->data;
                    cout << "(" << i->data << "," << j->data << "," << k->data << ") = " << sum;
                    if (sum == X)
                    {
                        cout << "   Correct." << endl;
                        count++;
                    }
                    else
                    {
                        cout << "   Wrong." << endl;
                    }
                }
            }
        }
        return count;
    }
};

int main()
{
    DoublyLinkedList transactions;
    transactions.insertAtHead(5);
    transactions.insertAtHead(4);
    transactions.insertAtHead(3);
    transactions.insertAtHead(2);
    transactions.insertAtHead(1);

    transactions.display();
    int Matching = transactions.tripletChecker(6);

    cout << "Matching = " << Matching << endl;
    return 0;
}