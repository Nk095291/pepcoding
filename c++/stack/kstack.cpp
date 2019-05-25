#include<iostream>

using namespace std;

class kstack
{
	int* da;
	int* pa;
	int* sha;
	int fh;
	public:
	kstack(int cap,int k ){
		// this->cap = cap;
		da = new int[cap];
		pa = new int[cap];
		sha = new int[k];
		fh =0;
		for(int i =0;i<cap-1;i++)
		{
			da[i]=0;
			pa[i]=i+1;
			cout<<pa[i]<<" ";
		}
		cout<<endl;
		pa[cap-1]=-1;
		for(int i =0;i<k;i++)
			sha[i]=-1;
	}	
	bool isfull()
	{
		return fh==-1;
	}
	bool isempty(int k)
	{
		return sha[k]==-1;
	}
	void push(int data , int k)
	{
		if(isfull())
		{
			cout<<"stack overflow\n";
			cout<<fh<<endl;
			return;
		}
		da[fh]=data;
		int temp = fh;
		fh = pa[fh];		//remove at first

		pa[temp]=sha[k];	//add at first
		sha[k]=temp;


	}
	int top(int k)
	{
		if(isempty(k))
		{
			cout<<"underflow\n";
			return -1;
		}
		return da[sha[k]];
	}
	void pop(int k)
	{
		if(isempty(k))
		{
			cout<<"underflow\n";
			return ;
		}
		da[sha[k]]=0;

		int temp = sha[k];
		sha[k]=pa[sha[k]];
		
		pa[temp]=fh;
		fh = temp;
	}
};

int main(){
	kstack st(10,3);
	int val =10;
	for(int i =0;i<3;i++)
	{
		for(int j =0;j<3;j++)
		{
			st.push(val,i);
			val+=10;
		}
	}
			st.push(val,0);
			st.push(val,0);

	for(int i =0;i<3;i++)
	{
		cout<<i<<"  ";
		while(st.isempty(i)==false)
		{
			cout<<st.top(i)<<" ";
			st.pop(i);
		}
		cout<<endl;
	}
}