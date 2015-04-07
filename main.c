#include <stdio.h>
#include <stdlib.h>

#include "data_structs.h"

int main()
{
    CUSTOMER *root = init_customer(1, "MAX");
    CUSTOMER *current_node = root;
    add_customer(current_node, 2, "TEST");
    add_customer(current_node->next, 3, "TEST2");

    delete_next_node(current_node);

    print_customer(root);
    print_customer(root->next);
    print_customer(root->next->next);
    return 0;
}
