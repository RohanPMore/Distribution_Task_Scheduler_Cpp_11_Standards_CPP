# Cpp_11_Standards
This repository will contain codes highlighting the features of Cpp_11 Standards

Project Overview: Distributed Task Scheduler
Project Description:
The project will be a Distributed Task Scheduler, a system that can distribute computational tasks across multiple machines (or threads on a single machine), manage dependencies between tasks, and ensure optimal resource usage. The scheduler will handle a variety of tasks with dependencies, manage resources efficiently using smart pointers, and provide a real-time interface for monitoring and controlling the distributed tasks.

Core Features:
Task Management:

Create, schedule, and manage tasks with dependencies.
Use move semantics to efficiently transfer tasks between different components.
Implement tasks as callable objects, possibly using lambda expressions.
Resource Management:

Use std::unique_ptr and std::shared_ptr to manage resources such as tasks and worker objects.
Implement resource pools for managing reusable resources (e.g., threads).
Concurrency:

Utilize std::thread for task execution on multiple threads.
Manage concurrency with mutexes, condition variables, and other synchronization primitives.
Implement a thread pool to manage a fixed number of worker threads.
Task Distribution and Execution:

Implement a mechanism for task distribution across different nodes or threads.
Use range-based for loops for task assignment and scheduling.
Implement a priority queue for task management, with tasks sorted by priority and dependencies.
Real-Time Monitoring and Control:

Provide an interface for monitoring task progress and controlling execution.
Implement logging and event handling using lambda expressions and multithreading support.
Configuration and Initialization:

Use uniform initialization for all configuration data (e.g., task parameters, thread pool size).
Leverage enum class for strongly-typed task states and priorities.
Type Inference and Type Safety:

Use the auto keyword and decltype for type inference in complex expressions, particularly in task management and resource handling code.
