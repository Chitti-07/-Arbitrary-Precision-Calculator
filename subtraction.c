#include "main.h"

/* Function for subtraction */
int subtraction(Dll **head1, Dll **tail1, Dll **head2, Dll **tail2, Dll **headR, Dll **tailR)
{
	
	/* Assigning temp variables */
	Dll* temp1 = *tail1;
	Dll* temp2 = *tail2;
	int barrow = 0;
	int temp;

	/* Iterate until any one of the lists gets empty */
	while (temp1 != NULL && temp2 != NULL) {
		if (temp1->data >= temp2->data) {
			temp = temp1->data - temp2->data - barrow;
			barrow = 0;
		}else {
			temp1->data += 10000;
			temp = temp1->data - temp2->data - barrow;
			barrow = 1;
		}
		temp1 = temp1->prev;
		temp2 = temp2->prev;
		insert_at_first(headR, tailR, temp);
	}

	/* Adding the remaining data to list */
	while (temp1 != NULL) {
		insert_at_first(headR, tailR, temp1->data-barrow);
		barrow = 0;
		temp1 = temp1->prev;
	}
	return SUCCESS;
}