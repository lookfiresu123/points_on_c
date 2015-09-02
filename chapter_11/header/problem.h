/*
 * =====================================================================================
 *
 *       Filename:  problem.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月01日 21时40分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

#define malloc          never call malloc directly
#define MALLOC(num, type)       (type *)alloc((num) * sizeof(type))

typedef struct {
    int ref_count;      // 32-bits integer, equal to int in 32/64-bit system
    void *ptr_mem;          // used to malloc a memory area
} MEM;

/* declaration of storages */
/* structure of information of part */
typedef struct {
    int cost;
    int supplier;
} Partinfo;

/* structure of information of subassy */
typedef struct {
    int n_parts;
    struct SUBASSYPART {
        char partno[10];
        short quan;
    } *part;
} Subassyinfo;

/* structure of records of storage */
typedef struct {
    char partno[10];
    int quan;
    enum {PART, SUBASSY} type;
    union {
        Partinfo *part;
        Subassyinfo *subassy;
    } info;
} Invrec;

void problem_1 (void);

void *alloc (size_t size);
void problem_2 (void);

MEM *ALLOC (size_t size);
void USE_MEM (MEM *ptr);
void UNUSE_MEM (MEM *ptr);
void problem_3 (void);

int compare_integers (void const *a, void const *b);
int problem_4 (void);

void problem_5 (void);

char *strdup (char const *string);
char *problem_6 (void);

Invrec *create_subassy_record (int n_parts);
void discart_inventory_record (Invrec *record);
void problem_7 (void);

void test_problem (void);
