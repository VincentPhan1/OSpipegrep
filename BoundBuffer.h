#ifndef BOUNDBUFFER_H
#define BOUNDBUFFER_H

#include <vector>
#include <mutex>
#include <condition_variable>

template <typename T>
class BoundBuffer {
private:
    std::vector<T> buffer;
    size_t capacity;
    size_t front, rear, count;
    std::mutex mutex;
    std::condition_variable not_full, not_empty;

public:
    BoundBuffer(size_t capacity);
    void put(T item);
    T get();
};


#endif
