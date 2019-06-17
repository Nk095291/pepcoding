#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
int main(){
	vector<int>start {900,940,950,1100,1500,1800};
	vector<int>end{910,1200,1120,1130,1900,2000};
	sort(start.begin(),start.end());
	sort(end.begin(),end.end());
	int maxx = 0;
	int i =0;
	int j=0;
	int c=0;
	while(i<start.size()&&j<end.size())
	{

		if(start[i]<end[j])
		{
			c++;
			if(c>maxx)
				maxx=c;
			i++;
		}
		else{
			c--;
			j++;
		}
		
	}
	cout<<maxx<<endl;

}