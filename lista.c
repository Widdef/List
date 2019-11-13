#include "lista.h"


void list_add_end(list **p, int value)
{
	list ** marker = p;
	list *new_el = (list*)malloc(sizeof(list));

	while (*marker)
	{
		marker = &(*marker)->next;
	}
	new_el->data = value;
	new_el->next = NULL;
	*marker = new_el;
}

void list_add_start(list **p, int value)
{
	if (p == NULL)
	{
		list *new_el = (list*)malloc(sizeof(list));
		new_el->data = value;
		new_el->next = NULL;
		*p = new_el;
	}
	else
	{
		list *new_el = (list*)malloc(sizeof(list));
		new_el->data = value;
		new_el->next = *p;
		*p = new_el;
	}
}

void list_read(list *p)
{
	printf("\n\n");
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

void list_delete_first(list **p)
{
	if (*p != NULL)
	{
		list *tmp = *p;
		*p = (*p)->next;
		free(tmp);
	}
}

void list_delete_last(list **p)
{
	if (*p != NULL)
	{
		list **marker = p;
		while ((*marker)->next)
		{
			marker = &(*marker)->next;
		}
		list *tmp = *marker;
		(*p)->next = NULL;
		free(tmp);
	}
}

int list_find(list **p, int value)
{
	int flag = 0;
	int index = 0;
	list **marker = p;
	while (*marker != NULL)
	{
		index++;
		if ((*marker)->data == value)
		{
			flag = 1;
			break;
		}
		marker = &(*marker)->next;
	}
	if (flag)
	{
		printf("Element exist. Index: %d\n", index);
		return 1;
	}
	printf("Element not exist\n");
	return 0;
}

void list_find_add_after(list **p, int value, int find)
{
	int flag = 0;
	list **marker = p;
	while (*marker != NULL)
	{
		if ((*marker)->data == find)
		{
			flag = 1;
			break;
		}
		marker = &(*marker)->next;
	}
	if (flag == 1)
	{
		list *new_el = (list*)malloc(sizeof(list));
		new_el->data = value;
		new_el->next = (*marker)->next;
		(*marker)->next = new_el;
	}
	else
	{
		char dec;
		printf("Element not exist\n");
		do
		{
			printf("Do you want to create element as last element of the list? (Y/N)");
			scanf("%c", &dec);
		} while (dec != 'y' && dec != 'Y' && dec != 'n' && dec != 'N');
		if (dec == 'Y' || dec == 'y')
			list_add_end(p, value);
	}
}

void list_find_add_before(list **p, int value, int find)
{
	int flag = 0;
	list **marker = p;
	while (*marker != NULL)
	{
		if ((*marker)->next->data == find)
		{
			flag = 1;
			break;
		}
		marker = &(*marker)->next;
	}
	if (flag == 1)
	{
		list *new_el = (list*)malloc(sizeof(list));
		new_el->data = value;
		new_el->next = (*marker)->next;
		(*marker)->next = new_el;
	}
	else
	{
		char dec;
		printf("Element not exist\n");
		do
		{
			printf("Do you want to create element as first element of the list? (Y/N)");
			scanf("%c", &dec);
		} while (dec != 'y' && dec != 'Y' && dec != 'n' && dec != 'N');
		if (dec == 'Y' || dec == 'y')
			list_add_start(p, value);
	}
}

void list_find_delete(list **p, int find)
{
	int flag = 0;
	int index = 0;
	list **marker = p;
	while (*marker != NULL)
	{
		index++;
		if ((*marker)->next->data == find)
		{
			flag = 1;
			break;
		}
		marker = &(*marker)->next;
	}
	list *tmp = (*marker)->next;
	(*marker)->next = (*marker)->next->next;
	free(tmp);
}

int check_sting(char *str)
{
	int len = (int)strlen(str);
	if (str[len - 3] == 't' && str[len - 4] == '.' && str[len - 2] == 'x' && str[len] == 't');
		return 1;
	return 0;
}

void list_from_file(list **head)
{
	int value;
	char file[256];
	int i_value;
	int b_val = 0;
	FILE *fptr;
	do {
		printf_s("Podaj nazwe pliku: ");
		scanf("%s", &file);
		value = check_sting(file); //Sprawdza czy plik zostal podany z rozszerzeniem txt TAK - 1 NIE - 0 
		if (value)
		{
			fptr = fopen(file, "r");
			if (fptr == NULL) // Czy uda³o siê otworzyæ plik
			{
				printf("Blad otwarcia pliku.\n");
				system("PAUSE");
				fclose(fptr);
				break;
			}
			do
			{
				i_value = fgetc(fptr);
				if (i_value == 32)
					continue;
				if (i_value == 45)
				{
					b_val = 1;
				}
				if(i_value >= 48)
					if (b_val)
					{
						list_add_end(head, (i_value - 48)*-1); // i_value przechowuje wartosci wg tablicy ascii
						b_val = 0;
					}
					else
						list_add_end(head, i_value - 48);
			} while (i_value != EOF);
			printf("Udalo sie odczytac dane z pliku.\n");
			fclose(fptr);
			system("PAUSE");
			break;
		}
		printf("Podales zly format pliku.\n");
		system("PAUSE");
	} while (!value); // Pêtla nie zakonczy sie do momentu podania pliku z rozszerzeniem txt
}

void list_to_file(list *head)
{
	int value;
	char file[256];
	FILE *fptr;
	do {
		printf_s("Podaj nazwe pliku: ");
		scanf("%s", &file);
		value = check_sting(file); //Sprawdza czy plik zostal podany z rozszerzeniem txt TAK - 1 NIE - 0 
		if (value)
		{
			fptr = fopen(file, "w");
			if (fptr == NULL) // Czy uda³o siê otworzyæ plik
			{
				printf("Blad otwarcia pliku.\n");
				system("PAUSE");
				fclose(fptr);
				break;
			}
			while (head != NULL)
			{
				fprintf(fptr,"%d ", head->data);
				head = head->next;
			}
			printf("Udalo sie zapisac dane do pliku.\n");
			fclose(fptr);
			system("PAUSE");
			break;
		}
		printf("Podales zly format pliku.\n");
		system("PAUSE");
	} while (!value); // Pêtla nie zakonczy sie do momentu podania pliku z rozszerzeniem txt
}

void list_delete_all_found_not_rek(list **p, int value)
{
	while (list_find(p,value))
	{
		list_find_delete(p, value);
	}
}

void list_delete_all_found_rek(list **p, int value)
{
	while (list_find(p, value))
	{

	}
}