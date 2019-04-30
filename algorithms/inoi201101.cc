#include <iostream>
#include <vector>

std::vector<int> A;
int N, K;
int d, max_d, max_e_here;

const int nil = -20000;

int gmin(int x, int y)
{
    int i, min = nil;
    for (i = x; i <= y; i++) {
        if (A[i] <= max_d && A[i] > min) {
            min = A[i];
        }
    }
    return min;
}

void sum(int x, int y)
{
    if (A[y] < max_d && K > 0) {
        if (d < K) {
            d++;
        }
        if (d == K) {
            max_e_here = max_e_here + max_d;
            max_d      = gmin(x, y);
        }
    } else   {
        max_e_here = max_e_here + A[y];
    }
}

int main()
{
    int i, max_so_far, s;
    std::cin >> N >> K;
    A.resize(N);

    for (i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    max_e_here = 0;
    d          = 0;
    max_d      = 0;
    max_so_far = 0;
    s          = 0;

    for (i = 0; i < N; i++) {
        sum(s, i);
        if (max_e_here < A[i]) {
            d          = 0;
            max_d      = 0;
            max_e_here = 0;
            s          = i;
            sum(s, i);
        }
        if (max_e_here > max_so_far) {
            max_so_far = max_e_here;
        }
    }

    std::cout << max_so_far << std::endl;
    return 0;
}
