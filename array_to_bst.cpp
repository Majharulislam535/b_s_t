#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node * convert_ar(int ar[],int n,int l,int r){

    if(l>r) return NULL;
    int mid = (l+r)/2;
    Node * root = new Node(ar[mid]);

    Node * leftR= convert_ar(ar,n,l,mid-1);
    Node * rightR = convert_ar(ar,n,mid+1,r);

    root->left=leftR;
    root->right=rightR;

    return root;

 }


void level_order(Node *root)
{

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        // 1. ber kore ana
        Node *f = q.front();
        q.pop();

        // 2. jabotiyo ja kaj ache
        cout << f->val << " ";

        // 3. tar children gulo ke rakha
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}
int main()
{
     int n;cin>>n;
     int ar[n];
     for(int i=0;i<n;i++) cin>>ar[i];

     Node * root = convert_ar(ar,n,0,n-1);


    level_order(root);
    return 0;
}
