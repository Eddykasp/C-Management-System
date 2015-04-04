#include <stdio.h>
#include <stdlib.h>

#include "data_structs.h"

int main()
{
    CUSTOMER *root = init_customer(1, "MAX");
    add_customer(root, 2, "TEST");

    print_customer(root);
    print_customer(root->next);
    return 0;
}
