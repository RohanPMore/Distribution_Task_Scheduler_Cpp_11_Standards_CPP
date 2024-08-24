// task.hpp
#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <memory>
#include <mutex>

enum class TaskPriority { LOW, MEDIUM, HIGH };

class Task {
public:
    Task(std::function<void()> func, TaskPriority priority);

    void execute();
    TaskPriority getPriority() const;

private:
    std::function<void()> taskFunc;
    TaskPriority priority;
    std::mutex taskMutex;
};

std::ostream& operator<<(std::ostream& os, const Task& task);
