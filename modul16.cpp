#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    size_t size;

public:
    explicit String(size_t n) : size(n) {
        data = new char[size + 1]{};
    }

    explicit String(const char* str = "") {
        size = strlen(str);
        data = new char[size + 1];
        strcpy(data, str);
    }

    String(const String& other) : size(other.size) {
        data = new char[size + 1];
        strcpy(data, other.data);
    }

    String(String&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

   
    ~String() {
        delete[] data;
    }

    size_t length() const { return size; }        
    bool empty() const { return size == 0; }      

    const char* c_str() const { return data; }    

    void print() const {                         
        if (data != nullptr) 
        {
            std::cout << data;
        }
        else{
            std::cout << "(null)";
        }

    }
};

