/*
 * =====================================================================================
 *
 *       Filename:  problem.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/28/2015 04:51:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123
 *        Company:
 *
 * =====================================================================================
 */
#ifndef _PROBLEM_H
#define _PROBLEM_H 1
    //#include <time.h>
    typedef struct CARD Card;
    typedef struct PLAYER Player;
    typedef struct NODE Node;

    struct CARD {
        char *digit;
        char *kind;
    };

    struct PLAYER {
        char *name;
        Card *card_player[26];
        Node *list[9];      // 0~8
    };

    struct NODE {
        char *digit;
        struct NODE *next;
    };

    void shuffle (Card **deck, int n_cards);
    void get_cards (Card **deck, Player *player, int player_num);
    void set_cards (Player *one_player, char **digit);
    int problem_1 (void);

    void problem_2 (void);

    int problem_3 (void);

    int test_problem (void);
#endif

