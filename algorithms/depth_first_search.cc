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

void dfs(const matrix &graph, int vertex, std::vector<bool> &visited)
{
    for (unsigned int i = 0; i < graph.size(); i++) {
        if (graph[vertex][i] && !visited[i]) {
            visited[i] = true;
            std::cout << i << " ";
            dfs(graph, i, visited);
        }
    }
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
    std::vector<bool> visited(n, false);
    dfs(graph, source, visited);
    std::cout << std::endl;
}
