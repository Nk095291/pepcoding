#include<iostream>
#include<vector> 
using namespace std;

void fillzarray(vector<int> &ar, string str)
{
	int l ,r,i;
	 i =1;
	 l=r=0;
	 while(i<str.size())
	 {
	 	if(i>r)
	 	{
	 		l=r=i;
	 		while(r<str.size() && str[r]==str[r-l])
	 			r++;
	 		r--;
	 		ar[i]=r-l+1;
	 	}
	 	else
	 	{
	 		if(ar[i-l]<r-i+1)
	 		{
	 			ar[i]=ar[i-l];
	 		}
	 		else
	 		{
	 			l=r=i;
		 		while(r<str.size() && str[r]==str[r-l])
		 			r++;
		 		r--;
		 		ar[i]=r-l+1;		
	 		}
	 	}
	 i++;
	 }
}

void patternMatching(string str, string pat)
{
	string newstr;
	newstr = pat + "$" + str;
	vector<int> z (newstr.size(),0);
	fillzarray(z,newstr);
	// for(int x:z)
	// 	cout<<x<<endl;
	for(int i=0;i<z.size();i++){
		if(z[i]==pat.size())
			cout<<i-pat.size()+1<<" ";
	}
	cout<<endl;

}

int main()
{
	 patternMatching("abcabcabc","ab");

}