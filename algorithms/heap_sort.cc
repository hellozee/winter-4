#include <iostream>
#include <vector>

void heapify(std::vector<int> &array, int index, int size)
{
    int left    = 2 * index;
    int right   = left + 1;
    int largest = index;

    if (left < size && array[left] > array[index]) {
        largest = left;
    }

    if (right < size && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != index) {
        int temp = array[largest];
        array[largest] = array[index];
        array[index]   = temp;
        heapify(array, largest, size);
    }
}

void build_max_heap(std::vector<int> &array)
{
    for (int i = array.size() / 2; i >= 0; i--) {
        heapify(array, i, (int) array.size());
    }
}

void sort(std::vector<int> &array)
{
    build_max_heap(array);
    int size = (int) array.size();
    for (int i = size - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        size--;
        heapify(array, 0, size);
    }
}

std::ostream&operator << (std::ostream &out, const std::vector<int> array)
{
    for (unsigned long i = 0; i < array.size(); i++) {
        out << array[i] << " ";
    }
    out << std::endl;
    return out;
}

int main()
{
    int testcases;
    std::cin >> testcases;
    while (testcases--) {
        int n;
        std::cin >> n;
        std::vector<int> array(n, 0);
        for (int i = 0; i < n; i++) {
            std::cin >> array[i];
        }
        sort(array);
        std::cout << array;
    }
}
