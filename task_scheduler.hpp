// task_scheduler.hpp
#pragma once
#include "task.hpp"
#include <vector>
#include <queue>
#include <thread>
#include <condition_variable>
#include <future>

class TaskScheduler {
public:
    TaskScheduler(size_t numThreads);
    ~TaskScheduler();

    void scheduleTask(std::unique_ptr<Task> task);
    void run();
    void stop();

private:
    std::vector<std::thread> workers;
    std::priority_queue<std::unique_ptr<Task>> tasks;
    std::mutex tasksMutex;
    std::condition_variable cv;
    bool stopFlag;
    void workerFunction();
};
