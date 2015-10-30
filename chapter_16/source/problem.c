/*
 * =====================================================================================
 *
 *       Filename:  problem.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/28/2015 04:50:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123
 *        Company:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <setjmp.h>
#include <stdio.h>
#include "../header/problem.h"

#define DO_PROBLEM_1 0
#define DO_PROBLEM_2 0
#define DO_PROBLEM_3 0
#define DO_PROBLEM_4 1

#define TRUE 1
#define FALSE 0
void shuffle (Card **deck, int n_cards) {
    int i;
    static int first_time = TRUE;
    if (first_time) {
        first_time = FALSE;
        srand((unsigned int)time(NULL));
    }
    for (i = n_cards-1 ; i > 0 ; i--) {
        int where;
        Card *temp;
        where = rand() % i;
        temp = deck[where];
        deck[where] = deck[i];
        deck[i] = temp;
    }
}

void get_cards (Card **deck, Player *player, int player_num) {
    int count_per = 26;
    int i, j;
    int sum = 0;
    for (i = 0 ; i < count_per ; i++)
        for (j = 0 ; j < player_num ; j++)
            player[j].card_player[i] = deck[sum++];
}

void set_cards (Player *one_player, char **digit) {
    int count_per = 26;
    int i, j;
    int sum;
    // initialize list
    for (i = 0 ; i < 9 ; i++)
        one_player->list[i] = NULL;
    // set
    for (i = 0 ; i < 13 ; i++) {
        sum = 0;
        for (j = 0 ; j < count_per ; j++) {
            if(digit[i] == one_player->card_player[j]->digit)
                sum++;
        }
        Node *new = (Node *)malloc(sizeof(*new));
        new->digit = digit[i];
        new->next = NULL;
        if (one_player->list[sum] == NULL)
            one_player->list[sum] = new;
        else {
            Node *current = one_player->list[sum];
            while(current->next != NULL)
                current = current->next;
            current->next = new;
        }
    }
}

#define CARD_COUNT 104
int problem_1 (void) {
    jmp_buf restart_problem_1;
    setjmp(restart_problem_1);          // save the current state of registers into restart_problem_1
    Card *deck[CARD_COUNT];
    char *kind[4] = { "红桃", "黑桃", "方块", "梅花" };
    char *digit[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    int i, j, k;
    int sum = 0;
    for (i = 0 ; i < 4 ; i++) {
        for (j = 0 ; j < 13 ; j++) {
            for (k = 0 ; k < 2 ; k++) {
                deck[sum] = (Card *)malloc(sizeof(Card));
                deck[sum]->digit = digit[j];
                deck[sum]->kind = kind[i];
                sum++;
            }
        }
    }
    assert(sum == CARD_COUNT);
//    for (i = 0 ; i < CARD_COUNT ; i++)
//        printf("%s %s\n", deck[i]->kind, deck[i]->digit);
//    printf("------------------\n------------------\n");
    // 洗牌
    shuffle(deck, CARD_COUNT);
//    for (i = 0 ; i < CARD_COUNT ; i++)
//        printf("%s %s\n", deck[i]->kind, deck[i]->digit);
    Player player[4];
    player[0].name = "陈溯";
    player[1].name = "陈叶";
    player[2].name = "赵冠军";
    player[3].name = "吕腾飞";
    int player_num = 4;
    // 发牌
    get_cards(deck, player, player_num);
    // 理牌
    for (i = 0 ; i < player_num ; i++)
        set_cards(&player[i], digit);

    for (i = 0 ; i < player_num ; i++)
        if (player[i].list[5] != NULL)
            longjmp(restart_problem_1, 1);          // 不允许有人有5个相同牌的炸弹

    Node *current = NULL;
    for (i = 0 ; i < player_num ; i++) {
        printf("%s\n", player[i].name);
//        for (j = 0 ; j < 26 ; j++)
//            printf("%s %s\n", deck[j]->kind, deck[j]->digit);
        for (j = 0 ; j < 9 ; j++) {
            printf("%d张牌: { ", j);
            current = player[i].list[j];
            while (current != NULL) {
                printf("%s ", current->digit);
                current = current->next;
            }
            printf("}\n");
        }
        printf("------------------\n");
    }
    for (i = 0 ; i < CARD_COUNT ; i++)
        free(deck[i]);
    Node *del_node;
    for (i = 0 ; i < 4 ; i++) {
        for (j = 0 ; j < 9 ; j++) {
            current = player[i].list[j];
            while (current != NULL) {
                del_node = current;
                current = current->next;
                free(del_node);
            }
        }
    }
    return 0;
}

void problem_2 (void) {
    jmp_buf restart_problem_2;
    setjmp(restart_problem_2);          // save the current state of registers into restart_problem_2
    clock_t temp = clock();         // 从程序开始执行起处理器时钟滴答的次数
    assert(temp != -1);
    double clock = ((double)temp) / CLOCKS_PER_SEC;         // 从程序开始执行起处理器所消耗的时间（毫秒）
    time_t current = time(NULL);            // 获得当前时间
    assert(current != -1);

    char *string_time = ctime(&current);        // 用字符串的形式表现时间
    time_t time1 = time(NULL);
    sleep(2);
    time_t time2 = time(NULL);
    double diff = difftime(time1, time2);       // （time1 - time2）-> double
    struct tm *UTC = gmtime(&current);          // 获得当前格林尼治时间
    struct tm *LTC = localtime(&current);       // 获得当前本地时间
}

int problem_3 (void) {
    char *a = "dns";
    char *ptr_a = getenv(a);
    return 0;
}

int r_compare (void const *a, void const *b) {
    return strcmp( ((Record *)a)->key, ((Record *)b)->key );
}

int problem_4 (void) {
    Record array[50];
    /* fill the array with 50 elements */
    qsort( array, 50, sizeof(Record), r_compare );
    return EXIT_SUCCESS;
}

int test_problem (void) {
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
    return 0;
}
