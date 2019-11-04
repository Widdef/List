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

void list_reverse(list *p)
{
	//list first;
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

void list_find(list **p, int value)
{
	int flag = 0;
	list **marker = p;
	while (marker)
	{
		if ((*marker)->data == value)
		{
			flag = 1;
			break;
		}
		marker = &(*marker)->next;
	}
	if (flag)
		printf("Element exist\n");
	else
		printf("Element not exist");
}