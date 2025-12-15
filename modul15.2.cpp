#include <iostream>
#include <cstring>

class String {
private:
    char* data;    
    int length;     

    static int counter; 

public:
    String() : String(80) {
    }

    String(int size) : length(size) {
        data = new char[length + 1];
        data[0] = '\0';
        counter++;
    }

    String(const char* str) : String(strlen(str)) {
        strcpy(data, str);
    }

    ~String() {
        delete[] data;
        counter--;
    }


    void print() const {
        std::cout << data << std::endl;
    }

 
    static int GetCount() {
        return counter;
    }
};

int String::counter = 0;
