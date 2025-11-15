#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex printMutex; // to prevent overlapping prints

void countRange(size_t start, size_t end, int id) {
    for (size_t i = start; i <= end; ++i) {
        std::lock_guard<std::mutex> lock(printMutex);
        std::cout << "Thread " << id << ": " << i << std::endl;
    }
}

int main() {
    const size_t total = 100000000;
    unsigned int numThreads = std::thread::hardware_concurrency();
    if (numThreads == 0) numThreads = 4;

    size_t chunkSize = total / numThreads;
    std::vector<std::thread> threads;

    for (unsigned int t = 0; t < numThreads; ++t) {
        size_t start = t * chunkSize + 1;
        size_t end = (t == numThreads - 1) ? total : (start + chunkSize - 1);
        threads.emplace_back(countRange, start, end, t);
    }

    for (auto &th : threads) {
        th.join();
    }

    std::cout << "Finished using " << numThreads << " threads." << std::endl;
    return 0;
}
