#include <iostream>
#include <vector>
#include <string>

std::vector<int> failure_indexes(std::string pattern)
{
    std::vector<int> findexes(pattern.size(), 0);

    for (unsigned long i = 1, j = 0; i < pattern.size();) {
        if (pattern[i] == pattern[j]) {
            j++;
            findexes[i] = j;
            i++;
            continue;
        }

        if (j > 0) {
            j = findexes[j - 1];
        } else {
            findexes[i] = 0;
            i++;
        }
    }

    return findexes;
}

int kmp(std::string text, std::string pattern)
{
    auto findexes = failure_indexes(pattern);
    size_t j      = 0;
    for (size_t i = 0; i < text.size() && j < pattern.size();) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            continue;
        }
        if (j > 0)
            j = findexes[j - 1];
        else
            i++;
    }
    return j;
}

int main()
{
    std::string text, pattern;
    std::cin >> text >> pattern;
    std::cout << kmp(text, pattern) << std::endl;
}
