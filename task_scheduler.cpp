// task_scheduler.cpp
#include "task_scheduler.hpp"

TaskScheduler::TaskScheduler(size_t numThreads) : stopFlag(false) {
    for (size_t i = 0; i < numThreads; ++i) {
        workers.emplace_back(&TaskScheduler::workerFunction, this);
    }
}

TaskScheduler::~TaskScheduler() {
    stop();
}

void TaskScheduler::scheduleTask(std::unique_ptr<Task> task) {
    {
        std::lock_guard<std::mutex> lock(tasksMutex);
        tasks.push(std::move(task));
    }
    cv.notify_one();
}

void TaskScheduler::run() {
    for (auto& worker : workers) {
        worker.join();
    }
}

void TaskScheduler::stop() {
    {
        std::lock_guard<std::mutex> lock(tasksMutex);
        stopFlag = true;
    }
    cv.notify_all();
}

void TaskScheduler::workerFunction() {
    while (true) {
        std::unique_ptr<Task> task;
        {
            std::unique_lock<std::mutex> lock(tasksMutex);
            cv.wait(lock, [this] { return stopFlag || !tasks.empty(); });

            if (stopFlag && tasks.empty()) return;

            // Move the top task out of the priority queue
            task = std::move(const_cast<std::unique_ptr<Task>&>(tasks.top()));
            tasks.pop();
        }
        task->execute();
    }
}

