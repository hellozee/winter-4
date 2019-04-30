#include <vector>
#include <iostream>
#include <chrono>

namespace chr = std::chrono;

std::ostream&operator << (std::ostream &out, const std::vector<int> array)
{
    for (unsigned long i = 0; i < array.size(); i++) {
        out << array[i] << " ";
    }
    out << std::endl;
    return out;
}

void sort(std::vector<int> array)
{
    int count = 0;
    for (unsigned long i = 1; i < array.size(); i++) {
        int key = array[i];
        int j   = i - 1;
        while (j >= 0 && key < array[j]) {
            array[j + 1] = array[j];
            j--;
            count++;
        }
        array[j + 1] = key;
    }
    std::cout << "Swaps : " << count << " Size : " << array.size() << std::endl;
}

int main()
{
    int testcases;
    std::cin >> testcases;
    while (testcases--) {
        int n;
        std::cin >> n;
        std::vector<int> elements(n, 0);
        for (int i = 0; i < n; i++) {
            std::cin >> elements[i];
        }
        auto start = chr::high_resolution_clock::now();
        sort(elements);
        auto finish = chr::high_resolution_clock::now();
        std::cout << "Time : " << chr::duration_cast<chr::microseconds>(
            finish - start).count() << std::endl;
    }
}
