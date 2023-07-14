//circular [2-way circular linked list]
  void insertc(int value);
  int deletesc(int value);
  void printListRc();
};


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