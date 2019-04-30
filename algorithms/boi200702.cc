#include <iostream>
#include <set>
#include <deque>
#include <list>
#include <utility>
#include <vector>

struct soldier : std::pair<int, int> {
    int  i;
    soldier(int x = 0, int y = 0) :
         std::pair<int, int>(x, y), i(-1)
    { }
};

int square(int x){ return x * x; }

int main()
{
    int length, width, n, r = 100, d = 2 * r;
    std::cin >> length >> width >> n;
    std::set<soldier> points;
    typedef std::set<soldier>::iterator itr;

    std::list<int> graph[n + 2];
    for (int i = 1; i <= n; i++) {
        soldier temp;
        std::cin >> temp.first >> temp.second;
        temp.i = i;
        soldier Q(temp.first - d, temp.second - d), R(temp.first + d,
                                                      temp.second + d);
        itr l = points.lower_bound(Q), u = points.upper_bound(R);
        for (itr j = l; j != u; ++j) {
            if (square(temp.first - j->first)
                + square(temp.second - j->second) <= square(d))
            {
                graph[i].push_back(j->i), graph[j->i].push_back(i);
            }
        }
        if (temp.second - r <= 0) {
            graph[i].push_back(0), graph[0].push_back(i);
        }
        if (temp.second + r >= width) {
            graph[i].push_back(n + 1), graph[n + 1].push_back(i);
        }
        points.insert(temp);
    }

    std::vector<int> visited(n + 2, 0);
    std::deque<int> q;
    q.push_back(0);

    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        if (visited[v])
            continue;
        visited[v] = 1;
        if (v == n + 1) {
            std::cout << 1 << "\n";
            return 0;
        }
        for (std::list<int>::iterator i = graph[v].begin();
             i != graph[v].end();
             ++i)
            q.push_back(*i);
    }
    std::cout << 0 << std::endl;
    return 0;
} // main
