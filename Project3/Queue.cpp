#include "Queue.h"
#include <iostream>

Queue::Queue() : pHead(nullptr), pTail(nullptr) {}

Queue::~Queue() {
    while (pHead != nullptr) {
        QueueNode* temp = pHead;
        pHead = pHead->getNext();
        delete temp;
    }
}

void Queue::enqueue(Data* pData) {
    QueueNode* newNode = new QueueNode(pData);

    if (!pHead) {
        pHead = pTail = newNode;
    }
    else {
        pTail->setpNext(newNode);  
        pTail = newNode;          
    }
}

void Queue::dequeue() {
    if (pHead) {
        QueueNode* temp = pHead;
        pHead = pHead->getNext();
        delete temp;
    }
}
bool Queue::isEmpty() const {
    return pHead == nullptr;
}
QueueNode* Queue::getpHead() const
{
    return pHead;
}
QueueNode* Queue::getpTail() const
{
    return pTail;
}
void Queue::printQueue() const {
    QueueNode* current = pHead;

    std::cout << "Queue Status:" << std::endl;

    while (current) {
        std::cout << "Customer Number: " << current->getData()->getCustomerNumber()
            << ", Service Time: " << current->getData()->getServiceTime()
            << ", Total Time: " << (current->getData()->getCustomerNumber() + current->getData()->getServiceTime())
            << ", Arrival Minute: " << current->getData()->getCustomerNumber()
            << std::endl;
        current = current->getNext();
    }

}



int Queue::size() const {
    int count = 0;
    QueueNode* current = pHead;
    while (current) {
        ++count;
        current = current->getNext();
    }
    return count;
}

