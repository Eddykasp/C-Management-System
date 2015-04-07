#include "data_structs.h"

CUSTOMER * init_customer(int i, char n[])
{
    CUSTOMER *root = malloc(sizeof(CUSTOMER));
    root->id = i;
    strcpy(root->name, n);
    root->next = root;
    root->prev = root;
    return root;
}

CUSTOMER * add_customer(CUSTOMER * left_node, int id, char n[])
{
    CUSTOMER * right_node = left_node->next, * new_node;
    //init new node and connect left node to it
    left_node->next = init_customer(id, n);
    new_node = left_node->next;
    //connect new node to left node
    new_node->prev = left_node;
    //connect new node to right node
    new_node->next = right_node;
    //connect right node to new node
    right_node->prev = new_node;
    return new_node;
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

CUSTOMER * find_smallest_id(CUSTOMER * root)
{
    CUSTOMER * node = root, * low_node;
    do
    {
        if(low_node->id > node->id)
        {
            low_node = node;
        }
        node = node->next;
    }while(node!=root);
    return low_node;
}

int get_length(CUSTOMER * root)
{
    CUSTOMER * node = root;
    int length = 0;
    do
    {
        node = node->next;
        length++;
    }while(node!=root);
    return length;
}

CUSTOMER * move_steps(CUSTOMER * node, int n)
{
    int i;
    CUSTOMER * step = node;
    if(n > 0)
    {
        for(i=0; i<n; i++)
        {
            step = step->next;
        }
    }
    else
    {
        n*=-1;
        for(i=0; i<n; i++)
        {
            step = step->prev;
        }
    }
    return step;
}

void sort_by_id(CUSTOMER * node)
{
    CUSTOMER * root = find_smallest_id(node), temp;
    int l = get_length(root), i, j;
    for(i=0; i<l-1; i++)
    {
        for(j=0; j<l-i-1; j++)
        {
            if(move_steps(root,j)->id > move_steps(root, j+1))
            {

            }
        }
    }
}
