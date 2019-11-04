#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "lista.h"


void ask_value(int *value)
{
	printf("\nPodaj wartosc do dodania: ");
	scanf("%d", value);
}


int main()
{
	list *head = NULL;
	int chose = 0;
	int value;
	do
	{
		system("CLS");
		printf("1)Dodaj element na poczatku listy\n");
		printf("2)Dodaj element na koncu listy\n");
		printf("3)Usun pierwszy element listy\n");
		printf("4)Usun ostatni element listy\n");
		printf("5)Odszukaj zadany element\n");
		printf("6)dodaj element na poczatku listy\n");
		printf("7)dodaj element na poczatku listy\n");
		printf("8)dodaj element na poczatku listy\n");
		printf("9)dodaj element na poczatku listy\n");
		printf("10)wyswietl zawartosc listy\n");
		printf("0)Wyjscie\n");
		scanf("%d", &chose);
		switch (chose)
		{
		case 1:
			ask_value(&value);
			list_add_start(&head, value);
			continue;
		case 2:
			ask_value(&value);
			list_add_end(&head, value);
			continue;
		case 3:
			list_delete_first(&head);
			continue;
		case 4:
			list_delete_last(&head);
			continue;
		case 5:
			ask_value(&value);
			list_find(&head, value);
			system("PAUSE");
			continue;
		case 10:
			list_read(head);
			system("PAUSE");
			continue;
		default:
			continue;
		}
	} while (chose != 0);

	free(head);
	return 0;
}