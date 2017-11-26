#include <iostream>
#include <thread>
#include <unistd.h>
#include <random>
#include "Stack.h"
#include "Processor.h"
#include "Queue.h"
using namespace std;

const unsigned int TASKS_PULL_SIZE = 100;
vector<Task *> taskVector(TASKS_PULL_SIZE);

void loadPull(Queue *queue, int priority) {
    unsigned long taskCounter = taskVector.size();
    for (unsigned long i = taskCounter - 1; i >= 0; i--) {
        if (queue->size() == queue->getMaxSize()) {
            break;
        } else if (taskVector[i]->getPriority() == priority) {
            queue->add(taskVector[i]);
            taskVector.pop_back();
        }
    }
}

int main() {
    Stack *stack1 = new Stack();
    Processor *proc1 = new Processor(stack1);
    Queue *queue0 = new Queue(15);
    Queue *queue1 = new Queue(15);
    Queue *queue2 = new Queue(15);
    mt19937 gen(time(0));
    uniform_int_distribution<> uid(0, 2);

    for (int i = 0; i < taskVector.size(); i++) {
        string newName = "Task_" + to_string(i);
        int time = 1 + rand() % 10;
        int prior = uid(gen);
        taskVector[i] = new Task(newName, time, prior);
    }

    while (0 < (queue0->size() + queue1->size() + queue2->size() + stack1->size() + taskVector.size()) || proc1->busy()) {
        if (!taskVector.empty()) {
            Task *currTask = taskVector.back();
            bool taskLoaded = false;

            switch (currTask->getPriority()) {
                case 0:
                    if (queue0->getMaxSize() > queue0->size()) {
                        queue0->add(currTask);
                        taskLoaded = true;
                    }
                    break;
                case 1:
                    if (queue1->getMaxSize() > queue1->size()) {
                        queue1->add(currTask);
                        taskLoaded = true;
                    }
                    break;
                case 2:
                    if (queue2->getMaxSize() > queue2->size()) {
                        queue2->add(currTask);
                        taskLoaded = true;
                    }
            }

            if (taskLoaded) {
                taskVector.pop_back();
            }
        }

        if (0 < queue0->size()) {
            Task *queueTask = queue0->pop_first();
            if (!proc1->busy() || queueTask->getPriority() > proc1->currentTask()->getPriority()) {
                proc1->runTask(queueTask);
            }
        } else if (0 < queue1->size()) {
            Task *queueTask = queue1->pop_first();
            if (!proc1->busy() || queueTask->getPriority() > proc1->currentTask()->getPriority()) {
                proc1->runTask(queueTask);
            }
        } else if (0 < queue2->size()) {
            Task *queueTask = queue2->pop_first();
            if (!proc1->busy() || queueTask->getPriority() > proc1->currentTask()->getPriority()) {
                proc1->runTask(queueTask);
            }
        }

    }

    delete(stack1);
    delete(proc1);
    delete(queue0);
    delete(queue1);
    delete(queue2);
    return 0;
}