// task.cpp
#include "task.hpp"

Task::Task(std::function<void()> func, TaskPriority priority)
    : taskFunc(std::move(func)), priority(priority) {}

void Task::execute() {
    std::lock_guard<std::mutex> lock(taskMutex);
    taskFunc();
}

TaskPriority Task::getPriority() const {
    return priority;
}

std::ostream& operator<<(std::ostream& os, const Task& task) {
    os << "Task with priority: " << static_cast<int>(task.getPriority());
    return os;
}
