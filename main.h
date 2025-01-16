#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE 1
#define DATA_NOT_FOUND -2
#define LIST_EMPTY -1

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dll;

#endif

int addition(Dll **head1, Dll **tail1, Dll **head2, Dll **tail2, Dll **headR, Dll **tailR);

int subtraction(Dll **head1, Dll **tail1, Dll **head2, Dll **tail2, Dll **headR, Dll **tailR);

int multiplication(Dll **head1, Dll **tail1, Dll **head2, Dll **tail2, Dll **headR, Dll **tailR);

int division(Dll **head1, Dll **tail1, Dll **head2, Dll **tail2, Dll **headR, Dll **tailR);

Dll* createNode(int data);

int Validate_arg(int argc, char** argv);

int insert_at_first(Dll** head, Dll** tail, int data);

void print_list(Dll *head);

int Digits(int num);

void insert_data(char* argv, Dll** head, Dll** tail);

int compare_lists(Dll *head1, Dll *head2);

int get_length(Dll *head);