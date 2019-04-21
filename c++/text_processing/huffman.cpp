#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;
class Huffman{
public:
	unordered_map<char,string> encode;
	unordered_map<string,char> decode;
	class Node {
		public:
			char data;
			int f;
			Node* left=NULL;
			Node* right=NULL;
			Node(char data,int f)
			{
				this->data = data;
				this->f = f;
			}
			Node(const Node &n)
			{
				this->data = n.data;
				this->f= n.f;
				this->left = n.left;
				this->right = n.right;
			}

			bool operator>(const Node &other )const
			{
				return this->f > other.f;
			}
	};

	void traversal(Node *root, string asf)
	{	
		if(root->left == NULL & root->right == NULL)
		{
			encode[root->data] = asf;
			decode[asf] = root->data;
			return;
		}
		traversal(root->left, asf + "0" );
		traversal(root->right, asf + "1" );

	}
	Huffman(string feeder)
	{
		
		unordered_map<char,int> fre;
		//frequency map
		for(char x: feeder)
		{
			fre[x]++;
		}
		// PQ
		priority_queue<Node,vector<Node>, greater<Node> > pq;
		for(auto it=fre.begin();it!=fre.end();it++)
		{
			Node n(it->first,it->second);
			pq.push(n);
		}
		// troot
		while(pq.size()>1)
		{
			Node n1 = pq.top();
			pq.pop();
			Node n2 = pq.top();
			pq.pop();

			Node n3('&',n1.f+n2.f);
			n3.left = new Node(n1);
			n3.right = new Node(n2);
			pq.push(n3);
		}
		Node root = pq.top();
		pq.pop();
		// traversal 
		traversal(&root,"");

	}
	string encodetext(string str)
	{
		string ans ="";
		for(char x: str)
		{
			ans += encode[x];
		}
		return ans;
	}

	string decodetext(string str)
	{
		string ans="";
		string help ="";
		for(char x: str)
		{
			help+=x;
			if(decode.count(help))
			{
				ans+=decode[help];
				help="";
			}
		}
		return ans;
	}

};



int main(){
	Huffman n("aabssf");
	cout<<"aabssf"<<endl;
	cout<< n.decodetext(n.encodetext("aabssf"))<<endl;
}