#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
public:
	char data;
	bool eow;
	unordered_map<char,Node*> cmap;
	Node(int data)
	{
		this->data=data;
		this->eow=false;
	}
};

void display(Node *root,string asf)
{
	if(root->eow==true)
	{
		cout<<asf<< " "<<endl;
	}
	for(auto it =root->cmap.begin();it!=root->cmap.end();it++)
	{

			display(it->second,asf+(it->first) );
	}
}


void add (Node *root,string str)
{
	if(str.size()==0)
	{
		root->eow=true;
		return;
	}

	char s  = str[0];
		str=str.substr(1);
	if(root->cmap.count(s)==0)		// if the character is not present in the map then add it
	{
		Node* nextroot = new Node(s);
		root->cmap[s]=nextroot;		
	}
	add(root->cmap[s],str);
}

bool search(Node* root,string str)
{
	if(str.size()==0 && root->eow==true)
	{
		return true;
	}

	char s = str[0];
	str=str.substr(1);
	if(root->cmap.count(s)==0)
		return false;
	
	return search(root->cmap[s],str);
}


void remove(Node* root,string str)
{


	if(str.size()==0 )
	{
		root->eow=false;
		return;
	}
	char s = str[0];
	str = str.substr(1);

	if(root->cmap.count(s)==0)
		return ;
	
	remove(root->cmap[s],str);

	Node* child =root->cmap[s]; 
	if(child->cmap.size()==0 && child->eow==false)
	{
		root->cmap.erase(s);
		delete child; 						// important  otherwise there will be memory leak
	}
}
void displayTree(Node* root)
{
	cout<<root->data<<" ["<<root->eow<<" ]"<<" -> ";
	for(auto it =root->cmap.begin();it!=root->cmap.end();it++)
	{
		cout<<it->first<<" ";
	}
	cout<<endl;
	for(auto it =root->cmap.begin();it!=root->cmap.end();it++)
	{
		displayTree(it->second);
	}
}


int main()
{
	Node root ('$');

	add(&root,"and");
	add(&root,"ant");
	add(&root,"ask");
	add(&root,"an");
	add(&root,"see");
	add(&root,"seen");
	
	displayTree(&root);
	cout<<"----------------------"<<endl;
	remove(&root,"an");
	displayTree(&root);
	cout<<"----------------------"<<endl;

	remove(&root,"ant");
	displayTree(&root);
	cout<<"----------------------"<<endl;
	remove(&root,"and");
	displayTree(&root);
	cout<<"----------------------"<<endl;
	remove(&root,"se");
	displayTree(&root);
	cout<<"----------------------"<<endl;
	// cout<<search(&root,"and")<<endl;
	// cout<<search(&root,"an")<<endl;
	// cout<<search(&root,"antique")<<endl;
	// cout<<search(&root,"sea")<<endl;



}