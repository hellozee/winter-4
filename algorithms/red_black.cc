#include <iostream>

#define UNUSED(x) (void) x;

enum class node_color { red, black };

struct node {
    int        data;
    node *     parent, *left, *right;
    node_color color;
    node(int d = 0, node_color c = node_color::red, node *p = nullptr,
         node *l = nullptr, node *r = nullptr) :
        data(d), parent(p), left(l), right(r), color(c)
    { }
};

class rb_tree {
private:
    node *root;

public:
    rb_tree() :
        root(nullptr)
    { }

    node * insert(int data)
    {
        auto new_node = new node(data);
        if (root == nullptr) {
            root = new_node;
            new_node->color = node_color::black;
            return new_node;
        }
        auto root_copy = root;
        while (root_copy != nullptr) {
            if (root_copy->data >= data) {
                if (root_copy->left == nullptr) {
                    new_node->parent = root_copy;
                    root_copy->left  = new_node;
                    break;
                }
                root_copy = root_copy->left;
            } else {
                if (root_copy->right == nullptr) {
                    new_node->parent = root_copy;
                    root_copy->right = new_node;
                    break;
                }
                root_copy = root_copy->right;
            }
        }
        insert_fixup(new_node);
        return new_node;
    }

    void remove(node *x)
    {
        UNUSED(x)
    }

    void print()
    {
        print_tree(root);
        std::cout << std::endl;
    }

private:
    void print_tree(node *n)
    {
        if (n == nullptr) {
            std::cout << "{ NULL }";
            return;
        }
        std::cout << "{ Data: " << n->data << ", Color: "
                  << as_color(n->color) << ", Left : ";
        print_tree(n->left);
        std::cout << ", Right : ";
        print_tree(n->right);
        std::cout << " }";
    }

    void insert_fixup(node *beta)
    {
        if (beta->parent->color == node_color::black) {
            return;
        }
        auto daada = beta->parent->parent;
        auto baap  = beta->parent;
        if (daada->left == baap) {
            auto chacha      = daada->right;
            node_color color = node_color::black;
            if (chacha != nullptr) {
                color = chacha->color;
            }
            if (color == node_color::red) {
                // Case 1
                baap->color = chacha->color = node_color::black;
                beta        = daada;
                beta->color = node_color::red;
            } else {
                if (baap->right == beta) {
                    // Case 2
                    beta = baap;
                    left_rotate(beta);
                } else {
                    // Case 3
                    baap->color  = node_color::black;
                    daada->color = node_color::red;
                    beta         = daada;
                    right_rotate(beta);
                }
            }
        } else {
            auto chacha      = daada->left;
            node_color color = node_color::black;
            if (chacha != nullptr) {
                color = chacha->color;
            }
            if (color == node_color::red) {
                // Case 4
                baap->color = chacha->color = node_color::black;
                beta        = daada;
                beta->color = node_color::red;
            } else {
                if (baap->left == beta) {
                    // Case 5
                    beta = baap;
                    right_rotate(beta);
                } else {
                    // Case 6
                    baap->color  = node_color::black;
                    daada->color = node_color::red;
                    beta         = daada;
                    left_rotate(beta);
                }
            }
        }
        insert_fixup(beta);
        root->color = node_color::black;
    } // insert_fixup

    void remove_transplant(node *u, node *v)
    {
        if(u->parent == nullptr){
            root = v;
        }else if(u == u->parent->left) {
            u->parent->left = v;
        }else{
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void remove_fixup(node *x)
    {
        UNUSED(x)
    }

    void left_rotate(node *x)
    {
        auto y = x->right;
        x->right = y->left;
        if (x->right != nullptr) {
            x->left->parent = x;
        }
        y->left = x;
        if (x->parent == nullptr) {
            root = y;
        } else {
            if (x->parent->left == x) {
                x->parent->left = y;
            } else {
                x->parent->right = y;
            }
            y->parent = x->parent;
        }
        x->parent = y;
    }

    void right_rotate(node *y)
    {
        auto x = y->left;
        y->left = x->right;
        if (y->left != nullptr) {
            y->right->parent = y;
        }
        x->right = y;
        if (y->parent == nullptr) {
            root = x;
        } else {
            if (y->parent->left == y) {
                y->parent->left = x;
            } else {
                y->parent->right = x;
            }
            x->parent = y->parent;
        }
        y->parent = x;
    }

    std::string as_color(node_color color)
    {
        if (color == node_color::red) {
            return "Red";
        }
        return "Black";
    }
};

int main()
{
    rb_tree tree;
    tree.insert(7);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);
    tree.print();
}
