//
// Created by timur on 18.11.17.
//

#include <iostream>
#include "Stack.h"

void Stack::add(Task *newTask) {
    this->taskVector.push_back(newTask);
}

Task *Stack::pop() {
    if (0 < this->size()) {
        cout << "here";
        Task *lastTask = this->taskVector.back();
        this->taskVector.pop_back();
        return lastTask;
    } else {
        throw new string("Stack is empty!");
    }
}

unsigned long Stack::size() {
    return taskVector.size();
}
