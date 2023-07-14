#include "node.h"

class LL {
  NodePtr hol; // head of linked list
  int size;

public:
  LL();
  int deletes(int value);
  int isEmpty();
  void insert(int value);
  void printList();
  void printListR();
//circular [2-way circular linked list]
  void insertc(int value);
  int deletesc(int value);
  void printListRc();

 
  ~LL();
/* With doubly linked list*/
/*
 void printListR();
*/
};

LL::LL() {
  this->hol = NULL;
  size = 0;
}

LL::~LL() {
  cout << "deleting all nodes" << endl;
  NodePtr t;
  t = hol;
  int i;
  for (i = 0; i < size; i++) {
    hol = hol->get_next();
    delete t;
    t = hol;
  }
}

// insert a new value into the list in sorted order
void LL::insert(int value) {
  NodePtr newPtr;      // pointer to new node
  NodePtr previousPtr; // pointer to previous node in list
  NodePtr currentPtr;  // pointer to current node in list

  newPtr = new Node(value); // create node & put value in

  if (newPtr != NULL) { // is space available

    previousPtr = NULL;
    currentPtr = hol;
    // loop to find the correct location in the list
    while (currentPtr != NULL && value > currentPtr->get_data()) {
      previousPtr = currentPtr;            // walk to ...
      currentPtr = currentPtr->get_next(); // ... next node
                                          
    } // end while

    // insert new node at beginning of list
    if (previousPtr == NULL) {
        newPtr->set_next(hol);
      hol->set_prev(newPtr);
        hol = newPtr;
       
      }  // end if
    else { 
      // insert new node between previousPtr and currentPtr
      
      previousPtr->set_next(newPtr);
      newPtr->set_prev(previousPtr);
      previousPtr->set_next(currentPtr);
      newPtr->set_prev(newPtr);
    } // end else
    ++size;
  } // end if
  else {
    cout << value << " not inserted. No memory available." << endl;
  } // end else
} // end function insert

//insert

// delete a list element
int LL::deletes(int value) {
  NodePtr previousPtr; // pointer to previous node in list
  NodePtr currentPtr;  // pointer to current node in list
  NodePtr tempPtr;     // temporary node pointer

  // delete first node
  if (value == hol->get_data()) {
    tempPtr = hol;         // hold onto node being removed
    hol = hol->get_next(); // de-thread the node
    hol->set_prev(NULL);
    size--;

    delete tempPtr; // free the de-threaded node

    return value;
  } // end if
  else {
    previousPtr = hol;
    currentPtr = hol->get_next();

    // loop to find the correct location in the list
    while (currentPtr != NULL && currentPtr->get_data() != value) {
      previousPtr = currentPtr;            // walk to ...
      currentPtr = currentPtr->get_next(); // ... next node
      if (currentPtr == hol)
        currentPtr = NULL;
    } // end while

    // delete node makeat currentPtr
    if (currentPtr != NULL) {
      tempPtr = currentPtr;
      previousPtr->set_next(currentPtr->get_next());
      currentPtr = currentPtr->get_next();
      if(currentPtr){
      currentPtr->set_prev(previousPtr);
      }
      delete tempPtr;
      size--;
      return value;
    } // end if
  }   // end else

  return '\0';
} // end function delete

// return 1 if the list is empty, 0 otherwise
int LL::isEmpty() { return hol == NULL; } // end function isEmpty

// print the list
void LL::printList() {
  NodePtr currentPtr = hol;
  // if list is empty
  if (size == 0) {
    cout << "List is empty." << endl;
  } // end if
  else {
    cout << "The list is:" << endl;

    // while not the end of the list
    // while ( currentPtr != NULL ) {
    int i;
    for (i = 0; i < size; i++) {
      currentPtr->print();
      cout << "  ->";
      currentPtr = currentPtr->get_next();
    } // end while

    puts("NULL\n");
  } // end else
} // end function printList

//print list backward
void LL::printListR(){
  NodePtr currentPtr=hol;
  if (size == 0) {
    cout << "List is empty." << endl;
  } // end if
  else {
    cout << "The list is:" << endl;

    //move currentPtr to the last element
    for(int i=0;i<size;i++)
    {
      currentPtr = currentPtr->get_next();
    }

    //print back the list
    for(int j=0;j<size;j++)
      {
      currentPtr->print();
      cout << "  ->";
      currentPtr = currentPtr->get_prev();
      }
  }

} // end fuction printListR




void LL::insertc(int value) {
  NodePtr newPtr = new Node(value);  // create node & put value in

  if (newPtr != nullptr) { 
    if (hol == nullptr) { //case that the list is empty
      hol = newPtr;
      newPtr->set_next(newPtr); //make it point to itself
      newPtr->set_prev(newPtr); //make it point to itself
    } 
    else {
      NodePtr currentPtr = hol;
      while (currentPtr->get_next() != hol && value > currentPtr->get_next()->get_data()) {
        currentPtr = currentPtr->get_next();
      }
      newPtr->set_next(currentPtr->get_next()); 
      currentPtr->get_next()->set_prev(newPtr);
      newPtr->set_prev(currentPtr);
      currentPtr->set_next(newPtr);

      if(value < hol->get_data()) {
        hol = newPtr;  // Update the head pointer if the inserted value is smaller than the current head
      }
    }
    ++size;
  } 
  else {
    cout << value << " not inserted. No memory available." << endl;
  }
}

// delete a list element
int LL::deletesc(int value) {
  NodePtr currentPtr = hol;  // pointer to current node in list
  NodePtr tempPtr = nullptr; // temporary node pointer

  if (currentPtr == nullptr) {
    return '\0';
  }
  //check if deleted one is at the head
  if (value == hol->get_data()) {
    tempPtr = hol;  
    hol = hol->get_next();
    // Update the previous pointer of the new head
    
    if (hol != nullptr) {
      hol->set_prev(currentPtr->get_prev());
      currentPtr->get_prev()->set_next(hol);
    } else {
      // If the list becomes empty, set hol to nullptr
      hol = nullptr;
    }
    size--;
    delete tempPtr;
    return value;
  }
  else {
    currentPtr = hol->get_next();

    while (currentPtr != hol) { //looking for node to be deleted
      if (value == currentPtr->get_data()) {
        tempPtr = currentPtr;
        currentPtr->get_prev()->set_next(currentPtr->get_next());
        currentPtr->get_next()->set_prev(currentPtr->get_prev());
        size--;
        //circular ll updated

        delete tempPtr;
        return value;
      }    
      currentPtr = currentPtr->get_next(); // slide
    }
  }

  return '\0';
}

void LL::printListRc() {
  if (isEmpty()) {
    cout << "The List is empty" << endl;
    return;
  } 
  else {
    cout << "The reverse list is:" << endl;
    NodePtr currentPtr = hol;  // Start from head

    for (int i = 0; i < size; i++) {
      currentPtr->print();
      cout << "  ->";
      currentPtr = currentPtr->get_prev(); //loop backward
    }

    cout << " NULL" << endl;
  }
}