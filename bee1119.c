#include <stdio.h>
#include <stdlib.h>

typedef struct __node
{
    int value;
    struct __node *previous;
    struct __node *next;
} node_t;

node_t *create_list(int);
node_t *remove_node(node_t *, node_t *);
int list_size(node_t *);
node_t *navigate(node_t *, int, int);

int main(int argc, char **argv)
{
    int total, stepK, stepM, i;
    node_t *circular_list, *currentK, *currentM, *nextK, *nextM;

    while (scanf("%d %d %d", &total, &stepK, &stepM), total)
    {
        circular_list = create_list(total);
        currentK = circular_list;
        currentM = circular_list->previous;

        while (list_size(circular_list) > 2)
        {
            currentK = navigate(currentK, stepK, 0);
            currentM = navigate(currentM, stepM, 1);

            if (currentK->next == currentM)
                nextK = currentM->next;
            else
                nextK = currentK->next;

            if (currentM->previous == currentK)
                nextM = currentK->previous;
            else
                nextM = currentM->previous;

            if (currentK == currentM)
            {
                printf("%3d,", currentM->value);
                circular_list = remove_node(circular_list, currentK);
            }
            else
            {
                printf("%3d%3d,", currentK->value, currentM->value);
                circular_list = remove_node(circular_list, currentM);
                circular_list = remove_node(circular_list, currentK);
            }

            currentK = nextK;
            currentM = nextM;
        }

        if (list_size(circular_list) == 2)
        {
            currentK = navigate(currentK, stepK, 0);
            currentM = navigate(currentM, stepM, 1);

            if (currentK == currentM)
                printf("%3d,%3d\n", currentK->value, currentK->next->value);
            else
                printf("%3d%3d\n", currentK->value, currentK->next->value);
        }
        else
            printf("%3d\n", circular_list->value);
    }

    return 0;
}

node_t *create_list(int size)
{
    node_t *new_node;
    node_t *previous_node = NULL;
    node_t *start = NULL;

    for (int i = 1; i <= size; ++i)
    {
        new_node = (node_t *)malloc(sizeof(node_t));
        new_node->value = i;

        if (start == NULL)
            start = new_node;
        else
        {
            previous_node->next = new_node;
            new_node->previous = previous_node;
        }

        previous_node = new_node;
    }

    start->previous = new_node;
    new_node->next = start;

    return start;
}

node_t *remove_node(node_t *list, node_t *node_to_remove)
{
    node_t *prev_node = node_to_remove->previous;
    node_t *next_node = node_to_remove->next;

    if (node_to_remove == list)
    {
        list = list->next;
        prev_node->next = list;
        list->previous = node_to_remove->previous;
    }
    else
    {
        prev_node->next = next_node;
        next_node->previous = prev_node;
    }

    free(node_to_remove);
    return list;
}

int list_size(node_t *list)
{
    int count;
    node_t *node = list;
    for (count = 1; list != node->next; ++count)
        node = node->next;

    return count;
}

node_t *navigate(node_t *list, int steps, int direction)
{
    node_t *node = list;
    if (direction == 0)
        while (--steps)
            node = node->next;
    else
        while (--steps)
            node = node->previous;

    return node;
}
