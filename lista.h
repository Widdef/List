#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ell
{
	int data;
	struct ell *next;
}list;
void list_add_end(list**, int);
void list_add_start(list**, int);
void list_read(list*);
void list_delete_first(list**);
void list_delete_last(list**);
int list_find(list**, int);
void list_find_add_after(list**, int, int);
void list_find_add_before(list**, int, int);
void list_find_delete(list**, int);
void list_from_file(list **);
int check_sting(char *);
void list_to_file(list *);
void list_delete_all_found_not_rek(list **,int);
void list_delete_all_found_rek(list **,int);