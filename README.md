# Project overview

A simple coroutine library.
By introducing core modules such as coroutines, schedulers, and timers, traditional synchronous functions in Linux systems (such as' sleep ',' read ',' write ', etc.) are built into asynchronous versions using HOOK technology.
This coroutine library allows for synchronous I/O programming while enjoying the efficiency and response speed improvements of asynchronous execution.

## Operating environment

Ubuntu 22.04 LTS

## Directives

`g++ -std=c++17 ./src/*.cpp -o ./test/test`

## Run

`./test/test`

## Introduction to main modules

### Collaborative Class
* Use asymmetric independent stack coroutines.
* Support efficient switching between scheduling coroutines and task coroutines.

### scheduler
* Combine thread pool and task queue to maintain tasks.
* The worker thread uses FIFO strategy to run coroutine tasks and is responsible for adding ready file descriptor events and timeout tasks from epoll to the queue.

### timer
* Utilize the minimum heap algorithm to manage timers and optimize the efficiency of obtaining timeout callback functions.

## Key technical points

* Thread synchronization and mutual exclusion
* Thread Pool Management
* Epoll's event driven model
* Linux Network Programming
* Generic programming
* Synchronous and asynchronous I/O
* HOOK Technology

### Memory Pool Optimization
The current coroutine automatically allocates independent stack space upon creation and releases it upon destruction, introducing frequent system calls. Optimizing through memory pooling technology can reduce system calls and improve memory utilization efficiency.

### Support for nested coroutines
At present, it only supports switching between main coroutines and child coroutines, and cannot achieve nested coroutines. Referring to the design of libco, implement more complex coroutine nesting functionality, allowing for the creation of new coroutine levels within coroutines.

### Complex scheduling algorithm
Introduce process scheduling algorithms similar to operating systems, such as priority, response ratio, and time slices, to support more complex scheduling strategies and meet the needs of different scenarios.

## Core
### Synchronous I/O
The application must wait for the completion of I/O operations, during which the application is blocked and unable to perform other tasks.

### Asynchronous I/O
Applications can continue to execute other code during I/O operations, which are notified through an event callback mechanism.

### HOOK
Encapsulate the underlying functions of the system to enhance functionality while maintaining compatibility with the original calling interfaces, allowing functions to add new functionality implementations while maintaining their original calling methods.
