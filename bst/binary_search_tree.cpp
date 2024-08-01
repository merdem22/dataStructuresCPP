#include <stdio.h>

class binary_search_tree
{
private:
    struct node
    {
        int key;
        int val;
        node *l;
        node *r;
        node *p;
        node(int _key, int _val) : key(_key), val(_val), l(nullptr), r(nullptr), p(nullptr) {}
    };

    node *root;

    // returns node with key k on tree rooted on x, if node not present returns nullptr.
    node *search(int k, node *x)
    {

        if (x == nullptr || x->key == k)
        {
            return x;
        }
        if (k < x->key)
        {
            return search(k, x->l);
        }
        else
        {
            return search(k, x->r);
        }
    }

    node *min(node *x) // returns the min node on the tree rooted on x (nullptr if tree empty.)
    {
        if (x == nullptr || x->l == nullptr)
        {
            return x;
        }
        return min(x->l);
    }

    node *max(node *x)
    {
        if (x == nullptr || x->r == nullptr)
        {
            return x;
        }
        return max(x->r);
    }

    node *sucessor(node *x) // returns the next largest element of x in the tree
    {
        if (x->r != nullptr)
        {
            return min(x->r);
        }
        else // if there isn't a right child, then the lowest ancestor which is a right ancestor to the ancestors of x is the successor.
        {
            node *y = x->p;
            while (y != nullptr && y->r == x)
            {
                x = y;
                y = x->p;
            }
            return y;
        }
    }

    node *predecessor(node *x) // returns the node the with the next smallest key if present if there exists one such node (x is not the min)
    {
        if (x->l != nullptr)
        {
            return max(x->l);
        }
        else
        {
            node *y = x->p;
            while (y != nullptr && y->l == x)
            {
                x = y;
                y = x->p;
            }
            return y;
        }
    }

    void *insert(binary_search_tree t, node *z) // inserts node z into tree t
    {
        node *x = t.root;
        node *y = nullptr;
        while (x != nullptr)
        {
            y = x;
            if (z->key < x->key)
            {
                x = x->l;
            }
            else
            {
                x = x->r;
            }
        }
        if (y == nullptr)
        {
            t.root = z;
        }
        else if (z->key < y->key)
        {
            y->l = z;
        }
        else
        {
            y->r = z;
        }
        // cont determine z relation to y
    }

    void *replaceSubtree(binary_search_tree t, node *u, node *v) // replaces subtree rooted at u with subtree rooted at v, will be used for delete. //doesn't update v->l or v->r the caller should.
    {
        if (u->p == nullptr)
        {
            t.root = v;
        }
        else if (u == u->p->l)
        {
            u->p->l = v;
        }
        else
        {
            u->p->r = v;
        }

        if (v != nullptr)
        {
            v->p = u->p;
        }
    }

    void deleteNode(binary_search_tree t, node *z)
    {
        if (z->l == nullptr)
        {
            replaceSubtree(t, z, z->r);
        }
        else if (z->r == nullptr)
        {
            replaceSubtree(t, z, z->l);
        }
        else
        {
            node *y = min(z->r);
            if (y != z->r)
            {
                replaceSubtree(t, y, y->r);
                y->r = z->r;
                y->r->p = y;
            }
            replaceSubtree(t, z, y);
            y->l = z->l;
            y->l->p = y;
        }
    }
};
