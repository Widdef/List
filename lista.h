#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct ell
{
	int data;
	struct ell *next;
}list;
void list_add_end(list**,int);
void list_add_start(list**,int);
void list_reverse(list*);
void list_read(list*);
void list_delete_first(list**);
void list_delet_last(list**);
void list_find(list**,int);