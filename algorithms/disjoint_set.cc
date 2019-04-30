#include <iostream>
#include <vector>

struct node {
    int   data, rank;
    node *parent;
    friend std ::ostream& operator << (std::ostream &out, const node *n)
    {
        out << "{ Data : " << n->data << ", Rank : " << n->rank << " , ";
        if (n->parent != n)
            out << n->parent;
        else
            out << "NULL";
        out << " }";
        return out;
    }
};

node * make_set(int data)
{
    node *n = new node;
    n->data   = data;
    n->parent = n;
    n->rank   = 0;
    return n;
}

void union_set(node *p1, node *p2)
{
    while (p1 != p1->parent) {
        p1 = p1->parent;
    }
    while (p2 != p2->parent) {
        p2 = p2->parent;
    }

    if (p1->rank >= p2->rank) {
        p2->parent = p1;
        p1->rank  += p1->rank == p2->rank ? 1 : 0;
        return;
    }

    p1->parent = p2;
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

std::ostream& operator << (std::ostream &out, const std::vector<node *> &n)
{
    for (size_t i = 0; i < n.size(); i++) {
        out << n[i] << std::endl;
    }
    return out;
}

int main()
{
    std::vector<node *> nodes(7);
    for (int i = 0; i < 7; i++) {
        nodes[i] = make_set(i + 1);
    }
    union_set(nodes[0], nodes[1]);
    union_set(nodes[1], nodes[2]);
    union_set(nodes[3], nodes[4]);
    union_set(nodes[5], nodes[6]);
    union_set(nodes[4], nodes[5]);
    union_set(nodes[2], nodes[6]);
    find_set(nodes[2]);
    find_set(nodes[6]);
    std::cout << nodes << std::endl;
    return 0;
}
