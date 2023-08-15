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


void insert_value(Node * &root,int x){
   if(root==NULL){
      root=new Node(x);
      return;
   }

   if(x<root->value){
       if(root->left==NULL){
          root->left = new Node(x);
       }
       else{
          insert_value(root->left,x);
       }
   }
   else{
       if(root->right==NULL){
         root->right = new Node(x);
       }
       else{
          insert_value(root->right,x);
       }
   }
}






int main()
{


   Node * root = input_tree();
   insert_value(root,13);
   insert_value(root,22);
   insert_value(root,32);
   levelOrder(root);



    return 0;
}
