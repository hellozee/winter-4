#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
#include <algorithm>

std::ostream&operator << (std::ostream &out, const std::vector<float> array)
{
    out << std::setprecision(2);
    for (unsigned long i = 0; i < array.size(); i++) {
        out << array[i] << " ";
    }
    out << std::endl;
    return out;
}

std::vector<float> sort(std::vector<float> &array, int bucket_count)
{
    std::vector<std::list<float> > buckets(bucket_count);

    for (unsigned long i = 0; i < array.size(); i++) {
        int index = bucket_count * array[i];
        buckets[index].push_back(array[i]);
    }

    for (int i = 0; i < bucket_count; i++) {
        buckets[i].sort();
    }

    std::vector<float> result;

    for (int i = 0; i < bucket_count; i++) {
        for (float item : buckets[i]) {
            result.push_back(item);
        }
    }
    return result;
}

int main()
{
    int testcases;
    std::cin >> testcases;
    std::cin.precision(2);
    while (testcases--) {
        int n, max = 0;
        std::cin >> n;
        std::vector<float> array(n, 0);
        for (int i = 0; i < n; i++) {
            std::cin >> array[i];
            if (max < array[i]) {
                max = array[i];
            }
        }
        auto result = sort(array, 10);
        std::cout << result;
    }
}
