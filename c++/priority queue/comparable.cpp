#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class yoyo
{
 public:
 	int x,y;
 	yoyo(int z,int b):
 		x(z),y(b)
 	{
 	}
 	
 	bool operator <(const yoyo &o)const		// "<" operator overloading so that priority queue can arrange them 
 	{
 		return (this->x)>(o.x);
 	}
}; 

class comp		// why are we using class ?why not directly overload it? we can do this too but then all other operation that use that operator will behave according to this overloaded operator which we don't want 
					//hence we use class so that we can overload this operator only for priority_queue
{
public:
	bool operator () (const int &a, const int &b) const	// don't know why but we need to overload "()" instead of "<"
	{
		return a>b;
	}
	
};

int main(){
	priority_queue<int> pq;			// by default desc. order(greater then lesser)
	pq.push(10);
	pq.push(-10);
	pq.push(110);
	pq.push(1110);
	pq.push(13230);
	pq.push(-2310);
	// for(auto x:pq)			// don't work here but work in java
	// 	cout<<x<<" ";
	// cout<<endl;
	while(pq.size()>0){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;

	priority_queue<yoyo>pq2;
	pq2.push(yoyo(123,123));
	pq2.push(yoyo(12,123));
	pq2.push(yoyo(1123,123));
	pq2.push(yoyo(33,123));
	pq2.push(yoyo(-1123,123));
	pq2.push(yoyo(123423,123));
	while(pq2.size()>0){
		cout<<pq2.top().x<<" "<<pq2.top().y<<endl;
		pq2.pop();
	}
	cout<<endl;

	priority_queue<int,vector<int>,comp>p3;		// way to add a class for helping in comparison
	p3.push(12);
	p3.push(1232);
	p3.push(-12);
	p3.push(12342);
	p3.push(-23412);
	while(p3.size()>0)
	{
		cout<<p3.top()<<" ";
		p3.pop();
	}
	cout<<endl;

}