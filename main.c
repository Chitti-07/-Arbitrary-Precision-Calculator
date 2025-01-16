#include "main.h"

/* Function to create a node for double linked list */
Dll* createNode(int data) {
    Dll* node = malloc(sizeof(Dll));
    if (node == NULL) {
        return NULL;
    }
    node->prev = NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

/* Function to validate the command line arguments */
int Validate_arg(int argc, char** argv) {
    if (argc < 4) {
        return FAILURE;
    }
    else if (strcmp("+", argv[2]) && strcmp("-", argv[2]) && strcasecmp("x", argv[2]) && strcmp("/", argv[2])) {
        return FAILURE;
    }
    return SUCCESS;
}

/* Function to insert data at first in DLL */
int insert_at_first(Dll** head, Dll** tail, int data) {
    Dll* node = createNode(data);
    if (node == NULL) {
        return FAILURE;
    }
    if (*head == NULL) {
        *head = node;
        *tail = node;
        return SUCCESS;
    }
    node->next = *head;
    (*head)->prev = node;
    *head = node;
    return SUCCESS;
}


/* Function to Print list */
void print_list(Dll *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    printf("Head <-> ");
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d <-> ", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
		    // if (head)
		    //     printf(" ");
	    }
    	printf("Tail\n");
    }
}

/* Main function */
int main(int argc, char** argv) {
    Dll *head1 = NULL, *head2 = NULL, *headR = NULL;
    Dll *tail1 = NULL, *tail2 = NULL, *tailR = NULL;
    char option;
    int result;
    char operator = argv[2][0];

    int validate = Validate_arg(argc, argv);
    if (validate == FAILURE) {
        return 0;
    }
    if (argv[1][0] == '-') {
        insert_data(argv[1]+1, &head1, &tail1);
    }else {
        insert_data(argv[1], &head1, &tail1);
    }
    if (argv[3][0] == '-') {
        insert_data(argv[3]+1, &head2, &tail2);
    }else {
        insert_data(argv[3], &head2, &tail2);
    }
    
    switch (operator)
		{
            
			case '+':
                /* call the function to perform the Addition operation */
                if(argv[1][0] == '-' && argv[3][0] == '-') {
                    if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS) {
                        printf("%s + %s = ", argv[1], argv[3]);
                        (*headR).data *= -1;
                        print_list(headR);
                    }
                }
                else if (argv[1][0] == '-' && argv[3][0] != '-') {
                    if (compare_lists(head1, head2)) {
                        if (subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS) {
                            printf("%s + %s = ", argv[1], argv[3]);
                            (*headR).data *= -1;
                            print_list(headR);
                        }   
                    }else if (subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR) == SUCCESS) {
                        printf("%s + %s = ", argv[1], argv[3]);
                        print_list(headR);
                    }
                }
                else if (argv[3][0] == '-' && argv[1][0] != '-') {
                    if(compare_lists(head1, head2)) {
                        if (subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS) {
                            printf("%s + %s = ", argv[1], argv[3]);
                            print_list(headR);
                        }
                    }else if (subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR) == SUCCESS) {
                        printf("%s + %s = ", argv[1], argv[3]);
                        (*headR).data *= -1;
                        print_list(headR); 
                    }
                }else {
                    if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS) {
                        printf("%s + %s = ", argv[1], argv[3]);
                        print_list(headR);
                    }
                }
				break;
			case '-':	
                /* call the function to perform the Subtraction operation */
                if (argv[1][0] == '-' && argv[3][0] == '-') {
                    if (compare_lists(head1, head2)) {
                        if (subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS) {
                            printf("(%s) - (%s) = ", argv[1], argv[3]);
                            (*headR).data *= -1;
                            print_list(headR);
                        }
                    }else if (subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR) == SUCCESS) {
                        printf("%s - %s = ", argv[1], argv[3]);
                        print_list(headR);
                    }
                }
                else if (argv[1][0] == '-' && argv[3][0] != '-') {
                    if (compare_lists(head1, head2)) {
                        if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS) {
                            printf("(%s) - %s = ", argv[1], argv[3]);
                            (*headR).data *= -1;
                            print_list(headR);
                        }
                    }else if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS) {
                        printf("%s - %s = ", argv[1], argv[3]);
                        (*headR).data *= -1;
                        print_list(headR);
                    }
                }
                else if (argv[3][0] == '-' && argv[1][0] != '-') {
                    if (compare_lists(head1, head2)) {
                        if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS) {
                            printf("(%s) - %s = ", argv[1], argv[3]);
                            print_list(headR);
                        }
                    }else if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS) {
                        printf("%s - %s = ", argv[1], argv[3]);
                        print_list(headR);
                    }
                }else {
                    if (compare_lists(head1, head2)) {
                        if (subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS) {
                            printf("%s - %s = ", argv[1], argv[3]);
                            print_list(headR);
                        }
                    }else {
                        if (subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR) == SUCCESS) {
                            printf("%s - %s = ", argv[1], argv[3]);
                            (*headR).data *= -1;
                            print_list(headR);
                        }
                    }
                }
				break;
			case 'x':
            case 'X':	
				/* call the function to perform the multiplication operation */
                if (argv[1][0] == '-' && argv[3][0] == '-') {
                    if(multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS) {
                        printf("%s * %s = ", argv[1], argv[3]);
                        print_list(headR);
                    }
                }
                else if ((argv[1][0] == '-' && argv[3][0] != '-') || (argv[1][0] != '-' && argv[3][0] == '-')) {
                    if(multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS) {
                        printf("%s * %s = ", argv[1], argv[3]);
                        (*headR).data *= -1;
                        print_list(headR);
                    }
                }
                else {
                    if(multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS) {
                        printf("%s * %s = ", argv[1], argv[3]);
                        print_list(headR);
                    }
                }
				break;
			case '/':	
				/* call the function to perform the division operation */
                if (argv[1][0] == '-' && argv[3][0] == '-') {
                    result = division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                    printf("%s / %s = %d", argv[1], argv[3], result);
                }else if (argv[1][0] == '-' || argv[3][0] == '-') {
                    result = division(&head1, &tail1, &head2, &tail2, &headR, &tailR) * (-1);
                    printf("%s / %s = %d", argv[1], argv[3], result);
                }else {
                    result = division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                    printf("%s / %s = %d", argv[1], argv[3], result);
                }
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
}

/* Function to insert data to the list */
void insert_data(char argv[], Dll** head, Dll** tail) {
   char temp[5];
    for (int i = strlen(argv); i > 0; i-=4) {
        int start = i - 4 >= 0 ? i - 4 : 0;
        int num_digits = i - start;

        strncpy(temp, argv + start, num_digits);
        temp[num_digits] = 0;
        insert_at_first(head, tail, atoi(temp));
    } 
}