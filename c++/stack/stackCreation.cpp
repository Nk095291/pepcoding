#include<iostream>
using namespace std;
class mystack
{
	int* st;	// stack array
	int cap;	// capacity 
	int top;	// hold index of the top element
	public:

		mystack(int cap){
		 	this->cap = cap;
		 	top=-1;
		 	st=new int[cap];
		 }				// initialise the size of the stack array 
		
		~ mystack()
		{
			delete st;
		}
		void push(int k){

			top++;
			if(top==cap)
			{
				cout<<"overflow\n";
				return ;
			}
			st[top]=k;		
		}
		
		void pop()
		{
			if(top==-1)
			{
				cout<<"underflow\n";
				return ;
			}
			st[top]=0;
			top--;
			
		}
		int stop(){
			return st[top];
		}
		int size(){
			return top+1;
		}
};
int main()
{
	mystack st(5);
	st.push(10);
	st.push(20);

	st.push(30);
	st.push(40);
	st.push(50);
	while(st.size()>0)
	{
		cout<<st.stop()<<endl;
		st.pop();
	}

}