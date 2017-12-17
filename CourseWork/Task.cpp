//
// Created by timur on 18.11.17.
//

#include "Task.h"

Task::Task(string taskName, unsigned int taskTime, short int taskPriority) {
    this->name = taskName;
    this->time = taskTime;
    this->priority = taskPriority;
    this->leftTime = taskTime;
}

string Task::getName() {
    return this->name;
}

unsigned int Task::getTime() {
    return this->time;
}

short int Task::getPriority() {
    return this->priority;
}

unsigned int Task::getLeftTime() {
    return this->leftTime;
}

void Task::setLeftTime(unsigned int time) {
    this->leftTime = time;
}
