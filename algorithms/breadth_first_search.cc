#include <iostream>
#include <vector>
#include <queue>

typedef std::vector<std::vector<int> > matrix;

std::ostream&operator << (std::ostream &out, const std::vector<int> array)
{
    for (unsigned long i = 0; i < array.size(); i++) {
        out << array[i] << " ";
    }
    out << std::endl;
    return out;
}

void bfs(matrix graph, int source)
{
    int n = graph[0].size();
    std::vector<bool> visited(n, false);
    std::vector<int> distance(n, -1);
    std::queue<int> to_scan;

    to_scan.push(source);
    std::cout << source << std::endl;
    distance[source] = 0;
    visited[source]  = true;

    while (!to_scan.empty()) {
        int vert = to_scan.front();
        for (int i = 0; i < n; i++) {
            if (graph[vert][i] && !visited[i]) {
                to_scan.push(i);
                std::cout << i << " ";
                visited[i]  = true;
                distance[i] = graph[vert][i] + distance[vert];
            }
        }
        std::cout << std::endl;
        to_scan.pop();
    }

    std::cout << distance << std::endl;
}

int main()
{
    int n;
    std::cin >> n;
    matrix graph(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> graph[i][j];
        }
        graph[i][i] = 0;
    }
    int source;
    std::cin >> source;
    bfs(graph, source);
}
