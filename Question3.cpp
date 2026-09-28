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
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << "[" << temp->PassengerID << "]->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    Node *findMiddle(Node *head)
    {
        Node *slow, *fast;
        slow = fast = head;

        if (isEmpty())
            return nullptr;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    bool isPallindrome()
    {
        Node *mid = findMiddle(head);
        Node *end = tail;
        Node *start = head;
        bool valuesMatch = true;

        while (end != mid && valuesMatch)
        {
            valuesMatch = false;
            Node *temp = mid;
            while (temp->next != end)
                temp = temp->next;

            if (start->PassengerID == end->PassengerID)
                valuesMatch = true;

            start = start->next;
            end = temp;
        }

        if (valuesMatch)
            return true;
        return false;
    }
};

int main()
{
    LinkedList PIN;
    PIN.InsertAtHead(1);
    PIN.InsertAtHead(2);
    PIN.InsertAtHead(3);
    PIN.InsertAtHead(2);
    PIN.InsertAtHead(1);

    cout << "Input:" << endl;
    PIN.display();
    cout << "IsPallindrome?: ";
    if (PIN.isPallindrome())
    {
        cout << "TRUE";
    }
    else
    {
        cout << "FALSE";
    }
    return 0;
}