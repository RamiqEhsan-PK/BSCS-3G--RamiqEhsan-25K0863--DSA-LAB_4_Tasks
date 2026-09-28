//Question 1

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
	
	void reverseOrder()
	{
		Node* temp;
		Node* end = tail;
		
		while(end != head)
		{
			temp = head;
			while(temp->next!=end) temp=temp->next;
			
			end->next = temp;
			end = temp;
		}
		end->next = nullptr;
		temp = head;
		head = tail; 
		tail = temp;
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
};


int main()
{
	LinkedList recent;
	int data;
	for(int i = 0; i<5; i++)
	{
		cout<<"Enter data: ";
		cin>>data;
		recent.InsertAtHead(data);
	}
	cout<<endl;
	cout<<"Input:"<<endl;
	recent.display();
	recent.reverseOrder();
	cout<<endl;
	cout<<"After reverse: "<<endl;
	recent.display();
	return 0;
}
