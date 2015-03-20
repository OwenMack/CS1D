/*
 * DLinkedList.h
 *
 *  Created on: Feb 19, 2015
 *      Author: MackO
 */

#ifndef DLINKEDLIST_H_
#define DLINKEDLIST_H_

#include <string>

typedef string Elem;				// list element type
  class DNode {					// doubly linked list node
  private:
    Elem elem;					// node element value
    DNode* prev;				// previous node in list
    DNode* next;				// next node in list
    friend class DLinkedList;			// allow DLinkedList access
  };


//3.23
class DLinkedList {				// doubly linked list
  public:
    DLinkedList();				// constructor
    ~DLinkedList();				// destructor
    bool empty() const;				// is list empty?
    const Elem& front() const;			// get front element
    const Elem& back() const;			// get back element
    void addFront(const Elem& e);		// add to front of list
    void addBack(const Elem& e);		// add to back of list
    void removeFront();				// remove from front
    void removeBack();				// remove from back
  private:					// local type definitions
    DNode* header;				// list sentinels
    DNode* trailer;
  protected:					// local utilities
    void add(DNode* v, const Elem& e);		// insert new node before v
    void remove(DNode* v);			// remove node v
  };

//3.24
DLinkedList::DLinkedList() {			// constructor
    header = new DNode;				// create sentinels
    trailer = new DNode;
    header->next = trailer;			// have them point to each other
    trailer->prev = header;
  }

  DLinkedList::~DLinkedList() {			// destructor
    while (!empty()) removeFront();		// remove all but sentinels
    delete header;				// remove the sentinels
    delete trailer;
  }

//3.25

  bool DLinkedList::empty() const		// is list empty?
    { return (header->next == trailer); }

  const Elem& DLinkedList::front() const	// get front element
    { return header->next->elem; }

  const Elem& DLinkedList::back() const		// get back element
    { return trailer->prev->elem;}

//3.26

      						// insert new node before v
  void DLinkedList::add(DNode* v, const Elem& e) {
    DNode* u = new DNode;  u->elem = e;		// create a new node for e
    u->next = v;				// link u in between v
    u->prev = v->prev;				// ...and v->prev
    v->prev->next = v->prev = u;
  }

  void DLinkedList::addFront(const Elem& e)	// add to front of list
    { add(header->next, e); }

  void DLinkedList::addBack(const Elem& e)	// add to back of list
    { add(trailer, e); }

//3.27

  void DLinkedList::remove(DNode* v) {		// remove node v
    DNode* u = v->prev;				// predecessor
    DNode* w = v->next;				// successor
    u->next = w;				// unlink v from list
    w->prev = u;
    delete v;
  }

  void DLinkedList::removeFront()		// remove from font
    { remove(header->next); }

  void DLinkedList::removeBack()		// remove from back
    { remove(trailer->prev); }


  // 5.21
  //typedef string Elem;				// deque element type
    class LinkedDeque {				// deque as doubly linked list
    public:
      LinkedDeque();				// constructor
      int size() const;				// number of items in the deque
      bool empty() const;				// is the deque empty?
      const Elem& front() const ; // the first element
      const Elem& back() const ;	// the last element
      void insertFront(const Elem& e);		// insert new first element
      void insertBack(const Elem& e);		// insert new last element
      void removeFront() ;	// remove first element
      void removeBack() ;	// remove last element
    private:					// member data
      DLinkedList D;				// linked list of elements
      int n;					// number of elements
    };
  // 5.22

  						// insert new first element
    void LinkedDeque::insertFront(const Elem& e) {
      D.addFront(e);
      n++;
    }
  						// insert new last element
    void LinkedDeque::insertBack(const Elem& e) {
      D.addBack(e);
      n++;
    }
  						// remove first element
    void LinkedDeque::removeFront() {
      if (!empty()){
      D.removeFront();
      n--;}
    }
    						// remove last element
    void LinkedDeque::removeBack()  {
      if (!empty()){
      D.removeBack();
      n--;}
    }
    //5.23
    //typedef string Elem;				// element type
      class DequeStack {				// stack as a deque
      public:
        DequeStack();				// constructor
        int size() const;				// number of elements
        bool empty() const;				// is the stack empty?
        const Elem& top() const;	// the top element
        void push(const Elem& e);			// push element onto stack
        void pop() ;		// pop the stack
      private:
        LinkedDeque D;				// deque of elements
      };

    //5.24

    DequeStack::DequeStack()			// constructor
        : D() { }
      						// number of elements
      int DequeStack::size() const
        { return D.size(); }
      						// is the stack empty?
      bool DequeStack::empty() const
        { return D.empty(); }
      						// the top element
      const Elem& DequeStack::top() const  {
        if (!empty())
        return D.front();
      }
      						// push element onto stack
      void DequeStack::push(const Elem& e)
        { D.insertFront(e); }
      						// pop the stack
      void DequeStack::pop()
      {
        if (!empty())
        D.removeFront();
      }

      class Qwrapper{
      public:
      	Qwrapper();
      	~Qwrapper();
      	int size();
      	bool empty();
      	const Elem& front() const;
      	void enqueue(const Elem& e);
      	void dequeue(const Elem& e);

      private:
      	LinkedDeque* Q;
      };

      Qwrapper::Qwrapper(){
      	Q = new LinkedDeque;
      }
      int Qwrapper::size(){
      	return Q->size();
      }

      bool Qwrapper::empty(){
      	return Q->empty();
      }

       const Elem& Qwrapper::front() const{
      	return Q->front();
      }

       void Qwrapper::enqueue(const Elem& e){
      	 Q->insertBack(e);
       }

       void Qwrapper::dequeue(const Elem& e){
      	 Q->removeFront(e);
       }


#endif /* DLINKEDLIST_H_ */
