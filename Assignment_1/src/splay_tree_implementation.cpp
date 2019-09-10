#include "../include/splay_tree.hpp"

using namespace std;

class node
{
public:
    int data;
    node *left, *right;
};

class splay_tree_implementation : public splay_tree
{
private:
    int num_nodes;
    node *root;
    vector<int> traversal;

public:
    splay_tree_implementation();

    int get_num_nodes();

    node *create_new_node(int);
    node *left_rotate(node *);
    node *right_rotate(node *);
    node *splay(node *, int);

    int find(int);
    void insert(int);
    void remove(int);

    inline void pre_order_traversal(node *Node)
    {
        if (Node != NULL)
        {
            traversal.push_back(Node->data);
            pre_order_traversal(Node->left);
            pre_order_traversal(Node->right);
        }
    };
    inline void in_order_traversal(node *Node)
    {
        if (Node != NULL)
        {
            in_order_traversal(Node->left);
            traversal.push_back(Node->data);
            in_order_traversal(Node->right);
        }
    };
    inline void post_order_traversal(node *Node)
    {
        if (Node != NULL)
        {
            post_order_traversal(Node->left);
            post_order_traversal(Node->right);
            traversal.push_back(Node->data);
        }
    };

    vector<int> pre_order();
    vector<int> in_order();
    vector<int> post_order();

    ~splay_tree_implementation();
};

splay_tree_implementation::splay_tree_implementation()
{
    num_nodes = 0;
    root = NULL;
}

node *splay_tree_implementation::create_new_node(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = Node->right = NULL;
    return Node;
}

node *splay_tree_implementation::left_rotate(node *Node)
{
    node *temp = Node->right;
    Node->right = temp->left;
    temp->left = Node;

    return temp;
}

node *splay_tree_implementation::right_rotate(node *Node)
{
    node *temp = Node->left;
    Node->left = temp->right;
    temp->right = Node;

    return temp;
}

node *splay_tree_implementation::splay(node *Node, int data)
{
    if (!Node)
        return Node;

    if (Node->data == data)
        return Node;

    if (Node->data < data)
    {
        // cout << "SPLAY: Node " << Node->data << " < " << data << '\n';
        if (!Node->right)
            return Node;

        if (Node->right->data > data)
        {
            Node->right->left = splay(Node->right->left, data);

            if (Node->right->left)
                Node->right = right_rotate(Node->right);
        }

        else if (Node->right->data < data)
        {
            Node->right->right = splay(Node->right->right, data);
            Node = left_rotate(Node);
        }

        // cout << "SPLAY: Node " << Node->left->data << " probably = " << data << '\n';

        return (Node->right) ? left_rotate(Node) : Node;
    }

    else
    {
        // cout << "SPLAY: Node " << Node->data << " > " << data << '\n';
        if (!Node->left)
            return Node;

        if (Node->left->data > data)
        {
            Node->left->left = splay(Node->left->left, data);
            Node = right_rotate(Node);
        }

        else if (Node->left->data < data)
        {
            Node->left->right = splay(Node->left->right, data);
            if (Node->left->right)
                Node->left = left_rotate(Node->left);
        }

        // cout << "SPLAY: Node " << Node->left->data << " probably = " << data << '\n';

        return (Node->left) ? right_rotate(Node) : Node;
    }
}

int splay_tree_implementation::get_num_nodes()
{
    return num_nodes;
}

int splay_tree_implementation::find(int data)
{
    if ((root = splay(root, data))->data == data)
        return 1;
    return 0;
}

void splay_tree_implementation::insert(int data)
{
    if (!root)
    {
        root = create_new_node(data);
        this->num_nodes++;
    }

    root = splay(root, data);

    if (root->data != data)
    {
        node *Node = create_new_node(data);

        if (root->data < data)
        {
            Node->left = root;
            Node->right = root->right;
            root->right = NULL;
        }

        else
        {
            Node->right = root;
            Node->left = root->left;
            root->left = NULL;
        }

        root = Node;
        this->num_nodes++;
    }

    return;
}

void splay_tree_implementation::remove(int data)
{
    if (!root)
        return;

    root = splay(root, data);

    if (data != root->data)
        return;

    struct node *Node;

    if (root->left)
    {
        Node = root;
        root = splay(root->left, data);
        root->right = Node->right;
    }

    else
    {
        Node = root;
        root = root->right;
    }

    delete Node;
    this->num_nodes--;

    return;
}

vector<int> splay_tree_implementation::pre_order()
{
    traversal.clear();
    pre_order_traversal(root);
    return traversal;
}

vector<int> splay_tree_implementation::in_order()
{
    traversal.clear();
    in_order_traversal(root);
    return traversal;
}

vector<int> splay_tree_implementation::post_order()
{
    traversal.clear();
    post_order_traversal(root);
    return traversal;
}

splay_tree_implementation::~splay_tree_implementation()
{
    delete root;
    root = NULL;
    num_nodes = 0;
}