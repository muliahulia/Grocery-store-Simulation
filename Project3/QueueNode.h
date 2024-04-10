#ifndef QUEUENODE_H
#define QUEUENODE_H
#include "Data.h"

class QueueNode {
public:
    QueueNode(Data* pData);
    ~QueueNode();

    void setpNext(QueueNode* pNext);
    Data* getData() const;
    QueueNode* getNext() const;

private:
    Data* pData;
    QueueNode* pNext;
};

#endif // QUEUENODE_H
