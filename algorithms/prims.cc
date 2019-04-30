#include <iostream>
#include <vector>
#include <queue>
#include <climits>

typedef std::vector<size_t> vec;
typedef std::vector<vec> matrix;

struct distance{
    size_t i, d;
    bool operator<(const distance &dist) const {
        return d > dist.d;
    }
};

std::vector<int> prims(matrix g, size_t v){
    std::vector<int> parent(g.size());
    vec visited(g.size());
    visited[v] = 1;
    std::priority_queue<distance> heap;
    for(size_t i=0;i<g.size();i++){
        if(i==v){
            parent[i] = -1;
            continue;
        }
        if(g[v][i]){
            heap.push(distance{i,g[v][i]});
            parent[i] = v;
        } else
            heap.push(distance{i,INT_MAX});
    }

    while(!heap.empty()){
        auto top = heap.top();
        heap.pop();
        if(visited[top.i])
            continue;
        visited[top.i] = 1;
        for(size_t i=0;i<g.size();i++){
            if(g[top.i][i] && !visited[i]){
                heap.push(distance{i,g[top.i][i]});
                parent[i] = top.i;
            }
        }
    }

    return parent;
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
    auto p = prims(graph,0);
    for(auto v : p){
        std::cout << v << " ";
    }
    std::cout << std::endl;
}
