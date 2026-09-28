#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList() { head = tail = nullptr; }

    bool isEmpty()
    {
        return head == nullptr;
    }

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

    void SoftwareBug(int Position)
    {
        Node *temp = head;
        for (int i = 1; i < Position; i++)
        {
            temp = temp->next;
        }
        tail->next = temp;
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

    Node *bugfix()
    {
        int buffer = 10;
        Node **NodesAlreadyPointedtowards = new Node *[buffer];
        for (int i = 0; i < buffer; i++)
        {
            NodesAlreadyPointedtowards[i] = nullptr;
        }

        bool bugfixed = false;
        Node *temp = head->next;
        Node *preTemp = head;
        int current = 0;
        while (!bugfixed)
        {
            for (int i = 0; i < current; i++)
            {
                if (temp == NodesAlreadyPointedtowards[i])
                {
                    preTemp->next = nullptr;
                    bugfixed = true;
                }
            }
            NodesAlreadyPointedtowards[current] = temp;
            preTemp = temp;
            temp = temp->next;
            current++;

            if (current == buffer)
            {
                buffer += 10;
                Node **temp = new Node *[buffer];

                for (int i = 0; i < buffer; i++)
                {
                    if (i < buffer - 10)
                    {
                        temp[i] = NodesAlreadyPointedtowards[i];
                    }
                    else
                    {
                        temp[i] = nullptr;
                    }
                }
                delete[] NodesAlreadyPointedtowards;
                NodesAlreadyPointedtowards = temp;
            }
        }

        delete[] NodesAlreadyPointedtowards;
        return temp;
    }

    void loopingdisplay()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp == tail)
            {
                cout << "[" << temp->data << "]->[" << temp->next->data << "]....(loops) " << endl;
                break;
            }
            cout << "[" << temp->data << "]->";
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList stops;
    stops.InsertAtHead(6);
    stops.InsertAtHead(5);
    stops.InsertAtHead(4);
    stops.InsertAtHead(3);
    stops.InsertAtHead(2);
    stops.InsertAtHead(1);

    cout << "Input: ";
    stops.display();

    stops.SoftwareBug(3);

    cout << endl
         << "Bug introduced:";
    stops.loopingdisplay();

    stops.bugfix();
    cout << endl
         << "Bug fixed: ";
    stops.display();
    return 0;
}