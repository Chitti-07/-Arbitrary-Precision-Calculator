#include "main.h"

/* Function to compare two linked lists representing big numbers */
/* Returns 1 if head1 >= head2, 0 otherwise */

int compare_lists(Dll *head1, Dll *head2) {
    Dll *temp1 = head1, *temp2 = head2;

    /* First, compare lengths of the linked lists */
    int len1 = 0, len2 = 0;
    while (temp1) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2) {
        len2++;
        temp2 = temp2->next;
    }
    if (len1 > len2) 
		return 1;
    if (len1 < len2) 
		return 0;

    /* If lengths are equal, compare node by node */
    temp1 = head1;
    temp2 = head2;
    while (temp1 && temp2) {
        if (temp1->data > temp2->data) 
			return 1;
        if (temp1->data < temp2->data) 
			return 0;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 1;
}

/* Function to divide big numbers using repeated subtraction */
int division(Dll **head1, Dll **tail1, Dll **head2, Dll **tail2, Dll **headR, Dll **tailR) {
    int count = 0;

    /* Repeat subtraction until head1 (dividend) becomes smaller than head2 (divisor) */
    while (compare_lists(*head1, *head2)) {
        *headR = NULL;
        *tailR = NULL;
        /* Perform a single subtraction */
		subtraction(head1, tail1, head2, tail2, headR, tailR);
        count++;
        *head1 = *headR; 
        *tail1 = *tailR;
    }
    return count;
}