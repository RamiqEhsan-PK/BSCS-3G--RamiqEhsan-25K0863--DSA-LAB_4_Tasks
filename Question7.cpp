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

    DoublyLinkedList() { head = tail = nullptr; }

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

    void deleteDuplicates()
    {
        Node *tempA = head;

        while (tempA != nullptr)
        {
            Node *tempB = head;
            while (tempB != nullptr)
            {
                if (tempA->data == tempB->data && tempA != tempB)
                {
                    Node *todelete = tempB;
                    tempB = tempB->next;

                    tempA->next = tempB;
                    tempB->prev = tempA;
                    delete todelete;
                }
                else
                {
                    tempB = tempB->next;
                }
            }
            tempA = tempA->next;
        }
    }
};

int main()
{
    DoublyLinkedList patients;
    patients.insertAtHead(4);
    patients.insertAtHead(3);
    patients.insertAtHead(3);
    patients.insertAtHead(3);
    patients.insertAtHead(2);
    patients.insertAtHead(1);
    patients.insertAtHead(1);

    cout << "Input: ";
    patients.display();

    patients.deleteDuplicates();
    cout << endl
         << "Output: ";
    patients.display();
    return 0;
}