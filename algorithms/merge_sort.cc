#include <iostream>
#include <vector>

int comparisons;

std::ostream&operator << (std::ostream &out, const std::vector<int> array)
{
    for (unsigned long i = 0; i < array.size(); i++) {
        out << array[i] << " ";
    }
    out << std::endl;
    return out;
}

std::vector<int> merge(const std::vector<int> fhalf,
     const std::vector<int>                   shalf)
{
    std::vector<int> result(fhalf.size() + shalf.size(), 0);
    unsigned long i = 0, j = 0;

    while (i < fhalf.size() && j < shalf.size()) {
        if (fhalf[i] < shalf[j]) {
            result[i + j] = fhalf[i];
            i++;
        } else {
            result[i + j] = shalf[j];
            j++;
        }
    }

    while (i < fhalf.size()) {
        result[i + j] = fhalf[i];
        i++;
    }

    while (j < shalf.size()) {
        result[i + j] = shalf[j];
        j++;
    }

    return result;
}

std::vector<int> sort(std::vector<int> array, int start, int end)
{
    if (end - start == 1) {
        return array;
    }
    std::vector<int> fhalf, shalf;
    int mid = start + (end - start) / 2;

    for (int i = start; i < mid; i++) {
        fhalf.push_back(array[i]);
    }

    for (int i = mid; i < end; i++) {
        shalf.push_back(array[i]);
    }

    return merge(sort(fhalf, 0, fhalf.size()), sort(shalf, 0, shalf.size()));
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
        auto temp = sort(array, 0, n);
        std::cout << temp;
    }
}
