#include <utility>
#include <stdexcept>
#include <initializer_list>
template<typename T>
class vector {
private:
    T* arr;
    unsigned s;
    unsigned cap;
    
public:
    vector() : arr{nullptr}, s{0}, cap{0} {}
    vector(std::initializer_list<T> list) {
        s = list.size();
        cap = s;

        arr = new T[cap];
        unsigned i = 0;
        for (auto j : list) {
            arr[i++] = j;
        }
    };
    //copy constructor
    vector(const vector<T>& second) {
        s = second.s;
        cap = second.cap;
        arr = new T[cap];
        for (unsigned j = 0; j < s; j++) {
            arr[j] = second.arr[j];
        }
    }
    //copy assignment
    vector<T>& operator=(const vector<T>& second) {
        if (this == &second) return *this;
        T* temp = new T[second.cap];
        for (unsigned j = 0; j < second.s; j++) {
            temp[j] = second.arr[j];
        }
        s = second.s;
        cap = second.cap;
        std::swap(arr, temp);       
        delete[] temp; //even if arr is nullptr it doesnt cause any harm since delete[] nullptr is safe
        return *this;
    }
    //move constructor
    vector(vector<T>&& second) noexcept {
        arr = second.arr;
        s = second.s;
        cap = second.cap;

        second.arr = nullptr;
        second.s = 0;
        second.cap = 0;
    }
    //move assignment
    vector<T>& operator=(vector<T>&& second) noexcept {
        if (this == &second) return *this;
        delete[] arr;
        arr = second.arr;
        s = second.s;
        cap = second.cap;

        second.arr = nullptr;
        second.s = 0;
        second.cap = 0;   
        
        return *this;
    }
    unsigned size() const {
        return s;
    }
    unsigned capacity() const{
        return cap;
    }
    T& operator[](const unsigned index) {
        if (index >= s) throw std::out_of_range("Index is out of bound!");
        return arr[index];
    }
    const T& operator[](const unsigned index) const {
        if (index >= s) throw std::out_of_range("Index is out of bound!");
        return arr[index];
    }
    void push_back(const T& data) {
        if (s < cap) {
            arr[s] = data;
            s++;
            return;
        }

        resize();
        arr[s] = data;
        s++;
        return;
    }
    ~vector() {
        delete[] arr;
    };
private:
    void resize() {
        unsigned tempCap;
        if (cap == 0) tempCap = 1;
        else tempCap = cap * 2;
        T* temp = new T[tempCap];
        for (unsigned i = 0; i < s; i++) {
            temp[i] = std::move(arr[i]);
        }
        delete[] arr;
        arr = temp;
        cap = tempCap;
    }
};