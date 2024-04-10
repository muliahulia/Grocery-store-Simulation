#include "QueueNode.h"

QueueNode::QueueNode(Data* pData) : pData(pData), pNext(nullptr) {}

QueueNode::~QueueNode() {
    delete pData;
}

void QueueNode::setpNext(QueueNode* pNext)
{
    this->pNext = pNext;
}

Data* QueueNode::getData() const {
    return pData;
}

QueueNode* QueueNode::getNext() const {
    return pNext;
}
