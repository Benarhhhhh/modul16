#include <iostream>


class Array {
private:
    int* data;
    int size;

public:
    Array() : data(nullptr), size(0) {}


    Array(int size) {
        this->size = size;
        data = new int[size];
    }

    Array(const Array& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~Array() {
        delete[] data;
    }

    void fill() {
        std::cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; i++) {
            std::cin >> data[i];
        }
    }


    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    void resize(int newSize) {
        int* newData = new int[newSize];

        int minSize = (newSize < size) ? newSize : size;
        for (int i = 0; i < minSize; i++) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        size = newSize;
    }



    int min() const {
        int m = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] < m)
                m = data[i];
        }
        return m;
    }

    int max() const {
        int m = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] > m)
                m = data[i];
        }
        return m;
    }
};
