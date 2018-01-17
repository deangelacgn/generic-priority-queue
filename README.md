# generic-priority-queue

This PQ(short for Priority Queue) class is implemented with a binary heap.You can find below a list with all public methods available:

* Push() - Inserts a new element in the queue and sorts it by priority. 
* Toss() - Inserts a new element in the queue without sorting it by priority.
* Pop() - Removes an element from the queue.
* Empty() - Returns true if priority queue is empty and false if it is not.
* Size() - Returns the number of elements in the queue.

### Prerequisites

In order to use this PQ class your compiler needs to support C++14 Standard. If you use a GCC compiler, at least GCC 4.9 is needed.

### How to use

Clone this repo to your local machine and move your .cpp files to the src folder inside the project.

## Running the tests

Inside the src folder you will find a drive_pq.cpp file that has a few unit tests. Compile it and run it to check if everything is okay.

```
g++ -std=c++14 drive_pq.cpp -g && ./a.out
```

If all tests pass, you can start playing around with the PQ by including pq.h in your own .cpp files.

## Authors

* Deangela C. G. Neves
* Maria Clara Martins 
