#include <iostream>
#include <thread>
#include <shared_mutex>
#include <mutex>

std::shared_mutex sm;
int shared_data = 0;

void reader(int id) {
    std::shared_lock lock(sm);
    std::cout << "Reader" << id << " reads " << shared_data << "\n";
}

void writer(int id) {
    std::unique_lock lock(sm);
    shared_data += 1;
    std::cout << "Writer" << id << " writes " << shared_data << "\n";
}


int main() {
    std::thread readers[5];
    std::thread writers[2];

    for(int i=0; i<5; ++i) {
        readers[i] = std::thread(reader, i);
    }

    for(int i=0; i<2; ++i) {
        writers[i] = std::thread(writer, i);
    }

    for(int i=0; i<5; ++i) {
        readers[i].join();
    }
    
    for(int i=0; i<2; ++i) {
        writers[i].join();
    }

    return 0;
}