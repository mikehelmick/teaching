#ifndef QUEUE_H
#define QUEUE_H

// Abstract class, represents the interface for a basic queue.
template<class T> class Queue {
public:
  Queue() {
  }
  
  virtual ~Queue() {
  }
  
  virtual unsigned int getSize() = 0;

  virtual void print() = 0;

  virtual void offer(T value) = 0;
  
  virtual T poll() = 0;
  
  virtual T peek() = 0;
};

#endif