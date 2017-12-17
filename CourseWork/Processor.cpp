//
// Created by timur on 18.11.17.
//

#include <thread>
#include <unistd.h>
#include <iostream>
#include "Processor.h"

void Processor::work() {
    Task * task = this->currentTask();
    task->setLeftTime(task->getLeftTime() - 1);
    cout << "WORK " << task->getName() << ", priority: " << task->getPriority() << ", time left: " << task->getLeftTime() << endl;
}

Task * Processor::currentTask() {
    return this->currTask;
}

void Processor::currentTask(Task *currentTask) {
    this->currTask = currentTask;
}