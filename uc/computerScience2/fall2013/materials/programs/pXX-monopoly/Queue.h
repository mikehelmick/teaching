#ifndef QUEUE_H
#define QUEUE_H

template<class T> class Queue {
public:
  Queue() {
  }
  
  virtual ~Queue() {
  }

  virtual void print() = 0;

  virtual void offer(T value) = 0;
  
  virtual T poll() = 0;
  
  virtual T peek() = 0;
};

#endif