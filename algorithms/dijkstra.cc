#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

typedef std::vector<size_t> vec;
typedef std::vector<vec> matrix;

struct distance{
    size_t i, d;
    bool operator<(const distance &dist) const {
        return d > dist.d;
    }
};

vec dijkstra(matrix g, int v){
    vec map(g.size(), INT_MAX);
    std::priority_queue<distance> heap;
    vec visited(g.size(), 0);
    map[v] = 0;
    visited[v] = 1;
    for(size_t i=0;i<g.size();i++){
        if((int)i==v)
            continue;
        if(g[v][i])
            heap.push(distance{i, g[v][i]});
        else
            heap.push(distance{i, INT_MAX});
    }

    while(!heap.empty()){
        auto top = heap.top();
        heap.pop();
        if(visited[top.i])
            continue;
        visited[top.i] = 1;
        map[top.i] = top.d;
        for(size_t i=0;i<g.size();i++)
            if(g[top.i][i] && !visited[i])
                if(g[top.i][i] + top.d < map[i])
                    heap.push(distance{i,g[top.i][i] + top.d});
    }
    return map;
}

int main(){
    int n;
    std::cin >> n;
    matrix graph(n, vec(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cin >> graph[i][j];
        }
    }
    auto abc = dijkstra(graph,0);
    for(auto a : abc){
        std::cout << a << " ";
    }
    std::cout << std::endl;
}
