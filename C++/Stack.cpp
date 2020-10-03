#include<iostream>
using namespace std;
class Stack
{
	private :
		int *a;
		int l,top;
	public:
		Stack(int x)
		{
			a=new int[x];
			l=x;
			top=-1;
		}
		~Stack()
		{
			delete []a;
		}
		operator ++()
		{
			if(top==(l-1))
			{
				cout<<"\n Stack is overflow. \n";
			}
			else
			{
				top++;
				int k;
				cout<<" \n Enter the element to be entered in stack ";
				cin>>k;
				a[top]=k;
			}
		}
		operator --()
		{
			if(top==(-1))
			{
				cout<<"\n Stack is underflow. \n";
			}
			else
			{
				cout<<"\n Popped out element is : "<<a[top--]<<"\n";
			}
		}
		void display()
		{
			int i;
			cout<<"\n Stack elements : \n";
			for(i=top;i>=0;i--)
			{
				cout<<a[i]<<",";
			}
			cout<<"\n";
		}
};
int main()
{
	int l,c;
	cout<<"Enter the length of stack ";
	cin>>l;
	Stack ob(l);
	while(1)
	{
		cout<<"Enter 1 to push. \n";
		cout<<"Enter 2 to pop. \n";
		cout<<"Enter 3 to display. \n";
		cout<<"Enter 4 to exit. \n";
		cout<<"Enter your choice ";
		cin>>c;
		switch(c)
		{
			case 1:				
				++ob;
				break;
			case 2:
				--ob;
				break;
			case 3:
				ob.display();
				break;
			case 4:
				ob.~Stack();
				exit(1);
			default :
				cout<<"\n Wrong choice.\nEnter a number between 1 - 4. \n";
		}
	}
	return 0;
}

