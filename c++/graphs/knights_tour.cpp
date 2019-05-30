#include <iostream>
#include<vector>
using namespace std;
bool isvalid(vector<vector<int>>& chess , int i ,int j)
{
	if(i<0||j<0||i>=chess.size()||j>=chess.size()||chess[i][j]!=-1)
		return false;
	return true;
}
int counter=0;
void knight_tour(vector<vector<int>>& chess , int i , int j, int mark)
{
	if(mark == chess.size()*chess.size()-1)
	{
		counter++;
		chess[i][j]=mark;
		cout<<"--------------------------"<<counter<<"----------------------\n";
		for(auto a:chess)
		{
			for(auto b:a)
			{
				cout<<b<<" ";
			}
			cout<<endl;
		}
		cout<<"--------------------------"<<counter<<"----------------------\n";
		chess[i][j]=-1;

	}
	chess[i][j]=mark;						// marking the current ver.	

	if(isvalid(chess,i+2,j+1))
		knight_tour(chess,i+2,j+1,mark+1);					// calling the nei. ver.

	if(isvalid(chess,i+2,j-1))
		knight_tour(chess,i+2,j-1,mark+1);

	if(isvalid(chess,i-2,j+1))
		knight_tour(chess,i-2,j+1,mark+1);
	
	if(isvalid(chess,i-2,j-1))
		knight_tour(chess,i-2,j-1,mark+1);
	
	if(isvalid(chess,i+1,j+2))
		knight_tour(chess,i+1,j+2,mark+1);

	if(isvalid(chess,i+1,j-2))
		knight_tour(chess,i+1,j-2,mark+1);

	if(isvalid(chess,i-1,j-2))
		knight_tour(chess,i-1,j-2,mark+1);
	
	if(isvalid(chess,i-1,j+2))
		knight_tour(chess,i-1,j+2,mark+1);
	chess[i][j]=-1;							// unmarking the current ver.

}

int main(){
	// vector<vector<int>> chess(5,vector<int>(5),-1);
	vector<vector<int>> chess(5,vector<int>(5,-1));
	// for(int i=0;i<chess.size();i++)
	// {
	// 	for(int j=0;j<chess.size();j++)
	// 	{
	// 		chess[i][j]=-1;
	// 	}

	// }

	knight_tour(chess,1,1,0);
}