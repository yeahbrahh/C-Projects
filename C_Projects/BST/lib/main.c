#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;

} Node;

Node *search(Node *root, const int key)
{
    if (root == NULL || key == root->value)
    {
        return root;
    }
    if (key < root->value)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }

}

Node *insert(Node *root, const int value)
{ 
    if (root == NULL)
    {   
        Node *node = malloc(sizeof(Node));
        node->value = value;
        node->left = NULL;
        node->right =NULL;
        return node;
    }
    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = insert(root->right, value);
    }
    
    return root;
}

void* delete(Node *node, const int key)
{
    if (is_leaf(node) && key < )
    {
        node = NULL;
        return;
    }

    if (has_one_child(node))
    {   
        node = node->left ? node->left : node->right;
    }

    if (has_two_children(node))
    {

    }



}

bool is_leaf(Node *node)
{
    return node->left == NULL && node->right == NULL;
}

bool has_one_child(Node *node)
{
    return node && (node->left != NULL || node->right != NULL);
}

bool has_two_children(Node * node)
{
    return node && node->left != NULL && node->right != NULL;
}

Node *find_successor(Node *node)
{

}



int *make_array(const int len) 
{   int *numbers = malloc(len * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {   
        numbers[i] = rand() % 100;
    }
    return numbers;
}

void print_tree(Node *root)
{
    if (root == NULL) return;

    print_tree(root->left);
    printf("%d ", root->value);
    print_tree(root->right);
}


int main(int argc, char *argv[])
{
    printf("This is my B-Tree!\n");

    int *array = make_array(12);
    Node *root = malloc(sizeof(Node));
    root->left = NULL;
    root->right = NULL;

    for (int k = 0; k < 12; k++)
    {
        insert(root, array[k]);
    }
    printf("Here is an insert-> \n");
    print_tree(root);

    printf();

    free(array);
    free(root);
}