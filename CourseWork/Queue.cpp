//
// Created by timur on 18.11.17.
//

#include <iostream>
#include "Queue.h"

Queue::Queue(unsigned int size) {
    this->maxSize = size;
}

void Queue::add(Task *newTask) {
    if ((1 + this->size()) > this->maxSize) {
        throw new string("Sorry, limit for this queue is " + to_string(this->maxSize) + " elements");
    } else {
        this->taskVector.push_back(newTask);
    }
}

void Queue::firstToProcessor(Processor *proc) {
    Task *task = this->taskVector.front();
    this->taskVector.erase(this->taskVector.begin());
    proc->runTask(task);
}

unsigned long Queue::size() {
    return this->taskVector.size();
}

unsigned int Queue::getMaxSize() {
    return this->maxSize;
}

void Queue::setPull(unsigned int pullCount) {
    this->pull = pullCount;
}
