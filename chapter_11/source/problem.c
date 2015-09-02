/*
 * =====================================================================================
 *
 *       Filename:  problem.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月01日 21时40分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <assert.h>
#include "../header/problem.h"

#define DO_PROBLEM_1 0
#define DO_PROBLEM_2 0
#define DO_PROBLEM_3 0
#define DO_PROBLEM_4 0
#define DO_PROBLEM_5 0
#define DO_PROBLEM_6 0
#define DO_PROBLEM_7 1

#define ORDER_INCREMENT 1
#define ORDER_DECREMENT 0

void problem_1 (void) {
    int *new_memory = MALLOC(25, int);
    assert(new_memory);
}

void *alloc (size_t size) {
/* cancel the last define of malloc */
#ifdef malloc
#undef malloc
#endif
    void *new_memory = malloc(size);
    assert(new_memory);
    return new_memory;
}

void problem_2 (void) {
    size_t size = 25;
    int *new_memory = alloc(size);
}

MEM *ALLOC (size_t size) {
#ifdef malloc
#undef malloc
#endif
    MEM *ptr = malloc (sizeof(*ptr));
    ptr->ref_count = 1;
    ptr->ptr_mem = malloc (size * sizeof(*ptr->ptr_mem));   // it is a gcc extension that sizeof(void) = 1
    return ptr;
}

void USE_MEM (MEM *ptr) {
    assert(ptr && ptr->ref_count > 0 && ptr->ptr_mem);
    ptr->ref_count ++;
}

void UNUSE_MEM (MEM *ptr) {
    if (ptr && ptr->ref_count > 0 && ptr->ptr_mem) {
    	ptr->ref_count --;
        if (ptr->ref_count == 0) {
        	free(ptr->ptr_mem);		// just change mem_control_block->is_available to 0, point ptr and memory still exist, the value of ptr->ref_count is changed to undefined value
        	free(ptr);		// just change mem_control_block->is_available to 0, point ptr and memory still exist, the value of ptr->ref_count is changed to undefined value
    	}
    }
    else
    	exit(1);
}

void problem_3 (void) {
#ifdef malloc
#undef malloc
#endif
	size_t size = 10;
    MEM *ptr = ALLOC(size);
    assert(ptr && ptr->ref_count > 0 && ptr->ptr_mem);
    USE_MEM(ptr);
    UNUSE_MEM(ptr);
    UNUSE_MEM(ptr);
    UNUSE_MEM(ptr);		// the ptr can be still accessed because the point ptr and memory still exist. however the value of *ptr is changed
}

/* this function is called by function qsort to compare between two integer values */
int compare_integers (void const *a, void const *b) {
	register int const *pa = a;
	register int const *pb = b;

	int order = ORDER_DECREMENT;

	if (order == ORDER_INCREMENT)
		return *pa > *pb ? 1 : *pa < *pb ? -1 : 0;
	else if (order == ORDER_DECREMENT)
		return *pa > *pb ? -1 : *pa < *pb ? 1 : 0;
	else
		exit(EXIT_FAILURE);
}

/* sort an array of integers */
int problem_4 (void) {
	int *array;
    int n_values;
    int i;

    /* conversation the number of values here */
    printf("how many values are there ?\n");
    if (scanf("%d",&n_values) != 1 || n_values <= 0) {
        printf("illegal number of values.\n");
        exit(EXIT_FAILURE);
    }

    /* malloc memory to store these values */
#ifdef malloc
#undef malloc
#endif
    array = malloc(n_values * sizeof(*array));
    if (array == NULL) {
        printf("can not get memory for that many values.\n");
        exit(EXIT_FAILURE);
    }

    /* get these values */
    for (i = 0 ; i < n_values ; i += 1) {
        printf("? ");
        if (scanf("%d", array + i) != 1) {
            printf("error reading value #%d\n", i);
            free(array);
            exit(EXIT_FAILURE);
        }
    }

    printf("\n");

    /* qsort these values */
    qsort(array, n_values, sizeof(*array), compare_integers);

    /* print these values */
    for (i = 0 ; i < n_values ; i++)
        printf("%d ", array[i]);

    /* free this momory and exit */
    free(array);
    return EXIT_SUCCESS;
}

/* auto realloc */
void problem_5 (void) {
    /* initialize a buf */
#ifdef malloc
#undef malloc
#endif
    size_t init_size = 10;
    size_t current_size = init_size;
    char *buf = malloc(init_size * sizeof(*buf));

    /* input some characters to buf */
    char ch;
    int i = 0;
    while((ch = getchar()) != '\n') {
        buf[i++] = ch;
        if (i == current_size) {
            current_size *= 2;
            realloc(buf, current_size);
        }
    }
}

/* strcpy to an auto-alloc memory */
char *strdup (char const *string) {
#ifdef malloc
#undef malloc
#endif
    char *new_string;
    assert(sizeof(*new_string) == sizeof(*string));
    new_string = malloc((strlen(string) + 1) * sizeof(*new_string));
    assert(new_string);
    strcpy(new_string, string);
    return new_string;
}

char *problem_6 (void) {
    char const *src_string = "hello world";
    char *copy_string = strdup(src_string);
    return copy_string;
}

Invrec *create_subassy_record (int n_parts) {
    Invrec *new_rec;

    /* try to alloc memory for new_rec */
    new_rec = malloc(sizeof(*new_rec));
    if (new_rec != NULL) {

        /* alloc success, and store SUBASSYINFO */
        new_rec->info.subassy = malloc(sizeof(Subassyinfo));
        if (new_rec->info.subassy != NULL) {
            new_rec->info.subassy->part = malloc(n_parts * sizeof(struct SUBASSYPART));
            if (new_rec->info.subassy->part != NULL) {
                new_rec->type = SUBASSY;
                new_rec->info.subassy->n_parts = n_parts;
                return new_rec;
            }
        }
    }
    return NULL;
}

void discart_inventory_record (Invrec *record) {
    assert(record);

    /* delete info */
    switch(record->type) {
    case PART:
        free(record->info.part);
    case SUBASSY:
        free(record->info.subassy->part);
        free(record->info.subassy);
    }

    /* delete record */
    free(record);

    /*  another method for free memory */
    // if (record->type == SUBASSY)
    // 	free(record->info.subassy->part);
    // free(record->info.part);	// it does not care what record->info.part point, because "void free(void *ptr)";
    // free(record);
}

void problem_7 (void) {
    int n_parts = 10;
    Invrec *record = create_subassy_record(n_parts);
    discart_inventory_record(record);
}

void test_problem (void) {
#if DO_PROBLEM_1
    problem_1();
#endif
#if DO_PROBLEM_2
    problem_2();
#endif
#if DO_PROBLEM_3
    problem_3();
#endif
#if DO_PROBLEM_4
    problem_4();
#endif
#if DO_PROBLEM_5
    problem_5();
#endif
#if DO_PROBLEM_6
    problem_6();
#endif
#if DO_PROBLEM_7
    problem_7();
#endif
}


