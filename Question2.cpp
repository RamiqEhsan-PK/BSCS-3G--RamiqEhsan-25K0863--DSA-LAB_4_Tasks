//QUESTION 2

#include <iostream>
using namespace std;

class Node
{
public:
int data;
Node* next;

Node(int d) : data(d)
{
	next = nullptr;
}
};

class LinkedList
{
	public:
	Node* head;
	Node* tail;
	
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}
	
	bool isEmpty()
	{
		return head == nullptr;
	}
	
	void InsertAtHead(int d)
	{
		Node* toInsert = new Node(d);
		
		if(isEmpty())
		{
			head = toInsert;
			tail = toInsert;
		}
		else
		{
			toInsert->next = head;
			head = toInsert;
		}
	}
	
	void display()
	{
		Node* temp = head;
		
		while(temp!=nullptr)
		{
			cout<<"["<<temp->data<<"]->";
			temp=temp->next;
		}
		cout<<"NULL"<<endl;
	}
	
	Node* findMiddle(Node* head)
	{
		if(head == nullptr)
		{
			return nullptr;
		}
		
		Node* SlowPtr = head;
		Node* FastPtr = head;
		
		while(FastPtr != nullptr && FastPtr->next != nullptr)
		{
			SlowPtr = SlowPtr->next;
			FastPtr=FastPtr->next->next;
		}
		
		return SlowPtr;
	}
};

int main()
{
	LinkedList Even, Odd;
	
	for(int i=6; i>0; i--)
	{
		Even.InsertAtHead(i);
		
	}
	for(int i=5; i>0; i--)
	{
		Odd.InsertAtHead(i);
	}
	
	cout<<"Odd List: "<<endl;
	Odd.display();
	Node* temp = Odd.findMiddle(Odd.head);
	cout<<"Odd Middle = "<<temp->data<<endl;
	
	cout<<endl<<"Even List: "<<endl;
	Even.display();
	temp = Even.findMiddle(Even.head);
	cout<<"Even Middle = "<<temp->data<<endl;
	
	return 0;
}
