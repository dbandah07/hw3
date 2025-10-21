#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {

  // cannot assume smaller and larger r null upon entry
  // dont delete or new nodes, change pointers

  if (smaller == NULL) {
    return;
  }

  if (larger == NULL) {
    return;
  }

  Node* temp = head; // curr
  head = head->next; // go to nxt Node
  temp->next = NULL;

  // split to smaller 
  if (temp->val <= pivot) {
    if (smaller == NULL) {
      smaller = temp;
    }
    else {
      temp->next = smaller;
      smaller = temp;
    }
  }

  else {
    if (larger == NULL) {
      larger = temp;
    }
    else {
      temp->next = larger;
      larger = temp;
    }
  }

  llpivot(head, smaller, larger, pivot);
}
