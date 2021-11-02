/* --------------------------
      Valentinno Cruz
   --------------------------*/  

#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
    Node* parent;
};
class BST
{
public:
    BST();
    void Insert(Node* z);
    void Delete(Node* z);
    void Print(int func);
    Node* search(int search);
    Node* datanode(int info);

private:
    Node *root;
    void transplant(Node* u, Node* v);
    void inorder(Node* x);
    void postorder(Node* x);
    Node* min(Node* x);
    Node* max(Node* x);
    void preorder(Node* x);
    Node* successor(Node* x);
};

BST::BST()
{
    root = NULL;
}

Node* BST::datanode(int insert)
{
    Node* temp = new Node();
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=NULL;
    temp->data=insert;

    return temp;
}

void BST::transplant (Node* u, Node* v)
{
    if(u->parent==NULL)
    {
        root = v;
    }
    else if(u == u->parent->left) 
    {
        u->parent->left = v;
    } 
    else 
    {
        u->parent->right = v;
    }
    if(v != NULL) 
    {
        v->parent=u->parent;
    }
}
Node* BST::min(Node* x)
{
    while ((x->left)!=NULL)
    {
        x=x->left;
    }
    return x;
}

Node* BST::max(Node* x){
    while ((x->right)!=NULL){
        
        x=x->right;
    }
    return x;
}
Node* BST::successor(Node* x){
    if(x->right!=NULL){
        return min(x->right);
    }
    Node* y;
    y = x->parent;
    while(y!=NULL&& x==(y->right)){
        x=y;
        y=y->parent;
    }
    return y;
}
// iterative search tree
Node* BST::search(int info)
{
    Node* x = root;
    if (x==NULL||info==x->data)
    {
        return x;
    }
    while(x!=NULL&&info!=x->data)
    {
        if( x->data>info){
           x=x->left;
       }
       if (info > x->data)
       {
            x=x->right;
    } 
}
    return x;
}
void BST::Insert(Node* z)
{
    Node* y =NULL;
    Node* x = root;
    while (x!=NULL)
    {
        y =x;
        if (z->data < (x->data))
        {
            x=(x->left);
        }
        else{
            x=(x->right);
        }
    }
    z->parent=y;
    
    if (y==NULL)
    {
        root=z;
    }
    else if(z->data<(y->data))
    {
        y->left=z;
    }
    else{
        y->right=z;
    }
    
}
void BST::Delete(Node* z)
{
    Node* y;
    if ((z->left)==NULL)
    {
        transplant(z, z->right);
    }
    else if((z->right)==NULL)
    {
        transplant(z,z->left);
    }
    else
    {
        y = min(z->right);
        
        if (y->parent!=z)
        {
            transplant(z, z->left);
            y->right = z->right;
            y->right->parent= y;
        }
        transplant(z, y);
        y->left=z->left;
        y->left->parent=y;
    }
}

void BST::inorder(Node* x)
{
    if(x==NULL)
    {
        return;
    }
    else
    {
        inorder(x->left);
        cout<<x->data<<endl;
        inorder(x->right);
    }
}
void BST::preorder(Node* x)
{
    if(x==NULL)
	{
        return;
    }
    else
    {
        cout<<x->data<<endl;
        preorder(x->left);
        preorder(x->right);
        
    }
}

void BST::postorder(Node* x)
{
    if(x==NULL)
    {
        return;
    }
    else
    {
        postorder(x->left);
        postorder(x->right);
        cout<<x->data<<endl;
    }
}
void BST::Print(int func)
{
    if (func ==1)
    {
        preorder(root);
    }
    if (func == 2)
    {
        postorder(root);
    }
    if (func==3)
    {
        inorder(root);
    }
}



int main(int argc, const char * argv[])
{
    BST tree;
    int data;
    char str[0];
    char str1[4];
    bool running=true;
    
    while(running)
    {
        cin>>str[0];
        // works for every case
        if(str[0]=='e')
        {
            running = false;
            break;
        }
        if(str[0]=='i')
        {
            cin>>data;
            Node* z = tree.datanode(data);
            tree.Insert(z);
        }
        if(str[0]=='d')
        {
            cin>>data;
            Node* z = tree.search(data);
            tree.Delete(z);
        }
        if(str[0]=='o')
        {
            cin>>str1;
        if (str1[1]=='r')
        {
            tree.Print(1);
        }
        if (str1[1]=='o')
        {
            tree.Print(2);
        }
        if (str1[1]=='n')
        {
            tree.Print(3);
        }
        }
    }
}

