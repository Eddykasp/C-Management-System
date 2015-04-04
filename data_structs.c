#include "data_structs.h"

CUSTOMER * init_customer(int i, char n[])
{
    CUSTOMER *root = malloc(sizeof(CUSTOMER));
    root->id = i;
    strcpy(root->name, n);
    root->next = root;
    //printf("Initialized new Customer list at address %d: id: %d, %s\n", root, root->id, root->name);
    return root;
}

CUSTOMER * add_customer(CUSTOMER * node, int id, char n[])
{
    CUSTOMER * root = node->next;
    node->next = init_customer(id, n);
    node->next->next = root;
    return node->next;
}

void print_customer(CUSTOMER * node)
{
    printf("CUSTOMER:\n");
    printf("ID: %d\n", node->id);
    printf("Name: %s\n", node->name);
}

void delete_next_node(CUSTOMER * prev_node)
{
    prev_node->next = prev_node->next->next;
}
