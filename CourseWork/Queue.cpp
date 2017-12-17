//
// Created by timur on 18.11.17.
//

#include <iostream>
#include "Queue.h"

void Queue::add(Task *newTask) {
    this->taskVector.insert(this->taskVector.begin(), newTask);
}

Task* Queue::pop_first() {
    Task *task = this->taskVector.front();

    this->taskVector.erase(this->taskVector.begin());
    return task;
}

Task* Queue::front() {
    Task *task = this->taskVector.front();
    return task;
}

unsigned long Queue::size() {
    return this->taskVector.size();
}