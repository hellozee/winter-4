#include <vector>
#include <list>
#include <utility>
#include <climits>
#include <set>
#include <iostream>

struct edge {
    int u;
    int v;
    int weight;
};

std::vector<edge> edges;

std::vector<std::list<std::pair<int, int> > > matrix(300);

void add_edge(int u, int v, int w)
{
    matrix[u].push_back(std::make_pair(v, w));
    matrix[v].push_back(std::make_pair(u, w));

    edge e { u, v, w };
    edges.push_back(e);
}

void remove_edge(int u, int v, int w, int pos)
{
    matrix[u].remove(std::make_pair(v, w));
    matrix[v].remove(std::make_pair(u, w));
    edges.erase(edges.begin() + pos);
}

int shortest_path(int u, int v)
{
    std::set<std::pair<int, int> > verts;

    std::vector<int> dist(300, INT_MAX);

    verts.insert(std::make_pair(0, u));
    dist[u] = 0;

    while (!verts.empty()) {
        std::pair<int, int> tmp = *(verts.begin());
        verts.erase(verts.begin());
        int u = tmp.second;
        std::list<std::pair<int, int> >::iterator i;
        for (i = matrix[u].begin(); i != matrix[u].end(); ++i) {
            int v      = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight) {
                if (dist[v] != INT_MAX)
                    verts.erase(verts.find(std::make_pair(dist[v], v)));

                dist[v] = dist[u] + weight;
                verts.insert(std::make_pair(dist[v], v));
            }
        }
    }

    return dist[v];
}

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        add_edge(u, v, w);
    }

    int minimum = INT_MAX;
    for (unsigned long i = 0; i < edges.size(); i++) {
        edge e = edges[i];
        remove_edge(e.u, e.v, e.weight, i);
        int distance = shortest_path(e.u, e.v);
        minimum = std::min(minimum, distance + e.weight);
        add_edge(e.u, e.v, e.weight);
    }

    std::cout << minimum << std::endl;
    return 0;
}
