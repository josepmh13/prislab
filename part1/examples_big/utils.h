#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> /* to use getopt(...) */
#include <ctype.h>  /* to use isdigit(...) */
#include <sys/time.h> /* for the 'timeval' struct */

/* Function 'overloading' */

void* sort_nrs(void*, char*, int);/* The second parameter is type of sort:
				     merge, insertion, bubblesort, quicksort
				     The third parameter is int or double (0
				     or 1, respectively)
				  */

/* different types of sorting */

void* quick(void*, int);

void* merge(void*, int);

void* bubble(void*, int);

void* insertion(void*, int);
