#include <iostream>
#include <vector>

void sort(std::vector<int> &array, int start, int end)
{
    int left = start, right = end;
    if (left >= right)
        return;

    for (int i = left; i <= right; i++) {
        if (array[i] < array[right]) {
            int temp = array[i];
            array[i]    = array[left];
            array[left] = temp;
            left++;
        }
    }

    int temp = array[left];
    array[left]  = array[right];
    array[right] = temp;

    sort(array, start, left - 1);
    sort(array, left + 1, end);
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
        sort(array, 0, n - 1);
        std::cout << array;
    }
}
