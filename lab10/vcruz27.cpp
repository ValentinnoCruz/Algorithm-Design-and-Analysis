//% I collaborated with cristian ortiz
#include<iostream>
#include <deque>
#include<map>
#include<queue>
#include<string>
using namespace std;

map<char, string>C;
struct  Node {
    char letter;
    double freq;
    Node* left;
    Node* right;
   
    
};
struct comparenodes {
    // weak collaboration
   // bool operator ()(const Node& left, const Node& right) {
    bool operator()(Node* left, Node* right){
        //help from http://www.cplusplus.com/reference/algorithm/sort/ for the bool operator
        //discussed comparison type with cristian ortiz
        return (left->freq > right->freq);
    }
};

priority_queue<Node *, deque<Node *>, comparenodes> Q;
//priority queue was instructed by the book
//priority_queue <Type, vector<Type>, ComparisonType > min_heap;
// disscused using a priority queue with cristisn ortiz
Node* Getnew(char letter, double freq){
    Node* newnode= new Node();
    newnode->freq=freq;
    newnode->letter=letter;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
    
}
Node* empty(){
    Node* temp= new Node();

    temp->left=NULL;
    temp->right=NULL;
    temp->letter=NULL;
    temp->freq=NULL;
    return temp;
}

static void encoding(Node *Q, string enc, int i) {
    //weak collaboration
    char letters[]={'A','B','C','D','E','F'};
    
    if (Q==NULL) {
        return;
    }
    
    if (Q->letter == letters[i]) {
        C.insert(make_pair (letters[i],enc));
    }
    if (Q->letter!= letters[i]){
    encoding(Q->left, enc + "0", i);
    //adds on to the string
    encoding(Q->right, enc + "1", i);
    }
};

void huffmantree(){
   Node *x= empty();
    //establish new nodes
    Node *y= empty();
    //establish new nodes
    Node *z=empty();
   //establish new nodes
    for(int p=6; p!=1;p--){
        x = Q.top();
        //x = extractmin(Q)
        //gets new min
        Q.pop();
        //min element gets removed
        y = Q.top();
        Q.pop();
        z = Getnew(' ', (x->freq + y->freq));
        // gets our addition of both nodes being added based on the frequency
        z->left = x;
        //makes left child off of the x min
        z->right = y;
        //makes right child off of the y min

        Q.push(z);
    }
}


int main(){
    double freq;
    int x=0;
    while (x!=6){
      
        cin>>freq;
        if (x==0){

            Q.push(Getnew('A', freq));
        }
        if (x==1){
            Q.push(Getnew('B', freq));

        }
        if (x==2){
            Q.push(Getnew('C', freq));

        }
        if (x==3){
            Q.push(Getnew('D', freq));

        }
        if (x==4){
            Q.push(Getnew('E', freq));

        }
        
        if (x==5){
            Q.push(Getnew('F', freq));

        }
     
        x++;
    }
    huffmantree();
    for (int i = 0; i < 6; i++) {
                encoding(Q.top(), "",i);
    }
    //prints out our encoded letters

     map<char, string>::iterator it = C.begin();
        while(it != C.end()){
                    //
        cout<<it->first<<":"<<it->second<<endl;
                    it++;
        
         }
}
