#include <iostream>
#include<vector>
#include<cmath>
using namespace std; 

int main(){
	vector<int>ar{5,6,10,100,10};
	int inc = ar[0];
	int ex = 0;
	for(int i =1;i<ar.size();i++)
	{
		int ninc = ex+ar[i];
		int nex = max(inc,ex);
		ex = nex;
		inc = ninc;
	}

	cout<<max(ex,inc)<<endl;
}