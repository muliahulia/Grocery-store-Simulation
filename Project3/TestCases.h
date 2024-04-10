#ifndef TESTCASES_H
#define TESTCASES_H
#include "Queue.h"

class TestCases {
public:
    static void testEmptyEnqueue();
    static void testOneNodeEnqueue();
    static void testOneNodeDequeue();
    static void testTwoNodeDequeue();
    static void runSimulationFor24Hours();
};

#endif // TESTCASES_H
