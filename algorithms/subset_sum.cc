#include <iostream>
#include <vector>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> values(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i];
    }
    std::vector<std::vector<int> > subset(n + 1,
                                          std::vector<int>(k + 1, false));
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= values[i - 1]) {
                subset[i][j] = subset[i - 1][j] ||
                               subset[i - 1][j - values[i - 1]];
                continue;
            }
            subset[i][j] = subset[i - 1][j];
        }
    }
    std::cout << subset[n][k] << std::endl;
    return 0;
}
