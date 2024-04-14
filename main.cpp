#include <iostream>
#include <mutex>
#include <dirent.h>
#include <deque>

#include "BoundBuffer.h"


template<typename T>
class Stage {
public:
    virtual void read(BoundBuffer<T> buffer) = 0;
    virtual void work() = 0;
    virtual void output(BoundBuffer<std::string> buffer) = 0;

    virtual ~Stage() {}
};

template<typename T>
class findFile : public Stage<T> {
private:
    DIR* dir;
    std::deque<std::string> fileNames;


public:
    void read(BoundBuffer<T> &readBuffer) override {
    }

    void work() override {
        dir = opendir(".");

        if ((dir = opendir(".")) == NULL) {
            std::cerr << "Cannot open current directory.";
            exit(1);
        }

        struct dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            std::string str(entry->d_name);
            fileNames.push_back(str);
        }
    }

    void output(BoundBuffer<std::string> &writeBuffer) {
        while(!fileNames.empty()) {
            writeBuffer.put(fileNames.front());
            fileNames.pop_front();
        }
        writeBuffer.put("\\EOB\\");
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

    void output(BoundBuffer<std::string> &writeBuffer) {

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

    void output(BoundBuffer<std::string> &writeBuffer) {

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

    void output(BoundBuffer<std::string> &writeBuffer) {

    }
};

template<typename T>
void worker(Stage<T>* stage, BoundBuffer<T> input, BoundBuffer<std::string> output) {
    while(true){
        stage -> read();
        stage -> work();
        stage -> output();
    }
}

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
