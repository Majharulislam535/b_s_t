#include <bits/stdc++.h>


using namespace std;

class Node{
  public:
      int value;
      Node * left;
      Node * right;
      Node(int value){
         this->left=NULL;
         this->right=NULL;
         this->value = value;
       }
};

Node * input_tree(){
 int val;
 cin>>val;
   Node * root;

  if(val==-1) root=NULL;
  else root=new Node(val);
   queue<Node*>q;
   if(root) q.push(root);

   while(!q.empty()){
       Node * f = q.front();
       q.pop();

        int l,r;
        cin>>l>>r;
        Node * left;
        Node *right;

        if(l==-1) left=NULL;
        else left=new Node(l);

        if(r==-1) right = NULL;
        else right = new Node(r);


        f->left=left;
        f->right=right;




      if(f->left) q.push(f->left);
      if(f->right) q.push(f->right);
   }

 return root;
}


void levelOrder(Node * root){

  queue<Node*> q;
  q.push(root);
  while(!q.empty()){

    Node *f = q.front();
    q.pop();

    cout<<f->value << " ";


    if(f->left) q.push(f->left);
    if(f->right) q.push(f->right);


  }

}

bool search_bst(Node*root,int x){

   if(root==NULL) return false;

   if(root->value==x) return true;

   if(x < root->value){
      return search_bst(root->left,x);
   }
   else{
      return search_bst(root->right,x);
   }

}






int main()
{


   Node * root = input_tree();
   //levelOrder(root);

   if(search_bst(root,120)){
       cout<<"YES , it's found"<<endl;
   }
   else{
     cout<<"NO, it's Not found"<<endl;
   }





    return 0;
}
