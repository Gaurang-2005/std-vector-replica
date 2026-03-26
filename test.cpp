#include <iostream>
#include "vector.hpp"

int main() {
vector<int> v;

for (int i = 1; i <= 5000; i++) {
    v.push_back(i);

    if (i % 200 == 0) {
        std::cout << "After " << i << " insertions:\n";
        std::cout << "Size: " << v.size() 
                  << ", Capacity: " << v.capacity() << "\n\n";
    }
}

return 0;


}
