//
// Created by timur on 18.11.17.
//

#include <thread>
#include <unistd.h>
#include <iostream>
#include "Processor.h"

void Processor::runTask(Task *task) {
    if (this->busy()) {
        this->stack->add(this->currentTask());
        cout << "To stack: " << this->currentTask()->getName() << endl;
    }
    this->occupyProc(task);
    thread thr(&Processor::threatFunc, this, task);
    thr.detach();
}

void Processor::threatFunc(Task *task) {
    this_thread::sleep_for(chrono::milliseconds(task->getTime()));
    cout << "Task " << task->getName() << ", "<< task->getPriority() <<" priority, sleep for " << task->getTime() << endl;
    this->freeProc();
}


bool Processor::busy() {
    return this->isBusy;
}

Task *Processor::currentTask() {
    return this->currTask;
}

void Processor::currentTask(Task *currentTask) {
    this->currTask = currentTask;
}

void Processor::occupyProc(Task *newTask) {
    this->busy(true);
    this->currentTask(newTask);
}

void Processor::freeProc() {
    this->busy(false);
    delete(this->currentTask());
}

void Processor::busy(bool busy) {
    this->isBusy = busy;
}

Processor::Processor(Stack *newStack) {
    this->stack = newStack;
}
