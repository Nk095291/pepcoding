#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<list>
using namespace std;
class Node {
    public:
    int data;
    vector<Node*> children;

    Node(int data){
        this->data = data;

    }

};

	 Node* construct(vector<int>& dlist){
		Node* root = NULL;
		vector<Node*> nlist;
		for(int i =0;i<dlist.size();i++){
			if(dlist[i]==-1){
				nlist.pop_back();
			}else{
				Node* n = new Node(dlist[i]);
				if(nlist.size()==0){
					root = n;
				}else{
					Node* last = nlist.back();
					last->children.push_back(n);
				}
				nlist.push_back(n);
			}

		}
		return root;
	}

     void display(Node* root){
		string s = to_string(root->data)+"->";
		for(int i=0;i<root->children.size();i++){
			s+=to_string(root->children[i]->data)+",";
		}
		cout<<s<<endl;
		for(int i =0;i<root->children.size();i++){
			display(root->children[i]);
		}
	}

	 int size(Node* root){
		int s= 1;
		for(int i =0;i<root->children.size();i++){
			s+=size(root->children[i]);
		}
		return s;
	}
	int max(Node* root){
		int m = root->data;
		for(int i =0;i<root->children.size();i++){
			int res = max(root->children[i]);
			if(res>m)
				m=res;
		}
		return m;
	}
    bool find (Node* root,int tar){
		if(root->data==tar)
			return true;
		for(int i =0;i<root->children.size();i++){
			bool hasfind= find(root->children[i],tar);
			if(hasfind)
				return true;
		}
		return false;
	}
	int height(Node* root){
		int m =0;
		for(int i=0;i<root->children.size();i++){
			int res = height(root->children[i]);
				if(res>m)
					m=res;
		}
		m++;
		return m;
	}

    vector<int>* n2rpath(Node* root , int tar){
		vector<int>* mres = new vector<int>();
		if(root->data==tar)
		{	mres->push_back(root->data);
			return mres;
		}
		for(Node* i :root->children){
			vector<int>* res = n2rpath(i, tar);
			if(res->size()!=0){
				mres = res;
				mres->push_back(root->data);
				return mres;
			}

		}
		return mres;
	}

    Node* lca(Node* root , int tar1, int tar2){             /// meri approach
		if(root->data==tar1 || root->data==tar2){
			return root;
		}
		Node* t = NULL;
		for(Node* i :root->children){
			Node* res =lca(i, tar1, tar2);
			if(res!=NULL){
				if(t==NULL){
					t=res;
				}else{
					t=root;
				}
			}
		}
		return t;
	}

    int lca2(Node* root, int tar1,int tar2){             /// sir ki approach
		vector<int>* p1 = n2rpath(root, tar1);
		vector<int>* p2 = n2rpath(root, tar2);
		int i = p1->size()-1;
		int j = p2->size()-1;
		int pre=0;
		while(i >=0&& j>=0 && p1->at(i)==p2->at(j)){
			pre=p1->at(i);
			i--;
			j--;
		}
		return pre;

	}


     int distant(Node* root , int tar1,int tar2){
		vector<int>* p1 = n2rpath(root, tar1);
		vector<int>* p2 = n2rpath(root, tar2);
		int i = p1->size()-1;
		int j = p2->size()-1;
		while(i >=0&& j>=0 && p1->at(i)==p2->at(j)){
			i--;
			j--;
		}
		return (i+1)+(j+1)+1;

	}

    void mirror(Node* root){
		for(Node* i:root->children)
			mirror(i);
		for(int i =0,j=root->children.size()-1;i<j;i++,j--){
			Node* temp1 = root->children[i];
			root->children[i]=root->children[j];
			root->children[j]=temp1;
		}

	}
    void removeleaf(Node* root){
		for(int i =0;i<root->children.size();i++){
			if(root->children[i]->children.size()==0){
				root->children.erase(root->children.begin()+i);
				i--;
			}
		}



		for(Node* i :root->children)
			removeleaf(i);


	}



		Node* linearlise(Node* root){
		if(root->children.size()==0)
			return root;

		Node* ol = root->children.back();
		Node* olast = linearlise(ol);
		while(root->children.size()>1){
			Node* slast = linearlise(root->children[root->children.size()-2]);
			Node* last = root->children.back();
			slast->children.push_back(last);
			root->children.pop_back();
		}
		return olast;
	}


		 bool ass(Node* root,Node* root2){
            if(root->children.size()!=root2->children.size())
                return false;
            for(int i=0;i<root->children.size();i++)
                if(!ass(root->children[i],root2->children[i]))
                    return false;
            return true;

	}


	 bool ams(Node* root,Node* root2){
		if(root->children.size()!=root2->children.size())
			return false;
		for(int i=0;i<root->children.size();i++)
			if(!ams(root->children[i],root2->children[root2->children.size()-1-i]))
				return false;
		return true;
	}



	 bool af(Node* root){
		return ams(root,root);
	}




    void floorreal(Node* root,int n,int &mn){
        if(root==NULL)
            return ;
        if(root->data<n&&root->data>mn){
            mn=root->data;
        }
        for(Node* x:root->children)
            floorreal(x,n,mn);
    }

    int floor(Node* root,int n){
        int mn = INT_MIN;
        floorreal(root,n,mn);
        return mn;

	}

	 void ceilreal(Node* root,int n,int &mn){
		if(root==NULL)
			return;
		if((root->data)>n && root->data<mn){
//			System.out.println("yp");
			mn=root->data;
		}
		for(Node* x:root->children){
			ceilreal(x, n, mn);
		}
	}

	 int ceil(Node* root,int n){
		int mn = INT_MAX;
		ceilreal(root,n,mn);
		return mn;

	}



	void preorder_real(Node* root, int n, int &pre,int &post){
        if(root==NULL)
            return;
        if(pre!=post && post==n){
            post=root->data;
            return;
        }
        if(root->data==n){
            post=n;
        }else if(pre==post){
            pre=post=root->data;
        }

        for(Node* x: root->children)
            preorder_real(x,n,pre,post);


	}


	void postorder_real(Node* root, int n, int &pre,int &post){
        if(root==NULL)
            return;
        for(Node* x: root->children)
            postorder_real(x,n,pre,post);


        if(pre!=post && post==n){
            post=root->data;
            return;
        }
        if(root->data==n){
            post=n;
        }else if(pre==post){
            pre=post=root->data;
        }

	}

	void preorder(Node* root,int n){
        int pre=root->data;
        int post=root->data;
        preorder_real(root,n,pre,post);
        cout<<pre<<"   "<<post<<endl;
         pre=root->data;
         post=root->data;
         cout<<pre<<"   "<<post<<endl;
        postorder_real(root,n,pre,post);
        cout<<pre<<"   "<<post<<endl;

	}

	int kl(Node* root , int k ,int mn){
	if(k==0){
        return mn;
	}
	 mn = floor(root,mn);
	kl(root,k-1,mn);

	}

	int kth_largest(Node* root,int k){
        int mn = INT_MAX;
        int kth = kl(root,k,mn);
        return kth;
	}

    int height(Node* root,int h){
		int m =0;
		for(int i=0;i<root->children.size();i++){
			int res = height(root->children[i]);
				if(res>m&&res<h){
				m=res;
				//cout<<res<<"-"<<h<<endl;
				}


		}
		//m++;
		return m;
	}


    int diameter(Node* root){
        int h1= height(root,INT_MAX);
        //cout<<h1<<endl;
        int h2= height(root,h1);
         //cout<<h1<<endl;
        return h1+h2;
    }

//    int sum=INT_MIN;
    int maxn2l(Node* root)                    ///max (node to leaf sum)
    {
        if(root->children.size()==0)
            return root->data;
        int sum=INT_MIN;
        for(Node* x:root->children)
        {
            int res=maxn2l(x);
                if(sum<res)
                    sum=res;
        }
        sum+=root->data;
        return sum;
    }

    void level_p(Node* root){
        list<Node* > queues;
        queues.push_back(root);
        while(queues.size())
        {
            Node* fr = queues.front();
            queues.pop_front();
            cout<<fr->data<<" ";
            for(Node* x:fr->children){
                queues.push_back(x);
            }
        }
        cout<<endl;

    }
     void level_p2_2(Node* root){                                                                  /// sir's code
        list<Node* > *cur=new list<Node*>();
        list<Node* > *next=new list<Node*>();
        cur->push_back(root);
        while(cur->size())
        {
            Node* fr = cur->front();
            cur->pop_front();
            cout<<fr->data<<" ";
            for(Node* x:fr->children)
            {
                next->push_back(x);
            }
            if(cur->size()==0)
            {
                delete cur;
                cur=next;
                next=new list<Node*>();
                cout<<endl;
            }
        }
        cout<<endl;

    }

    void level_p2(Node* root){
        list<list<Node* > > queues;
        list<Node*> helping;
        helping.push_back(root);
        queues.push_back(helping);
        helping.pop_back();
        while(queues.size()!=0 )
        {
            list<Node*> fr = queues.front();
            list<Node*> helping2;


            queues.pop_front();

            while(fr.size()!=0){

                    Node* head=fr.front();
                    fr.pop_front();
                    cout<<head->data<<" ";
                    for(Node* x:head->children)
                        helping2.push_back(x);

            }
            cout<<endl;

            if(helping2.size()!=0)
            queues.push_back(helping2);

        }
        cout<<endl;

    }




    void level_p3(Node* root){                                                                 /// sir's code
        list<Node* > *cur=new list<Node*>();
        list<Node* > *next=new list<Node*>();
        cur->push_back(root);
        bool flag=true;
        while(cur->size()!=0)
        {
             Node* fr = cur->front();
             cur->pop_front();
             cout<<fr->data<<" ";
             if(flag){
                for(Node* x:fr->children)
                    next->push_front(x);
             }else{
                for(int i=fr->children.size()-1;i>=0;i--)
                    next->push_front(fr->children[i]);
             }

             if(cur->size()==0)
             {
                delete cur;
                cur=next;
                next = new list<Node*>();
                flag=!flag;
                cout<<endl;

             }
        }
        cout<<endl;


    }

    class Ehelper{
        public:
        int state;
        Node* root;
        Ehelper(Node* root, int state){
            this->state = state;
            this->root=root;
        }

    };




    void euler(Node* root){
     list<Ehelper*> Stack;
     Ehelper* r= new Ehelper(root,0);
     Stack.push_front(r);
     while(Stack.size()!=0)
     {
        Ehelper* fr = Stack.front();
        int fr_size = fr->root->children.size();

        if(fr->state==0)
        {
            cout<<fr->root->data<<" pre"<<endl;
            (fr->state)++;
        }
        else if(fr->state>=1&& fr->state<=fr_size)
        {
            Ehelper* nn =new Ehelper(fr->root->children.at(fr->state - 1 ),0);
            Stack.push_front(nn);

            if(fr->state>1)
            {
                cout<<fr->root->data<<" in "<<(fr->state-1)<<endl;
            }
            (fr->state)++;
        }
        else if(fr->state==fr_size+1)
        {
            cout<<fr->root->data<<" post "<<endl;
            (fr->state)++;
        }
        else
        {
              Stack.pop_front();
                delete fr;
        }



     }


}

    char ar[][]={
            {'a','b','c'},
            {'d','e','f'},
            {'k'},
            {'l','m','n','o'},
    };

    void kps(Node* root){
     list<Ehelper*> Stack;
     Ehelper* r= new Ehelper(root,0);
     Stack.push_front(r);
     while(Stack.size()!=0)
     {
        Ehelper* fr = Stack.front();
        int fr_size= ar[fr->data -1];
        if(fr->state>=0&&fr->state<fr_size)
        {
            cout<<ar[fr->data -1][fr->state];
            (fr->state)++;
        }
     }


}

	int main(){
        vector<int> dlist{10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
        Node* root = construct(dlist);
        vector<int> dlist2{10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
        Node* root2 = construct(dlist2);

        cout<<ass(root,root2)<<endl;
        mirror(root2);
        cout<<ams(root,root2)<<endl;
        vector<int> dlist3{10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,200,-1,-1,-1};
        Node* root3 = construct(dlist3);
        cout<<af(root3)<<endl;

        cout<<"---------------------------------------------------------------------\n";
        cout<<ceil(root,68)<<endl;
        cout<<"---------------------------------------------------------------------\n";
        cout<<floor(root,68)<<endl;
        cout<<"---------------------------------------------------------------------\n";
        preorder(root,70);
        cout<<"---------------------------------------------------------------------\n";
        cout<<kth_largest(root,2)<<endl;
         cout<<"---------------------------------------------------------------------\n";
//         vector<int> dlist{10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
  //      Node* root = construct(dlist);

        cout<<diameter(root)<<endl;
        cout<<"---------------------------------------------------------------------\n";
        cout<<maxn2l(root)<<endl;
//        euler(root);
         vector<int> dlist23{5,4,3,-1,-1};
        Node* root23 = construct(dlist23);




//        display(root);
//        cout<<size(root)<<endl;
//        cout<<max(root)<<endl;
//        cout<<height(root)<<endl;
//        cout<<find(root,1000)<<endl;
//        vector<int>* s = n2rpath(root,70);
//        for(int i:*s)
//        cout<<i<<" ";
//        cout<<endl;
//        Node* plca = lca(root,70,120);
//        cout<<plca->data<<endl;
//        cout<<lca2(root,70,120)<<endl;
//        cout<<distant(root,70,120)<<endl;
////        mirror(root);
//        display(root);
//        cout<<endl;
////        removeleaf(root);
////        display(root);
//            linearlise(root);
//        display(root);
//
	}
