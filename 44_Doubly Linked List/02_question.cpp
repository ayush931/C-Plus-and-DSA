// 1. Insertion at the start in doubly linked list.
// 2. Insertion at the end in the doubly linked list.
// 3. Insertion at kth position in the doubly linked list.
// 4. Deletion of node from the start.
// 5. Deletion of the node from the end.
// 6. Deletion of node from the kth position.

#include <iostream>
using namespace std;

class Node {
public:
  int val;
  Node *prev;
  Node *next;

  Node(int data) {
    val = data;
    prev = NULL;
    next = NULL;
  }
};

class DoublyLinkedList {
public:
  Node *head;
  Node *tail;

  DoublyLinkedList() {
    head = NULL;
    tail = NULL;
  }

  void display() {
    Node *temp = head;
    while (temp != NULL) {
      cout << temp->val << "<->";
      temp = temp->next;
    }
    cout << endl;
  }

  void insertAtStart(int val) {
    Node *new_node = new Node(val);

    if (head == NULL) {
      head = new_node;
      tail = new_node;
      return;
    }

    new_node->next = head;
    head->prev = new_node;
    head = new_node;
    return;
  }

  void insertAtEnd(int val) {
    Node *new_node = new Node(val);

    if (tail == NULL) {
      head = new_node;
      tail = new_node;
      return;
    }

    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
    return;
  }

  void insertAtPosition(int val, int k) {

    // assuming that k is equal to or less than length of doubly linked list.
    Node *temp = head;
    int count = 1;

    while (count < (k - 1)) {
      temp = temp->next;
      count++;
    }

    // temp will be pointing to the node at the (k-1)th position.
    Node *new_node = new Node(val);
    new_node->next = temp->next;
    temp->next = new_node;

    new_node->prev = temp;
    new_node->next->prev = new_node;
    return;
    // Time complexity -> O(k);
    // Worst case -> O(n);
  }

  void deleteAtStart() {
    if (head == NULL) {
      return;
    }

    Node *temp = head;
    head = head->next;

    if (head == NULL) { // if doubly linked list has only 1 node
      tail = NULL;
    } else {
      head->prev = NULL;
    }

    free(temp);
    return;
  }

  void deleteAtEnd() {
    if (head == NULL) {
      return;
    }

    Node *temp = tail;
    tail = tail->prev;

    if (tail == NULL) {
      head = NULL;
    } else {
      tail->next = NULL;
    }

    free(temp);
    return;
  }

  void deleteAtPosition(int k) {
    // assuming that k is less than equal to length of doubly linked list.
    Node *temp = head;
    int counter = 1;

    while (counter < k) {
      temp = temp->next;
      counter++;
    }

    // now temp is pointing to node at kth node.
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return;
  }
};

int main() {

  DoublyLinkedList dll;

  dll.insertAtStart(1);
  dll.display();

  dll.insertAtStart(2);
  dll.display();

  dll.insertAtStart(3);
  dll.display();

  dll.insertAtEnd(4);
  dll.display();

  dll.insertAtEnd(5);
  dll.display();

  dll.insertAtEnd(6);
  dll.display();

  dll.insertAtPosition(9, 4);
  dll.display();

  dll.deleteAtStart();
  dll.display();

  dll.deleteAtEnd();
  dll.display();

  dll.deleteAtPosition(3);
  dll.display();

  return 0;
}
