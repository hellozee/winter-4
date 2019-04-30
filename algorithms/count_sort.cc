#include <iostream>
#include <vector>

std::ostream&operator << (std::ostream &out, const std::vector<int> array)
{
    for (unsigned long i = 0; i < array.size(); i++) {
        out << array[i] << " ";
    }
    out << std::endl;
    return out;
}

std::vector<int> sort(const std::vector<int> &array, int range)
{
    int n = array.size();
    std::vector<int> sorted(n, 0);
    std::vector<int> count(range + 1, 0);
    for (int i = 0; i < n; i++) {
        count[array[i]]++;
    }

    for (int i = 1; i <= range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        sorted[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    return sorted;
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
        auto result = sort(array, max);
        std::cout << result;
    }
}
