// self-referential structure    
#include <iomanip>
class Node
{ 
private:
    int value;
    Node *nextPtr;
public:
  Node(int x=0);
 ~Node();
  Node* get_next();
  void set_next(Node* t);
  void print();
  int  get_data(){return value;}
  
 
};
            
typedef Node *NodePtr; // synonym for ListNode*


Node::Node(int x){
  value=x;
  nextPtr=NULL;
}

Node::~Node(){
		cout<<value<<" deleted"<<endl;
}

  Node* Node::get_next(){
    return nextPtr;
  }
  void Node::set_next(Node* t){
    nextPtr=t; 
  }
  void Node::print(){ 
    cout<<setw(3)<<value; 
  }

