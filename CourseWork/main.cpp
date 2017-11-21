#include <iostream>
#include <thread>
#include <unistd.h>
#include "Stack.h"
#include "Processor.h"
#include "Queue.h"
const unsigned int TASKS_PULL_SIZE = 1000;

void loadPull() {

}
int main() {
    vector<Task *> taskVector(TASKS_PULL_SIZE);

    Stack *stack1 = new Stack();
    Processor *proc1 = new Processor();
    Queue *queue0 = new Queue(100);
    Queue *queue1 = new Queue(100);
    Queue *queue2 = new Queue(100);

    for (int i = 0; i < taskVector.size(); i++) {
        string newName = "Task_" + to_string(i);
        int time = 100 + rand() % 200;
        int prior = rand() % 3;
        taskVector[i] = new Task(newName, time, prior);
    }

    while (0 < (queue0->size() + queue1->size() + queue2->size() + stack1->size() + taskVector.size()) || proc1->busy()) {
        if (queue0->getMaxSize() > queue0->size() || queue1->getMaxSize() > queue1->size() || queue2->getMaxSize() > queue2->size()) {
            int taskCounter = taskVector.size();
            for (int i = 0; i < taskCounter; i++) {
                Task *currTask = taskVector[i];
                taskVector.pop_back();
                switch (currTask->getPriority()) {
                    case 0:
                        if (queue0->getMaxSize() > queue0->size()) {
                            queue0->add(currTask);
                        }
                        break;
                    case 1:
                        if (queue1->getMaxSize() > queue1->size()) {
                            queue1->add(currTask);
                        };
                        break;
                    case 2:
                        if (queue2->getMaxSize() > queue2->size()) {
                            queue2->add(currTask);
                        }
                        break;
                    default:
                        if (queue2->getMaxSize() > queue2->size()) {
                            queue2->add(currTask);
                        }
                }
            }
        }

        if (!proc1->busy()) {
            if (0 < queue0->size()) {
                queue0->firstToProcessor(proc1);
            } else if (0 < queue1->size()) {
                queue1->firstToProcessor(proc1);
            } else if (0 < queue2->size()) {
                queue2->firstToProcessor(proc1);
            }
        }

    }

//    try {
//        stack1->pop();
//    } catch (string *exception) {
//        cout << *exception << endl;
//    }

    return 0;
}