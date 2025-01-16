#include "main.h"

/* Fuction for multiplication */
int multiplication(Dll **head, Dll **tail, Dll **head2, Dll **tail2, Dll **head3, Dll **tail3) {
    if ((*tail)->data == 0 || (*tail2)->data == 0) {
        return FAILURE;
    }

    Dll *temp1 = *head;
    Dll *temp2 = *head2;

    /* Determine the lengths of the lists */
    int len1 = 0, len2 = 0;
    while (temp1) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2) {
        len2++;
        temp2 = temp2->next;
    }

    /* Allocate the result array */
    int result_size = len1 + len2;
    int *result_array = (int *)calloc(result_size, sizeof(int));
    if (!result_array) return FAILURE;

    /* Perform multiplication */
    temp1 = *tail;
    int i = 0;
    while (temp1) {
        temp2 = *tail2;
        int j = i;
        while (temp2) {
            result_array[j] += temp1->data * temp2->data;
            temp2 = temp2->prev;
            j++;
        }
        temp1 = temp1->prev;
        i++;
    }

    /* Add carry and convert to linked list */
    int carry = 0;
    for (i = 0; i < result_size; i++) {
        result_array[i] += carry;
        carry = result_array[i] / 10000;
        result_array[i] %= 10000;
        if (result_array[i] != 0 || carry != 0) {
            if (insert_at_first(head3, tail3, result_array[i]) == FAILURE) {
                free(result_array);
                return FAILURE;
            }
        }
    }

    return SUCCESS;
}

