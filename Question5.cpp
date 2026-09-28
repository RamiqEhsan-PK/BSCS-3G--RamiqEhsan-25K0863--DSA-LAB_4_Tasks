// Question 5
#include <iostream>
using namespace std;

class Node
{
public:
    int PassengerID;
    Node *next;

    Node(int d) : PassengerID(d), next(nullptr) {};
};

class LinkedList
{
public:
    Node *head, *tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    bool isEmpty() { return head == nullptr; }

    void InsertAtHead(int d)
    {
        Node *toInsert = new Node(d);

        if (isEmpty())
        {
            head = tail = toInsert;
        }
        else
        {
            toInsert->next = head;
            head = toInsert;
        }

        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
    }

    void InsertExistingNodeAtTail(Node *toInsert)
    {
        if (isEmpty())
        {
            head = tail = toInsert;
        }
        else
        {
            tail->next = toInsert;
            tail = toInsert;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << "[" << temp->PassengerID << "]->";
            temp = temp->next;
        }
    }
};

Node *findJunction(LinkedList &A, LinkedList &B)
{
    Node *tempA;
    Node *tempB = B.head;
    Node *Junction = nullptr;

    while (tempB != nullptr && Junction == nullptr)
    {
        tempA = A.head;
        while (tempA != nullptr)
        {
            if (tempA == tempB)
            {
                Junction = tempA;
                break;
            }
            tempA = tempA->next;
        }
        tempB = tempB->next;
    }

    return Junction;
}

int main()
{
    LinkedList Common, A, B;

    A.InsertAtHead(1);
    A.InsertAtHead(4);

    cout << "Chain A:      ";
    A.display();
    cout << endl;

    Common.InsertAtHead(5);
    Common.InsertAtHead(4);
    Common.InsertAtHead(8);
    cout << "                        ";
    Common.display();
    cout << "NULL" << endl;

    B.InsertAtHead(1);
    B.InsertAtHead(6);
    B.InsertAtHead(5);
    cout << "Chain B: ";
    B.display();
    cout << endl;

    B.InsertExistingNodeAtTail(Common.head);
    A.InsertExistingNodeAtTail(Common.head);

    Node *Junction = findJunction(A, B);
    cout << endl
         << "Instersection point: [" << Junction->PassengerID << ']' << endl;
}