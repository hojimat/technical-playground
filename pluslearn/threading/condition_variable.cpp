#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

const int MAX_NUMBER = 1000;

std::mutex mtx;
std::condition_variable cv;
int currentNumber = 1;

void printNumbers(int threadId) {
    while (true) {
        if (currentNumber > MAX_NUMBER) {
            break;
        }

        // Lock here:
        std::unique_lock<std::mutex> lock(mtx);

        if ((threadId == 1 && currentNumber % 2 == 1) || (threadId == 2 && currentNumber % 2 == 0)) {
            std::cout << "Thread " << threadId << ":" << currentNumber << std::endl;
            currentNumber++;

            mtx.unlock();
            cv.notify_all();
        } else {
            mtx.unlock();
            cv.wait(lock);
        }
    }
}


int main() {
    std::thread thread1(printNumbers, 1); // odd numbers
    std::thread thread2(printNumbers, 2); // even numbers

    thread1.join();
    thread2.join();

    return 0;

}