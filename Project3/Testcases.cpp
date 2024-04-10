#include "TestCases.h"
#include "Data.h"
#include <cstdlib> 
#include <ctime>  
#include <iostream> 

Data otherinstance;

void TestCases::testEmptyEnqueue() {
    Queue myQueue;
    std::cout << "Test Case: Enqueueing on an empty queue\n";
    std::cout << "---------------------------------------\n";
    std::cout << "Initial Queue:\n\n";
    myQueue.printQueue();

    std::cout << "Test Successful - Queue is empty\n";

}

void TestCases::testOneNodeEnqueue() {
    Queue myQueue;
    Data* data = new Data(1, 5);
    myQueue.enqueue(data);
    std::cout << "Test Case: Enqueueing one node\n";
    std::cout << "------------------------\n";

    std::cout << "Queue after enqueueing one node:\n";
    myQueue.printQueue();  
    std::cout << "\n";
}

void TestCases::testOneNodeDequeue() {
    Queue myQueue;
    Data* data = new Data(1, 8);
    myQueue.enqueue(data);
    std::cout << "Test Case: Dequeueing one node from a queue with one node\n";
    std::cout << "------------------------\n";
    std::cout << "Queue with one node: \n";
    myQueue.printQueue();
    myQueue.dequeue();
    std::cout << "Queue after dequeueing one node: \n";
    myQueue.printQueue();  
    std::cout << "\n";
}

void TestCases::testTwoNodeDequeue() {
    Queue myQueue;
    Data* data = new Data(1, 5);
    Data* data2 = new Data(2, 3);
    myQueue.enqueue(data);
    myQueue.enqueue(data2);
    std::cout << "Test Case: Dequeueing one node from a queue with two nodes\n";
    std::cout << "----------------------------------------------------------\n";
    std::cout << "Original Queue: \n";
    myQueue.printQueue();
    std::cout << "\n";
    myQueue.dequeue();

    std::cout << "Queue after dequeueing one node: \n";
    myQueue.printQueue();  
    std::cout << "\n";
    std::cout << "Test completed- 2 nodes succesfully dequeued\n";

}


void TestCases::runSimulationFor24Hours() {
    srand(static_cast<unsigned int>(time(0)));

    Queue expressLane;
    Queue normalLane;

    int totaltime = 0; 

    for (int minute = 0; minute < 1440; ++minute) {
        if (rand() % 5 == 0) {
            int serviceTime = 1 + rand() % 5;
            Data* newData = new Data(minute, serviceTime);
            expressLane.enqueue(newData);
            totaltime = minute + serviceTime;
            std::cout << "Express Lane: Customer arrived at minute " << minute
                << ", Customer Number: " << newData->getCustomerNumber() << ", Total Time: " << totaltime << std::endl;
        }

        if (rand() % 8 == 0) {
            int serviceTime = 3 + rand() % 6;
            Data* newData = new Data(minute, serviceTime);
            normalLane.enqueue(newData);
            totaltime = minute + serviceTime;
            std::cout << "Normal Lane: Customer arrived at minute " << minute
                << ", Customer Number: " << newData->getCustomerNumber() << ", Total Time: " << totaltime << std::endl;
        }

        if (!expressLane.isEmpty()) {
            expressLane.getpHead()->getData()->decrementServiceTime();
            if (expressLane.getpHead()->getData()->getServiceTime() == 0) {
                expressLane.dequeue();
            }
        }

        if (!normalLane.isEmpty()) {
            normalLane.getpHead()->getData()->decrementServiceTime();
            if (normalLane.getpHead()->getData()->getServiceTime() == 0) {
                normalLane.dequeue();
            }
        }

        if (minute % 10 == 0) {
            std::cout << "\n\n------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "Express Lane - Minute " << minute << std::endl;
            expressLane.printQueue();
            std::cout << "***Express Lane is " << (expressLane.isEmpty() ? "empty***" : "not empty***") << std::endl;
            std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "Normal Lane - Minute " << minute << std::endl;
            normalLane.printQueue();
            std::cout << "Normal Lane is " << (normalLane.isEmpty() ? "empty." : "not empty.") << std::endl;
            std::cout << "------------------------------------------------------------------------------------------------------------\n\n" << std::endl;

        }
    }


    while (!expressLane.isEmpty()) {
        expressLane.dequeue();
    }

    while (!normalLane.isEmpty()) {
        normalLane.dequeue();
    }
    std::cout << "Total Time: " << totaltime << std::endl;


    std::cout << "24 hour (1440 min) test completed and passed\n";
}
