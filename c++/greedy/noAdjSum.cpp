#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

class interval{
public:
	int start;
	int end;
	interval(int start, int end){
		this->start = start;
		this->end = end;
	}
	bool operator<(const interval & other)const{
		return (this->end) < other.end;
	}
};

int main(){
	vector<int>start{3,0,1,8,5,5};
	vector<int>end{4,6,2,9,9,7};
	vector<interval>ar;
	for(int i =0;i<start.size();i++)
		ar.push_back(interval(start[i],end[i]));
	sort(ar.begin(),ar.end());

	int minStartTime=ar[0].end;
	int count=1;
	for(int i =1;i<ar.size();i++)
	{
		if(ar[i].start>=minStartTime)
		{
			count++;
			minStartTime=ar[i].end;
		}
	}	
	cout<<count<<endl;
}