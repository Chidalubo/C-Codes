#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <limits>

// Define a k-ary heap
class KArHeap {
public:
    KArHeap(int k_val) : k(k_val) {}

    void insert(int value) {
        data.push_back(value);
        heapifyUp(data.size() - 1);
    }

    int extractMin() {
        if (data.empty()) {
            throw std::range_error("Heap is empty.");
        }
        int min = data.front();
        data[0] = data.back();
        data.pop_back();
        if (!data.empty()) {
            heapifyDown(0);
        }
        return min;
    }

    size_t size() const {
        return data.size();
    }

private:
    std::vector<int> data;
    int k;

    int parent(int i) { return (i - 1) / k; }
    int child(int i, int j) { return k * i + j + 1; }

    void heapifyUp(int index) {
        while (index != 0 && data[parent(index)] > data[index]) {
            std::swap(data[index], data[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int child_index, min_index;
        while ((child_index = child(index, 1)) < data.size()) {
            min_index = index;
            for (int j = 0; j < k; ++j) {
                if ((child_index + j) < data.size() && data[min_index] > data[child_index + j]) {
                    min_index = child_index + j;
                }
            }
            if (min_index == index) break;
            std::swap(data[index], data[min_index]);
            index = min_index;
        }
    }
};

// Function prototypes for testing
void testHeapCorrectness();
void testHeapEfficiency(int k, size_t N);

int main() {
    // Correctness test
    testHeapCorrectness();

    // Efficiency tests for different values of k and N
    testHeapEfficiency(2, 1000000);  // Binary heap
    testHeapEfficiency(3, 1000000);  // Ternary heap
    // Add more tests with different values of k and N as needed

    return 0;
}

void testHeapCorrectness() {
    KArHeap heap(2); // Testing with a binary heap
    std::vector<int> testValues = {3, 1, 6, 5, 9, 8};
    for (int value : testValues) {
        heap.insert(value);
    }

    std::cout << "Extracting values: ";
    while (heap.size() > 0) {
        std::cout << heap.extractMin() << " ";
    }
    std::cout << std::endl;
}

void testHeapEfficiency(int k, size_t N) {
    KArHeap heap(k);
    auto rng = std::default_random_engine {};
    std::vector<int> values(N);

    // Generate random values
    std::generate(values.begin(), values.end(), rng);

    // Time insertion
    auto start = std::chrono::high_resolution_clock::now();
    for (int value : values) {
        heap.insert(value);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto insert_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Time to insert " << N << " elements into a " << k << "-ary heap: " << insert_duration << " ms" << std::endl;

    // Time extraction
    start = std::chrono::high_resolution_clock::now();
    while (heap.size() > 0) {
        heap.extractMin();
    }
    end = std::chrono::high_resolution_clock::now();
    auto extract_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Time to extract all elements from a " << k << "-ary heap: " << extract_duration << " ms" << std::endl;
}
