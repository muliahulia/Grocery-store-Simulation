#ifndef QUEUE_H
#define QUEUE_H
#include "QueueNode.h"

class Queue {
public:
    Queue();
    ~Queue();

    void enqueue(Data* pData);
    void dequeue();
    void printQueue() const;
    int size() const;
    bool isEmpty() const;

  
    QueueNode* getpHead() const;
    QueueNode* getpTail() const;

private:
    QueueNode* pHead;
    QueueNode* pTail;
};

#endif // QUEUE_H
