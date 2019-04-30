#include <iostream>
#include <vector>
#include <algorithm>

struct item {
    int weight, value;
};

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<item> items(n);

    for (int i = 0; i < n; i++) {
        std::cin >> items[i].value >> items[i].weight;
    }

    std::vector<std::vector<int> > matrix(n + 1, std::vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (items[i - 1].weight <= j) {
                matrix[i][j] = std::max(matrix[i - 1][j],
                                        items[i - 1].value
                                        + matrix[i - 1][j
                                                        - items[i - 1].weight]);
                continue;
            }
            matrix[i][j] = matrix[i - 1][j];
        }
    }

    std::cout << matrix[n][k] << std::endl;
}
