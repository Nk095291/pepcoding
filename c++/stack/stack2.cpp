#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<math.h>
#include<algorithm>
using namespace std;
unordered_map<char,int> map{make_pair('+',1),make_pair('-',1),make_pair('*',2),make_pair('/',2),make_pair('^',3),make_pair('(',0)};
stack<int> var;
stack<char> op;
void solve()
{
		char operation = op.top();
		op.pop();
		int last = var.top();
		var.pop();
		int seclast = var.top();
		var.pop();
		int res;
		switch(operation)
		{
			case '+':{res = seclast+last;break;}
			case '-':{res = seclast-last;break;}
			case '*':{res = seclast*last;break;}
			case '/':{res = seclast/last;break;}
			case '^':{res = pow(seclast,last);break;}
		}
		var.push(res);
}
int solve2(int seclast,int last,char operation)
{
	int res;
		switch(operation)
		{
			case '+':{res = seclast+last;break;}
			case '-':{res = seclast-last;break;}
			case '*':{res = seclast*last;break;}
			case '/':{res = seclast/last;break;}
			case '^':{res = pow(seclast,last);break;}
		}
		return res;
}
void solveExp(string str)
{
		for(char ch:str)
		{
			if(map.count(ch) || ch == ')')
			{
				if(ch==')')
				{
					while(op.size()>0 && op.top()!='(')
					{
						solve();
					}
					op.pop();
				}
				else if(ch =='(')
				{
					op.push(ch);
				}
				else
				{
					while(op.size()>0&& map[ch]<=map[op.top()])
						solve();
					op.push(ch);
				}
			}
			else
			{
				var.push(ch-'0');
			}
		
		}
		while(var.size()>1)
		{
			solve();
		}
		cout<<var.top()<<endl;
}

string inToPost(string str)
{
	string res ;
	stack<char> op;
	for(char ch:str)
		{
			if(map.count(ch) || ch == ')')
			{
				if(ch==')')
				{
					while(op.size()>0 && op.top()!='(')
					{
							res.push_back(op.top());
							op.pop();
					}
					op.pop();
				}
				else if(ch =='(')
				{
					op.push(ch);
				}
				else
				{
					while(op.size()>0&& map[ch]<=map[op.top()])
						{
							res.push_back(op.top());
							op.pop();
						}
					op.push(ch);
				}
			}
			else
			{
				res.push_back(ch);
			}
		}
		while(op.size())
		{
			res.push_back(op.top());
			op.pop();
		}
		return res;
}

void inToPre(string str)
{
	reverse(str.begin(),str.end());
	for(char &ch :str)
	{
		if(ch =='(')
			ch=')';
		else if(ch == ')')
			ch ='(';
	}
}
void pre123(string str){
	stack<int> res;
	stack<string> infix;
	stack<string> prefix;
	for(char ch: str){
		if(map.count(ch))
		{
			int v2 = res.top();res.pop();
			int v1 = res.top();res.pop();
			res.push(solve2(v1,v2,ch));
			string iv2 = infix.top();infix.pop();
			string iv1 = infix.top();infix.pop();
			string ans = "("+iv1+ch+iv2+")";
			infix.push(ans);
			string pv2 = prefix.top();prefix.pop();
			string pv1 = prefix.top();prefix.pop();
			string ans2 = " "+ch+pv1+pv2;
			prefix.push(ans2);

		}
	else
		{
			res.push(ch-'0');
			infix.push(string()+ch);
			prefix.push(string()+ch);
		}
	}
	cout<<res.top()<<endl;
	cout<<infix.top()<<endl;
	cout<<prefix.top()<<endl;
}
void post123(string str)
{
	stack<int> res;
	stack<string> infix;
	stack<string> prefix;
	for(int i =str.size()-1;i>=0;i--){
		char ch = str[i];
		if(map.count(ch))
		{
			int v1 = res.top();res.pop();
			int v2 = res.top();res.pop();
			res.push(solve2(v1,v2,ch));
			string iv1 = infix.top();infix.pop();
			string iv2 = infix.top();infix.pop();
			string ans = "("+iv1+ch+iv2+")";
			infix.push(ans);
			string pv1 = prefix.top();prefix.pop();
			string pv2 = prefix.top();prefix.pop();
			string ans2 = pv1+pv2+ch;
			prefix.push(ans2);

		}
	else
		{
			res.push(ch-'0');
			infix.push(string()+ch);
			prefix.push(string()+ch);
		}
	}
	cout<<res.top()<<endl;
	cout<<infix.top()<<endl;
	cout<<prefix.top()<<endl;
}
int main()
{
	string s1="(8+2)/3+2^(1*1+3)";
	// cout<<inToPost(s1)<<endl;
	// inToPre(s1);
	pre123("123*+");
}