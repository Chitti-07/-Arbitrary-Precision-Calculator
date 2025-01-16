#include "main.h"

/* Function for Addition */
int addition(Dll **head1, Dll **tail1, Dll **head2, Dll **tail2, Dll **headR, Dll **tailR)
{
	/* Assigning temp variables to tails */
	Dll* temp1 = *tail1;
	Dll* temp2 = *tail2;
	int carry = 0;
	int check;

	/* iterate until any one of the lists get empty */
	while (temp1 != NULL && temp2 != NULL) {
		int temp = (temp1->data + carry) + temp2->data;
		if ((check = Digits(temp)) > 4) {
			carry = temp / 10000;
			temp %= 10000;
		}else {
			carry = 0;
		}
		temp1 = temp1->prev;
		temp2 = temp2->prev;
		insert_at_first(headR, tailR, temp);
	}

	/* Adding the remaining data */
	while (temp1 != NULL) {
		int temp = temp1->data + carry;
		if ((check = Digits(temp)) > 4) {
			carry = temp / 10000;
			temp %= 10000;
		}else {
			carry = 0;
		}
		insert_at_first(headR, tailR, temp);
		temp1 = temp1->prev;
	}

	/* Adding the remaining */
	while (temp2 != NULL) {
		int temp = temp2->data + carry;
		if ((check = Digits(temp)) > 4) {
			carry = temp / 10000;
			temp %= 10000;
		}else {
			carry = 0;
		}
		insert_at_first(headR, tailR, temp);
		temp2 = temp2->prev;
	}
	return SUCCESS;
}

/* Function to count digits of a number */
int Digits(int num) {
	int count = 0;
	while (num != 0) {
		num /= 10;
		count++;
	}
	return count;
}
