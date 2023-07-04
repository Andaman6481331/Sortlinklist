132455734913457123457// self-referential structure
#include <iomanip>
class Node {
private:
  int value;

  Node *nextPtr;
Node *previousPtr;
  //  Node *pPtr; // for doubly linked list
public:
  Node(int x = 0);
  ~Node();
  Node *get_next();
  int get_data();
  Node *get_prev();
  void set_next(Node *t);
  void print();
  void set_prev(Node *t);

  // for doubly linked list
  /*
  Node * get_prev();
  void set_prev(Node* t);
  */
};

typedef Node *NodePtr; // synonym for Node*

Node::Node(int x) {
  value = x;
  nextPtr = NULL;
  previousPtr = NULL;
}

Node::~Node() { cout << value << " deleted" << endl; }

NodePtr Node::get_next() { return nextPtr; }

int Node::get_data() { return value; }

NodePtr Node::get_prev() {return previousPtr; }

void Node::set_next(NodePtr t) {
  this->nextPtr = t; 
}

void Node::set_prev(NodePtr t){
  this->previousPtr = t;
}

void Node::print(){
  cout << setw(3) << value;
}
