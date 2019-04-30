#include <iostream>
#include <vector>
#include <algorithm>

struct edge {
    int length, from, to;
    bool operator < (const edge &e)
    {
        return length < e.length;
    }
};

struct node {
    int   rank, vertex;
    node *parent;
    friend std ::ostream& operator << (std::ostream &out, const node *n)
    {
        out << "{ Vertex : " << n->vertex << ", Rank : " << n->rank
            << " , Parent : ";
        if (n->parent != n)
            out << n->parent;
        else
            out << "NULL";
        out << " }";
        return out;
    }
};

node * make_set(int v)
{
    node *n = new node;
    n->rank   = 0;
    n->parent = n;
    n->vertex = v;
    return n;
}

node * find_set(node *n)
{
    node *result = n;
    while (result->parent != result) {
        result = result->parent;
    }
    n->parent = result;
    return result;
}

void union_set(node *p1, node *p2)
{
    p1 = find_set(p1);
    p2 = find_set(p2);
    if (p1->rank >= p2->rank) {
        p2->parent = p1;
        p1->rank  += p1->rank == p2->rank ? 1 : 0;
        return;
    }
    p1->parent = p2;
}

int main()
{
    int v, e;

    std::cin >> v >> e;

    std::vector<node *> nodes(v);
    std::vector<edge> edges(e);

    for (int i = 0; i < v; i++) {
        nodes[i] = make_set(i);
    }

    for (int i = 0; i < e; i++) {
        std::cin >> edges[i].from >> edges[i].to >> edges[i].length;
    }

    sort(edges.begin(), edges.end());
    int mst_length = 0;

    for (int i = 0; i < e; i++) {
        node *n1 = nodes[edges[i].from];
        node *n2 = nodes[edges[i].to];
        if (find_set(n1) != find_set(n2)) {
            union_set(n1, n2);
            mst_length += edges[i].length;
        }
    }

    std::cout << mst_length << std::endl;

    for (int i = 0; i < v; i++) {
        std::cout << nodes[i] << std::endl;
    }
} // main
