#ifndef STACK_H
#define STACK_H

template<class T> class Stack {
public:
  Stack() {
  }
  
  virtual ~Stack() {
  }

  virtual void print() = 0;

  virtual void push(T value) = 0;
  
  virtual T pop() = 0;
  
  virtual T peek() = 0;
};

#endif
