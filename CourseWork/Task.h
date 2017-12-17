//
// Created by timur on 18.11.17.
//
#include <string>

using namespace std;

#ifndef COURSEWORK_TASK_H
#define COURSEWORK_TASK_H


class Task {
private:
    string name;
    unsigned int time;
    unsigned int leftTime;
    short int priority;

public:
    Task(string taskName, unsigned int taskTime, short int taskPriority);

    string getName();

    unsigned int getTime();
    unsigned int getLeftTime();
    void setLeftTime(unsigned int time);

    short int getPriority();
};


#endif //COURSEWORK_TASK_H
