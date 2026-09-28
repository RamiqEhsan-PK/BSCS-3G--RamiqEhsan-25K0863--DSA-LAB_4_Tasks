// Question 4
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

    void Sort(Node *head)
    {
        tail = head;
        while (tail->next != nullptr)
            tail = tail->next;

        Node *end = tail;
        Node *lastswapped;
        Node *temp;

        while (end != head && end != nullptr)
        {
            lastswapped = nullptr;
            temp = head;

            while (temp->next != end)
            {
                if (temp->PassengerID > temp->next->PassengerID)
                {
                    swap(temp->PassengerID, temp->next->PassengerID);
                    lastswapped = temp;
                }
                temp = temp->next;
            }

            end = lastswapped;
        }
    }

    Node *MergeTwoLists(Node *Head1, Node *Head2)
    {
        Node *temp = Head1;

        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = Head2;
        Sort(Head1);
        return Head1;
    }
};

int main()
{
    LinkedList List1, List2;

    List1.InsertAtHead(7);
    List1.InsertAtHead(5);
    List1.InsertAtHead(3);
    List1.InsertAtHead(1);

    List2.InsertAtHead(8);
    List2.InsertAtHead(6);
    List2.InsertAtHead(4);
    List2.InsertAtHead(2);

    cout << "Chain A: HEAD1->";
    List1.display();
    cout << endl
         << "Chain B: Head2->";
    List2.display();

    LinkedList Merged;

    Merged.head = Merged.MergeTwoLists(List1.head, List2.head);
    cout << endl
         << "Merged and sorted: Head->";
    Merged.display();
}