#include <vector>
using namespace std;

template<typename T>
class Stack {
    vector<T> arr;
public:
    void push(T data) {
        arr.push_back(data);
    }
    void pop() {
        arr.pop_back();
    }
    T top() {
        if(arr.size()!=0) {
            return arr[arr.size() - 1];
        }
        // or arr.back();
        return -1;
    }
    bool isEmpty() {
        return arr.size() == 0;
    }
};