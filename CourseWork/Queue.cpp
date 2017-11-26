//
// Created by timur on 18.11.17.
//

#include <iostream>
#include "Queue.h"

Queue::Queue(unsigned int size) {
    this->maxSize = size;
}

void Queue::add(Task *newTask) {
    this->taskVector.push_back(newTask);

}

Task* Queue::pop_first() {
    Task *task = this->taskVector.front();
    this->taskVector.erase(this->taskVector.begin());
    return task;
}

unsigned long Queue::size() {
    return this->taskVector.size();
}

unsigned int Queue::getMaxSize() {
    return this->maxSize;
}