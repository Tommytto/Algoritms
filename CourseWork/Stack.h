//
// Created by timur on 18.11.17.
//

#ifndef COURSEWORK_STACK_H
#define COURSEWORK_STACK_H

using namespace std;

#include <vector>
#include "Task.h"

class Stack {
private:
    vector<Task *> taskVector;

public:
    void add(Task *newTask);

    Task *pop();
    Task *back();

    unsigned long size();
};


#endif //COURSEWORK_STACK_H
