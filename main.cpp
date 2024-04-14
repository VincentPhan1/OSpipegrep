#include <iostream>
#include <mutex>
#include <vector>
#include <condition_variable>

#include "BoundBuffer.h"


template<typename T>
class Stage {
public:
    virtual void read(BoundBuffer<T> buffer) = 0;
    virtual void work() = 0;
    virtual void output(BoundBuffer<T> buffer) = 0;

    virtual ~Stage() {}
};

template<typename T>
class findFile : public Stage<T> {
private:

public:
    void read(BoundBuffer<T> &readBuffer) override {

    }

    void work() override {

    }

    void output(BoundBuffer<T> &writeBuffer) {

    }
};

template<typename T>
class filterFile : public Stage<T> {
private:

public:
    void read(BoundBuffer<T> &readBuffer) override {

    }

    void work() override {

    }

    void output(BoundBuffer<T> &writeBuffer) {

    }
};

template<typename T>
class generateLine : public Stage<T> {
private:

public:
    void read(BoundBuffer<T> &readBuffer) override {

    }

    void work() override {

    }

    void output(BoundBuffer<T> &writeBuffer) {

    }
};

template<typename T>
class filterLine : public Stage<T> {
private:

public:
    void read(BoundBuffer<T> &readBuffer) override {

    }

    void work() override {

    }

    void output(BoundBuffer<T> &writeBuffer) {

    }
};

void usage(char* name) {
    std::cerr << "Usage: " << name << " <buffsize> <filesize> <uid> <gid> <string>";
}
int main(int argc, char** argv) {
        if (argc < 6) {
            usage(argv[0]);
            exit(1);
        }

    return 0;
}
