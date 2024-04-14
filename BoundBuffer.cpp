//
// Created by vince on 4/13/2024.
//

#include "BoundBuffer.h"
template <typename T>
BoundBuffer<T>::BoundBuffer(size_t capacity) : capacity(capacity), front(0), rear(0), count(0) {
    buffer.resize(capacity);
}

/**
 * @brief Puts an item into the buffer.
 *
 * Adds an item to the buffer if there's space available.
 * If the buffer is full, it waits until there's space available before proceeding.
 *
 * @param item The item to be added to the buffer.
 */

template <typename T>
void BoundBuffer<T>::put(T item) {
    std::unique_lock<std::mutex> lock(mutex);
    not_full.wait(lock, [this]() { return count < capacity; });

    buffer[rear] = item;
    rear = (rear + 1) % capacity;
    ++count;

    not_empty.notify_one();
}

/**
 * @brief Gets an item from the buffer.
 *
 * Removes an item from the buffer if there's data available.
 * If the buffer is empty, it waits until there's data available before proceeding.
 *
 * @return The item retrieved from the buffer.
 */
template <typename T>
T BoundBuffer<T>::get() {
    std::unique_lock<std::mutex> lock(mutex);
    not_empty.wait(lock, [this]() { return count > 0; });

    T item = buffer[front];
    front = (front + 1) % capacity;
    --count;

    not_full.notify_one();
    return item;
}
