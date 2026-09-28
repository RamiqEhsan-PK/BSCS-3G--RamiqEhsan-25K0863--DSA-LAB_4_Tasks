// Question 6
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    bool Even;
    Node *next;

    Node(int d) : data(d), next(nullptr)
    {
        Even = (d % 2 == 0);
    }
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
            cout << "[" << temp->data << "]->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void Sort_OddFirst()
    {

        Node *end = tail;
        Node *lastswapped = nullptr;

        while (end != nullptr)
        {
            lastswapped = nullptr;
            Node *temp = head;
            while (temp != end)
            {
                if (temp->Even && !temp->next->Even)
                {
                    swap(temp->data, temp->next->data);
                    swap(temp->Even, temp->next->Even);
                    lastswapped = temp;
                }
                else if (temp->Even == temp->next->Even)
                {
                    if (temp->data > temp->next->data)
                    {
                        swap(temp->data, temp->next->data);
                        swap(temp->Even, temp->next->Even);
                        lastswapped = temp;
                    }
                }
                temp = temp->next;
            }
            end = lastswapped;
        }
    }
};

int main()
{
    LinkedList passengers;
    passengers.InsertAtHead(7);
    passengers.InsertAtHead(4);
    passengers.InsertAtHead(6);
    passengers.InsertAtHead(5);
    passengers.InsertAtHead(3);
    passengers.InsertAtHead(1);
    passengers.InsertAtHead(2);

    cout << "Input: ";
    passengers.display();

    passengers.Sort_OddFirst();
    cout << endl
         << "Output: ";
    passengers.display();
}