#include<iostream>
using namespace std;
class mstack
{
	int *st;
	int tope;
	int cap;
	int min;
public:
	mstack(int cap){
		this->cap=cap;
		st = new int[cap];
		tope=-1;
	}
	void push(int data)
	{
		if(tope == cap-1)
		{
			cout<<"stack overflow\n";
			return;
		}
		if(tope==-1)		// for the initial element
		{
			min = data;
			tope++;
			st[tope]=data;
		}
		else if(min>data){    		// if the data is minimum than the min then we change the min and store a "fake minimum" value which will help us in top() and pop()
			tope++;
			st[tope]=2*data - min;
			min = data;
		}
		else{
			tope++;					// for the data greater than the min
			st[tope]=data;	
		}
	}
	int top(){
		if(tope==-1)
		{
			cout<<"stack is empty \n";
			return -1;
		}
		if(st[tope]<min)		// if the top is min. than the min that mean it's a "fake value" so we return min
			return min;
		return st[tope];
	}
	void pop()
	{
		if(tope == -1)
		{
			cout<<"stack underflow\n";
			return ;
		}
		if(st[tope]<min)	// if the top is min. than the min then that mean we have to re- assign the min value(which we will do with the help of "fake " and min value)
		{
			min = 2*min - st[tope];
		}
		st[tope]=0;
		tope--;
	}
	int size(){
		return tope+1;
	}
	int minn(){
		return min;
	}
	
};
int main(){
	mstack st(10);
	st.push(23);
	st.push(13);
	st.push(20);
	st.push(10);
	st.push(32);
	st.push(2);
	st.push(-1);
	st.push(123);
	st.push(143);
	st.push(143);
	st.push(143);

	st.push(193);
	st.push(-3);
	while(st.size()>0)
	{
		cout<<st.top()<<"--"<<st.minn()<<endl;
		st.pop();
	}
	st.pop();
}