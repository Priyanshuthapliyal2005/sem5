#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

// Constants
#define MaxItems 5        // Maximum items each producer/consumer handles
#define BufferSize 5      // Size of the circular buffer

// Shared resources
int buffer[BufferSize];   // Circular buffer
int in = 0, out = 0;      // Indices for insertion and removal
int itemCount = 0;        // Current number of items in the buffer
bool bufferFull = false;  // Flag to indicate if the buffer is full
bool bufferEmpty = true;  // Flag to indicate if the buffer is empty
int mutex = 1;            // Simulated mutex (1 = unlocked, 0 = locked)

// Function to lock the mutex
void lockMutex() {
    while (mutex == 0);  // Busy-wait until the mutex becomes available
    mutex = 0;           // Lock the mutex
}

// Function to unlock the mutex
void unlockMutex() {
    mutex = 1;           // Unlock the mutex
}

// Function to wait until the buffer is not full
void waitUntilNotFull() {
    while (bufferFull);  // Busy-wait until the buffer has space
}

// Function to wait until the buffer is not empty
void waitUntilNotEmpty() {
    while (bufferEmpty); // Busy-wait until the buffer has items
}

// Function to produce an item (returns a random number between 0 and 9)
int produceItem() {
    return rand() % 10;  // Simulates producing an item
}

// Function to insert an item into the buffer
void insertItem(int item) {
    buffer[in] = item;                       // Insert the item at the 'in' position
    in = (in + 1) % BufferSize;              // Update 'in' (circular buffer logic)
    itemCount++;                             // Increment item count
    if (itemCount == BufferSize) bufferFull = true;  // Set bufferFull if buffer is full
    bufferEmpty = false;                     // Buffer is no longer empty
}

// Function to remove an item from the buffer
int removeItem() {
    int item = buffer[out];                  // Remove the item from the 'out' position
    out = (out + 1) % BufferSize;            // Update 'out' (circular buffer logic)
    itemCount--;                             // Decrement item count
    if (itemCount == 0) bufferEmpty = true;  // Set bufferEmpty if buffer is empty
    bufferFull = false;                      // Buffer is no longer full
    return item;
}

// Producer thread function
void *producer(void *arg) {
    int id = *(int *)arg;  // Get the producer ID
    for (int i = 0; i < MaxItems; i++) {
        int item = produceItem();           // Produce an item
        waitUntilNotFull();                 // Wait until there is space in the buffer
        lockMutex();                        // Acquire the mutex
        insertItem(item);                   // Insert the item into the buffer
        printf("Producer %d: Inserted Item %d at %d\n", id, item, (in - 1 + BufferSize) % BufferSize);
        unlockMutex();                      // Release the mutex
        usleep(100000);                     // Simulate production delay
    }
    return NULL;
}

// Consumer thread function
void *consumer(void *arg) {
    int id = *(int *)arg;  // Get the consumer ID
    for (int i = 0; i < MaxItems; i++) {
        waitUntilNotEmpty();                // Wait until there are items in the buffer
        lockMutex();                        // Acquire the mutex
        int item = removeItem();            // Remove the item from the buffer
        printf("Consumer %d: Removed Item %d from %d\n", id, item, (out - 1 + BufferSize) % BufferSize);
        unlockMutex();                      // Release the mutex
        usleep(150000);                     // Simulate consumption delay
    }
    return NULL;
}

int main() {
    printf("Priyanshu Thapliyal\t SECTION-A2\t Roll no:51 \n");

    pthread_t producerThreads[5], consumerThreads[5]; // Threads for producers and consumers
    int producerIds[5] = {1, 2, 3, 4, 5};             // Producer IDs
    int consumerIds[5] = {1, 2, 3, 4, 5};             // Consumer IDs

    // Create producer threads
    for (int i = 0; i < 5; i++) {
        pthread_create(&producerThreads[i], NULL, producer, &producerIds[i]);
    }

    // Create consumer threads
    for (int i = 0; i < 5; i++) {
        pthread_create(&consumerThreads[i], NULL, consumer, &consumerIds[i]);
    }

    // Wait for producer threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(producerThreads[i], NULL);
    }

    // Wait for consumer threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(consumerThreads[i], NULL);
    }

    return 0;
}
