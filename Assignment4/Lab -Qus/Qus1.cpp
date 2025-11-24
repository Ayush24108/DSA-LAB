#include<iostream>

using namespace std;

#define SIZE 5
class Queue{
	int queue[SIZE];
	int front,rear;
	
	public:
		Queue(){
			front=-1;
			rear=-1;
		}
		
		
bool isEmpty()
{
	return (front==-1 && rear==-1);
}

bool isFull()
{
	return (rear==SIZE-1);
}

		
	void Enqueue(int x)
{
	if(isFull()){
		cout<<"Queue is full therefore no element can be entered"<<endl;
		return;
		}
		
		else if(isEmpty())
		{
			front=0;
			rear=0;
			
		}
		else{
			rear++;
			
		}
		
		queue[rear]=x;
}

void dequeue()
{
	if(isEmpty())
	{
		cout<<"Queue is empty"<<endl;
		return;
	}
else if(front==rear)
	{
		front=rear=-1;
		
	}
	else{
		front++;
	}
}

void peek(){
	
	if(isEmpty())
	{
		cout<<"Queue is empty"<<endl;
		return;
	}
	else{
		cout<<"First element is "<<queue[front]<<endl;
	}
}

void Display()
{
	if(isEmpty())
	{
		cout<<"Queue is empty"<<endl;
		return;
	}
	
	else{
		for(int i=front;i<=rear;i++)
		{
			cout<<queue[i]<<" ";
		}
		cout<<endl;
	}
}



};



int main ()

{
	Queue q;
	
	char choice;
	
	do{
		
		int op;
		cout<<"Enter 1 for enqueue"<<endl;
		cout<<"Enter 2 for deqeue"<<endl;
		cout<<"Enter 3 to check if it is empty"<<endl;
		cout<<"Enter 4 to check if it is full"<<endl;
		cout<<"Enter 5 to display queue"<<endl;
		cout<<"Enter 6 to peek"<<endl;
		cin>>op;
		
		switch(op)
		{
			case 1:
				int value;
				cout<<"Enter value for enqueue"<<endl;
				cin>>value;
				q.Enqueue(value);
				break;
			case 2:
				q.dequeue();
				break;
				
			case 3:
				if(q.isEmpty()){
					cout<<"Queue is empty"<<endl;
				}
				else{
					cout<<"Queue is not empty"<<endl;
				}
				break;
			case 4:
				if(q.isFull())
				{
					cout<<"Queue is full"<<endl;
				}
				
				else{
					cout<<"Queue is not full"<<endl;
				}
				break;
				
			case 5:
				q.Display();
				break;
			case 6:
				q.peek();
				break;
			
			default:
				cout<<"Invalid choice"<<endl;
				break;
				
				
		}
		cout<<"Do you wish to do something else(y/n)"<<endl;
		cin>>choice;
		
	}while(choice=='Y' || choice=='y');
}
