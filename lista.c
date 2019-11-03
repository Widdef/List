#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct ell
{
	int data;
	struct ell *next;

}list;


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

void list_reverse(list *p)
{
	//list first;
}

void list_read_start(list *p)
{
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

void list_read_end(list p)
{
	
}

int main()
{
	list *head = NULL;
	list_add_end(&head, 3);
	list_add_end(&head, 5);
	list_add_start(&head, 12);
	list_read_start(head);

	system("PAUSE");
	free(head);
	return 0;
}