#include <iostream>
#include <thread>
#include <unistd.h>
#include <random>
#include "Stack.h"
#include "Processor.h"
#include "Queue.h"
using namespace std;

Task* generateTask(int i) {
    string newName = "Task_" + to_string(i);
    int time = 2 + rand() % 10;
    int prior = rand() % 3;
    return new Task(newName, time, prior);
}

int main() {
    srand(time(0));
    Stack *stack1 = new Stack();
    Processor *proc1 = new Processor();
    Queue *queue0 = new Queue();
    Queue *queue1 = new Queue();
    Queue *queue2 = new Queue();
    int taskCount = 1000;
    int currentTaskCount = 0;
    int wait = 1;
    int commonCount = 0;

    while (0 < (queue0->size() + queue1->size() + queue2->size() + stack1->size()) || currentTaskCount != taskCount) {
        if (currentTaskCount != taskCount && commonCount % wait == 0) {
            Task * currTask = generateTask(currentTaskCount);
            currentTaskCount++;
            switch (currTask->getPriority()) {
                case 0:
                    queue0->add(currTask);
                    break;
                case 1:
                    queue1->add(currTask);
                    break;
                case 2:
                    queue2->add(currTask);
                    break;
            }
        }

        Task * currTask = proc1->currentTask();
        Task * stackTask = stack1->size() == 0 ? nullptr : stack1->back();
        Task * queueTask = nullptr;
        Queue *currQueue = nullptr;
        if (0 < queue0->size()) {
            queueTask = queue0->front();
            currQueue = queue0;
        } else if (0 < queue1->size()) {
            queueTask = queue1->front();
            currQueue = queue1;
        } else if (0 < queue2->size()) {
            queueTask = queue2->front();
            currQueue = queue2;
        }

        if (!currTask) {
            if (queueTask && stackTask && stackTask->getPriority() <= queueTask->getPriority()) {
                proc1->currentTask(stack1->pop());
                cout << "FROM STACK " << stackTask->getName() << ", priority: " << stackTask->getPriority() << endl;
            } else if (queueTask) {
                proc1->currentTask(currQueue->pop_first());
            }
        } else if (queueTask && queueTask->getPriority() < currTask->getPriority()) {
            Task * taskFromProc = proc1->currentTask();
            stack1->add(taskFromProc);
            cout << "TO STACK " << taskFromProc->getName() << ", priority: " << taskFromProc->getPriority() << endl;
            proc1->currentTask(currQueue->pop_first());
        }

        if (proc1->currentTask() && 0 != proc1->currentTask()->getLeftTime()) {
            proc1->work();
        } else {
            proc1->currentTask(nullptr);
        }
        commonCount++;
    }

    delete(stack1);
    delete(proc1);
    delete(queue0);
    delete(queue1);
    delete(queue2);
    return 0;
}