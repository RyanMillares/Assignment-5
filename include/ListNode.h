#include <iostream>
using namespace std;
template <class T>
class ListNode{
public:
  T data;
  ListNode<T> *next;
  ListNode<T> *prev;

  ListNode();
  ListNode(T d);
  ~ListNode();
private:

};

template <class T>
ListNode<T>::ListNode(){

}
template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL; //nullptr
  prev = NULL;
}
template <class T>
ListNode<T>::~ListNode(){
  if(next == NULL){

    delete next;
    delete prev;
  }
}
