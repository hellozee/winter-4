#include <iostream>
#include <vector>
#include <algorithm>

struct job {
    int start, end, profit;
    bool operator < (const job &j)
    {
        return end < j.end;
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<job> jobs(n);
    std::vector<int> profit(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> jobs[i].start >> jobs[i].end >> jobs[i].profit;
    }
    sort(jobs.begin(), jobs.end());

    for (int i = 0; i < n; i++) {
        profit[i] = jobs[i].profit;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (jobs[j].end > jobs[i].start) {
                continue;
            }
            profit[i] = std::max(profit[i], profit[j] + jobs[i].profit);
        }
    }
    std::cout << *std::max_element(profit.begin(), profit.end()) << std::endl;
}
