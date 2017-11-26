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
    unsigned int maxSize;
    unsigned int pull = 0;
    bool loadPull = true;

public:
    Queue(unsigned int size);

    Task* pop_first();

    void add(Task *newTask);

    unsigned long size();
    unsigned int getMaxSize();

};

#endif //COURSEWORK_QUEUE_H
