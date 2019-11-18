#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "lista.h"


void ask_value(int *value)
{
	printf("\nPodaj wartosc do dodania: ");
	scanf("%d", value);
}
void find_value(int *value)
{
	printf("\nPodaj wartosc do wyszukania: ");
	scanf("%d", value);
}


int main()
{
	list *head = NULL;
	int chose = 0;
	int value;
	int find;
	int test;
	do
	{
		system("CLS");
		printf("1)Dodaj element na poczatku listy\n");
		printf("2)Dodaj element na koncu listy\n");
		printf("3)Usun pierwszy element listy\n");
		printf("4)Usun ostatni element listy\n");
		printf("5)Odszukaj zadany element\n");
		printf("6)Dodaj nowy element przed lub za wskazanym\n");
		printf("7)Usun wskazany element\n");
		printf("8)Wczytaj zawartosc listy z pliku\n");
		printf("9)Zapisz zawartosc listy z pliku\n");
		printf("10)Wyswietl zawartosc listy\n");
		printf("11)Usun wszystkie wystapienia elementu\n");
		printf("12)Wyznacz wartosc najczestsza\n");
		printf("13)\n");
		printf("14)Odwracanie listy\n");
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
			find_value(&find);
			list_find(&head, find);
			system("PAUSE");
			continue;
		case 6:
			do
			{
				system("CLS");
				printf("1) Add before\n");
				printf("2) Add after\n");
				scanf("\n%d", &chose);
				switch (chose)
				{
				case 1:
					find_value(&find);
					ask_value(&value);
					list_find_add_before(&head, value, find);
					continue;
				case 2:
					find_value(&find);
					ask_value(&value);
					list_find_add_after(&head, value, find);
					continue;
				default:
					continue;
				}
			} while (chose != 1 && chose != 2);
			continue;
		case 7:
			find_value(&find);
			list_find_delete(&head, find);
			continue;
		case 8:
			list_from_file(&head);
			continue;
		case 9:
			list_to_file(head);
			continue;
		case 10:
			list_read(head);
			system("PAUSE");
			continue;
		case 11:
			do
			{
				system("CLS");
				printf("1) Rekurencyjnie\n2) Nierekurencyjnie\n");
				scanf("\n%d", &chose);
				switch (chose)
				{
				case 1:
					find_value(&find);
					list_delete_all_found_rek(&head, find);
					continue;
				case 2:
					find_value(&find);
					list_delete_all_found_not_rek(&head, find);
					continue;
				default:
					continue;
				}
			} while (chose != 1 && chose != 2);
			continue;
		case 12:
			printf("Najczesciej wystepujaca wartosc to: %d\n",list_value_most_common(&head));
			system("PAUSE");
			//list_value_most_common(&head);
			continue;
		case 14:
			do
			{
				system("CLS");
				printf("1) Rekurencyjnie\n2) Nierekurencyjnie\n");
				scanf("\n%d", &chose);
				switch (chose)
				{
				case 1:
					list_reverse_rek(&head);
					continue;
				case 2:
					list_reverse(&head);
					continue;
				default:
					continue;
				}
			} while (chose != 1 && chose != 2);
			continue;
		default:
			continue;
		}
	} while (chose != 0);

	free(head);
	return 0;
}