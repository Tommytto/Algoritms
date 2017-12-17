//
// Created by timur on 18.11.17.
//

#ifndef COURSEWORK_PROCESSOR_H
#define COURSEWORK_PROCESSOR_H


#include "Task.h"
#include "Stack.h"

class Processor {
private:
    Task * currTask;
public:
    bool busy();
    void busy(bool busy);

    Task * currentTask();
    void currentTask(Task *currentTask);

    void work();
};


#endif //COURSEWORK_PROCESSOR_H
