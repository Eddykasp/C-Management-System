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
    CUSTOMER * new_node = init_customer(id, n);
    //init new node and connect left node to it
    insert_node(left_node, new_node);
    return new_node;
}

void print_customer(CUSTOMER * node)
{
    printf("CUSTOMER:\n");
    printf("ID: %d\n", node->id);
    printf("Name: %s\n", node->name);
}

void delete_node(CUSTOMER * node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
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
    else if(n < 0)
    {
        n*=-1;
        for(i=0; i<n; i++)
        {
            step = step->prev;
        }
    }
    else{}
    return step;
}

void insert_node(CUSTOMER * left_node, CUSTOMER * new_node)
{
    CUSTOMER * right_node = left_node->next;
    left_node->next = new_node;
    new_node->prev = left_node;

    right_node->prev = new_node;
    new_node->next = right_node;
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
