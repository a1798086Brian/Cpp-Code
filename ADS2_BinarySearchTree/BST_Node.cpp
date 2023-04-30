#include "BST_Node.h"

BST_Node::BST_Node() : left(nullptr), right(nullptr), data(0) {}
BST_Node::BST_Node(int input_data) : left(nullptr), right(nullptr), data(input_data) {}
BST_Node::BST_Node(BST_Node* input_left, BST_Node* input_right, int input_data) : left(input_left), right(input_right), data(input_data) {}

// intentionally did this in one line cos I thought it was cool xD