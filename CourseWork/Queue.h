//
// Created by timur on 18.11.17.
//

#ifndef COURSEWORK_QUEUE_H
#define COURSEWORK_QUEUE_H


#include <vector>
#include "Task.h"
#include "Processor.h"

class Queue {
private:
    vector<Task *> taskVector;

public:
    Task* pop_first();
    Task* front();

    void add(Task *newTask);

    unsigned long size();
};

#endif //COURSEWORK_QUEUE_H
