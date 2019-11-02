#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct ell
{
	int data;
	struct ell *next;

}el_list;
typedef el_list *list;

void list_add_end(list *p, int value)
{
	if (p == NULL)
	{
		list new_el = malloc(sizeof(list));
		new_el->data = value;
		new_el->next = NULL;
		p->next = &new_el;
	}else
		list_add_end((*p)->next, value);
}
list list_add_start(list *p, int value)
{
	if (p == NULL)
	{
		list new_el = malloc(sizeof(list));
		new_el->data = value;
		new_el->next = NULL;
		return new_el;
	}
	else
	{
		list new_el = malloc(sizeof(list));
		new_el->data = value;
		new_el->next = p;
		return new_el;
	}
}

void list_reverse(list *p)
{
	list first;
}

void list_read_start(list p)
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
	list number = NULL;
	list_add_end(number, 3);
	list_add_end(number, 5);
	list_add_start(number, 12);
	list_read_start(number);

	system("PAUSE");
	free(number);
	return 0;
}