//
// Created by timur on 18.11.17.
//

#ifndef COURSEWORK_PROCESSOR_H
#define COURSEWORK_PROCESSOR_H


#include "Task.h"

class Processor {
private:
    bool isBusy = false;
    Task *currTask;
public:
    void runTask(Task *task);
    bool busy();
    void busy(bool busy);

    Task *currentTask();
    void currentTask(Task *currentTask);

    void threatFunc(Task *task);
    void freeProc();
    void occupyProc(Task *newTask);
};


#endif //COURSEWORK_PROCESSOR_H