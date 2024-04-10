/*
* Name: Julia Smith
* Lab Section: 10
* Description: This program simulates two gorcery stores queues, an express lane which is faster and a normal lane which takes longer for 24 hours.
*/

#include "Queue.h"
#include "Data.h"
#include "QueueNode.h"
#include "TestCases.h"
#include <cstdlib> 
#include <ctime>   
#include <iostream>

int main() {
    int choice;

    do {
        std::cout << "\nTest Menu:\n";
        std::cout << "1. Test Case: Enqueue operation on an empty queue\n";
        std::cout << "2. Test Case: Enqueue operation with one node in the queue\n";
        std::cout << "3. Test Case: Dequeue operation on a queue with one node\n";
        std::cout << "4. Test Case: Dequeue operation on a queue with two nodes\n";
        std::cout << "5. Test Case: Run simulation for 24 hours\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            TestCases::testEmptyEnqueue();
            system("pause");

            break;
        case 2:
            system("cls");
            TestCases::testOneNodeEnqueue();
            system("pause");
            break;
        case 3:
            system("cls");
            TestCases::testOneNodeDequeue();
            system("pause");
            break;
        case 4:
            system("cls");
            TestCases::testTwoNodeDequeue();
            system("pause");
            break;
        case 5:
            system("cls");
            TestCases::runSimulationFor24Hours();
            system("pause");
            break;
        case 6:
            std::cout << "Exiting the program....\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}