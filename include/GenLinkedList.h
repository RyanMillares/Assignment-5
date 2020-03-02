#include <iostream>
#include "ListNode.h"
using namespace std;

template <class T>
class GenLinkedList{
private:

  unsigned int size;
public:
  GenLinkedList();
  ~GenLinkedList();
  //to make peek() easier maybe
  ListNode<T> *front;
  ListNode<T> *tail;
  bool IsInList(T d);
  void insertFront(T d); //inserts element at the front
  void insertBack(T d); //inserts element at the back
  T removeFront(); //removes and returns front element
  T removeBack(); //removes and returns last element
  T deletePos(int pos); //delete at position
  int find(T d); //find position of a value

  bool isEmpty(); //is it empty?
  void printList(); //literally just the name
  unsigned int getSize(); //not much to say of this either

};

template <class T>
GenLinkedList<T>::GenLinkedList(){
  front = NULL; //nullptr
  tail = NULL;
  size = 0;
} //constructor
template <class T>
GenLinkedList<T>::~GenLinkedList(){
  if(front == NULL){
    delete front;
    delete tail;
  }
} //deconstructor
template <class T>
unsigned int GenLinkedList<T>::getSize(){
  return size; //return the size
}
template <class T>
bool GenLinkedList<T>::isEmpty(){
  return (size == 0); //return true if size is 0
}
template <class T>
void GenLinkedList<T>::printList(){
  //prints the list by iterating through every node from front to end
  ListNode<T> *curr = new ListNode<T>();
  curr = front;
  while(curr != NULL){
    cout << curr->data << endl;
    //cout << curr->next->data << endl;
    curr = curr->next;
  }

}
template <class T>
void GenLinkedList<T>::insertFront(T d){

  //insert element at front
  ListNode<T> *node = new ListNode<T>(d);

  if(front == NULL){ //is empty
    front = node;
    tail = node;
    //cout << "hi" << endl;

    //if empty, set front and tail to node
  }
  else{

    //if there are elements
    //set node's front pointer to Front, its prev to NULL
    //the front's prev pointer goes to the node
    //and the node becomes the front
    node->next = front;

    node->prev = NULL;
    front->prev = node;

    front = node;

  }
  size++;
}
template <class T>
void GenLinkedList<T>::insertBack(T d){
  if(tail == NULL){
    insertFront(d);
  }
  //if list is empty, insert is same as front insertion
  else{
    ListNode<T> *node = new ListNode<T>(d);
    node->prev = tail;
    tail->next = node; //had to switch these 2
    node->next = NULL; //had to switch these 2
    //


    tail = node;
    size++;
  }


}
template <class T>
T GenLinkedList<T>::removeFront(){
  //remove and return item from front
  T tap;
  if(size > 0){ //only do this all if there are even elements
    if(size == 1){
      tap = front->data;
      ListNode<T> *replace1 = front;
      delete replace1;
      front = NULL;
      tail = NULL;

    }
    else{
      tap = front->data;
      ListNode<T> *replace = front;
      front = front->next;
      front->prev = NULL;
      delete replace;
    }

    //replace->next = NULL;
    size--;
    return tap;
  }
  else{
    cout << "List is empty." << endl;
    exit(0);
  }


}
template <class T>
T GenLinkedList<T>::removeBack(){
  //removes from end of queue
  T tap;
  if(size > 0){
    if(size == 1){
      removeFront();
      //just do a removeFront if size is one
    }
    else{
      tap = tail->data;
      ListNode<T> *replace1 = tail;
      tail = tail->prev;
      tail->next = NULL;
      delete replace1;
      //performs the removefront but with tail and next pointers
    }


    size--;
    return tap;
  }
  else{
    cout << "List is empty." << endl;
    exit(0);
  }

}
template <class T>
T GenLinkedList<T>::deletePos(int pos){
  if(pos >= size){
    cout << "Error: Tried accessing item at position " << pos << " and available positions are 0-" << (size-1) << endl;
    exit(0);
  }
  int idx = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;
  while(idx != pos){
    prev = curr;
    curr = curr->next;
    idx++;
    //iterate until reaching the given position
  }

  if(curr == tail){
    tail = prev;
    curr->next = NULL;
    curr->prev = NULL;
  }
  else{
    prev->next = curr->next;

    curr->next->prev = prev;
    curr->next = NULL;
    curr->prev = NULL;
    //perform deletion, and fix pointers of the nodes
    //before and after to reference each other and not the
    //deleted node

  }

  int temp = curr->data;
  delete curr;
  size--;
  return temp;
}
template <class T>
int GenLinkedList<T>::find(T d){

  int idx = 0;
  ListNode<T> *curr = front;

  while(curr != NULL){
    if(curr->data == d){
      return idx;
      //return the index where the data matches the input
      //break
    }

    idx++;
    curr = curr->next;
  }
  if(curr == NULL){
    idx = -1;
  }
  return idx;
}
template <class T>
bool GenLinkedList<T>::IsInList(T d){
  if(size == 0){
    return false;
  }
  ListNode<T>* curr = front;
  while(curr != NULL){
    if(curr->data == d){
      return true;
    }
    curr = curr->next;
  }
  return false;
}
