#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                     order using the Cocktail Shaker Sort algorithm.
 * @list: Pointer to the pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *current;
    int swapped;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        current = *list;

        while (current->next != NULL) {
            if (current->n > current->next->n) {
                swap_nodes(list, &current, &current->next);
                swapped = 1;
                print_list(*list);
            } else {
                current = current->next;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        while (current->prev != NULL) {
            if (current->n < current->prev->n) {
                swap_nodes(list, &current, &current->prev);
                swapped = 1;
                print_list(*list);
            } else {
                current = current->prev;
            }
        }
    } while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the pointer to the head of the list.
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 */
void swap_nodes(listint_t **list, listint_t **a, listint_t **b)
{
    listint_t *prev_a, *next_a, *prev_b, *next_b;

    prev_a = (*a)->prev;
    next_a = (*a)->next;
    prev_b = (*b)->prev;
    next_b = (*b)->next;

    if (prev_a)
        prev_a->next = *b;
    if (next_a)
        next_a->prev = *b;
    if (prev_b)
        prev_b->next = *a;
    if (next_b)
        next_b->prev = *a;

    (*a)->prev = prev_b;
    (*a)->next = next_b;
    (*b)->prev = prev_a;
    (*b)->next = next_a;

    if (!prev_a)
        *list = *b;
    else if (!prev_b)
        *list = *a;
}

