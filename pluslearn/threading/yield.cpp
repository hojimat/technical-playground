#include <iostream>
#include <thread>
#include <mutex>

const int MAX_NUMBER = 100;
std::mutex mtx;
int currentNumber = 1;

void printOdd() {
    while (true) {

        std::unique_lock<std::mutex> lock(mtx);

        if (currentNumber > MAX_NUMBER) {
            break;
        }

        if (currentNumber % 2 == 1) {
            std::cout << "Odd: " << currentNumber << std::endl;
            currentNumber++;
        }

        lock.unlock();
        std::this_thread::yield();

    }
}

void printEven() {
    while (true) {

        std::unique_lock<std::mutex> lock(mtx);

        if (currentNumber > MAX_NUMBER) {
            break;
        }

        if (currentNumber % 2 == 0) {
            std::cout << "Even: " << currentNumber << std::endl;
            currentNumber++;
        }

        lock.unlock();
        std::this_thread::yield();

    }
}

int main() {
    std::thread thread1(printOdd);
    std::thread thread2(printEven);

    thread1.join();
    thread2.join();

    return 0;
}