#include <iostream>
#include <vector>
#include <algorithm>

struct pair {
    long long low, high;
    int       pos, score;
    friend std ::ostream& operator << (std::ostream &out, const pair &p)
    {
        out << p.low << " " << p.high;
        return out;
    }
};

bool compare_pitch(const pair &p1, const pair &p2)
{
    return p1.high < p2.high;
}

bool compare_position(const pair &p1, const pair &p2)
{
    return p1.pos < p2.pos;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<pair> singers(n);
    std::vector<int> points(n, 0);

    for (int i = 0; i < n; i++) {
        std::cin >> singers[i].low >> singers[i].high;
        singers[i].pos = i, singers[i].score = 0;
    }

    sort(singers.begin(), singers.end(), compare_pitch);

    for (int i = 0; i < n; i++) {
        singers[i].score = i * 2;
    }

    sort(singers.begin(), singers.end(), compare_position);

    for (int i = 0; i < n; i++) {
        std::cout << singers[i].score << " ";
    }
    return 0;
}
