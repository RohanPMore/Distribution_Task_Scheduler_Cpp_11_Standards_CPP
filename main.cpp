// main.cpp
#include "task_scheduler.hpp"
#include <iostream>

int main() {
    TaskScheduler scheduler(4);

    auto task1 = std::make_unique<Task>([] { std::cout << "Task 1\n"; }, TaskPriority::HIGH);
    auto task2 = std::make_unique<Task>([] { std::cout << "Task 2\n"; }, TaskPriority::MEDIUM);
    auto task3 = std::make_unique<Task>([] { std::cout << "Task 3\n"; }, TaskPriority::LOW);

    scheduler.scheduleTask(std::move(task1));
    scheduler.scheduleTask(std::move(task2));
    scheduler.scheduleTask(std::move(task3));

    scheduler.run();
    return 0;
}
