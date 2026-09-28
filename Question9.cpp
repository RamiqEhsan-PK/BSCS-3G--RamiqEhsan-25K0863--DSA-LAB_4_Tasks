#include <iostream>
using namespace std;

class Node
{
public:
    int ID;
    int severity;
    Node *next;
    Node *prev;

    Node(int id, int s) : ID(id), severity(s) { next = prev = nullptr; }
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

    void insertAtHead(int id, int s)
    {
        Node *toInsert = new Node(id, s);
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
            cout << "[ID:" << temp->ID << ", Sev:" << temp->severity << "]";
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }

    void shellsort()
    {
        Node *Arr[size];
        Node *temp = head;
        int index = 0;
        while (temp != nullptr)
        {
            Arr[index++] = temp;
            temp = temp->next;
        }

        for (int gap = size / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < size; i++)
            {
                int j = i - gap;
                Node *Key = Arr[i];

                while (j >= 0 && Arr[j]->severity > Key->severity)
                {
                    Arr[j + gap] = Arr[j];
                    j -= gap;
                }
                Arr[j + gap] = Key;
            }
        }

        for (int i = 0, j = 1; i < size - 1; i++, j++)
        {
            Arr[i]->next = Arr[j];
            Arr[j]->prev = Arr[i];

            if (i == 0)
            {
                head = Arr[i];
                Arr[i]->prev = nullptr;
            }
            if (j == size - 1)
            {
                tail = Arr[j];
                Arr[j]->next = nullptr;
            }
        }
    }
};

int main()
{
    DoublyLinkedList patients;
    patients.insertAtHead(106, 30);
    patients.insertAtHead(105, 60);
    patients.insertAtHead(104, 10);
    patients.insertAtHead(103, 80);
    patients.insertAtHead(102, 20);
    patients.insertAtHead(101, 50);
    cout << "Input: ";
    patients.display();

    patients.shellsort();
    cout << endl
         << "Output: ";
    patients.display();
    return 0;
}