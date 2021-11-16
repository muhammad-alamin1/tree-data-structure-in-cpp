#include <iostream>

using namespace std;

typedef struct node Tree_Node;
struct node
{
    int data;
    Tree_Node *left;
    Tree_Node *right;
};

Tree_Node *create_tree_node(int item);
void add_left_child(Tree_Node *root, Tree_Node *child);
void add_right_child(Tree_Node *root, Tree_Node *child);
Tree_Node *create_tree(void);

int main(void)
{
    Tree_Node *root;

    root = create_tree();
    cout << "Root data: " << root->data << endl;

    return 0;
}

// Create Tree Node
Tree_Node *create_tree_node(int item)
{
    Tree_Node *new_node = new Tree_Node;

    if(new_node == NULL)
    {
        cout << "Error! Could not create a Tree new node.\n";
        exit(1);
    }

    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
    delete new_node;
}

// add left child
void add_left_child(Tree_Node *root, Tree_Node *child)
{
    root->left = child;
}

// add right child
void add_right_child(Tree_Node *root, Tree_Node *child)
{
    root->right = child;
}

// Create Tree
Tree_Node *create_tree(void)
{
    Tree_Node *five = create_tree_node(5);
    Tree_Node *nine = create_tree_node(9);
    Tree_Node *three = create_tree_node(3);
    add_left_child(five, nine);
    add_right_child(five, three);

    Tree_Node *four = create_tree_node(4);
    Tree_Node *eight = create_tree_node(8);
    add_left_child(nine, four);
    add_right_child(nine, eight);

    Tree_Node *two = create_tree_node(2);
    Tree_Node *one = create_tree_node(1);
    add_left_child(four, two);
    add_right_child(four, one);

    Tree_Node *five_sec = create_tree_node(5);
    add_right_child(three, five_sec);

    Tree_Node *six = create_tree_node(6);
    Tree_Node *seven = create_tree_node(7);
    add_left_child(five, six);
    add_right_child(five, seven);

    return five;
}
