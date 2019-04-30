#include <iostream>
#include <vector>
#include <cmath>

std::ostream&operator << (std::ostream &out, const std::vector<int> array)
{
    for (unsigned long i = 0; i < array.size(); i++) {
        out << array[i] << " ";
    }
    out << std::endl;
    return out;
}

void isort(std::vector<int> &array, int position)
{
    int rfactor = std::pow(10, position);
    int qfactor = std::pow(10, position - 1);
    for (unsigned long i = 1; i < array.size(); i++) {
        int key  = (array[i] % rfactor) / qfactor;
        int temp = array[i];
        int j    = i - 1;
        while (j >= 0 && key < (array[j] % rfactor) / qfactor) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

void sort(std::vector<int> &array)
{
    int digits = 0;
    int temp   = array[0];
    while (temp) {
        temp /= 10;
        digits++;
    }

    for (int i = 1; i <= digits; i++) {
        isort(array, i);
    }
}

int main()
{
    int testcases;
    std::cin >> testcases;
    while (testcases--) {
        int n, max = 0;
        std::cin >> n;
        std::vector<int> array(n, 0);
        for (int i = 0; i < n; i++) {
            std::cin >> array[i];
            if (max < array[i]) {
                max = array[i];
            }
        }
        sort(array);
        std::cout << array;
    }
}
