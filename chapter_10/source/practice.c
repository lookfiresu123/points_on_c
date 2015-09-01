/*
 * =====================================================================================
 *
 *       Filename:  practice.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月23日 21时24分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "../header/types.h"

#define DO_PRACTICE_1 0
#define DO_PRACTICE_2 0
#define DO_PRACTICE_3 1

Long_way_call *practice_1 (void) {
    Long_way_call *long_way_call = malloc(sizeof(*long_way_call));

    Telephone_info *telephone_use = malloc(sizeof(*telephone_use));
    Telephone_info *telephone_call = malloc(sizeof(*telephone_call));
    Telephone_info *telephone_pay = malloc(sizeof(*telephone_pay));

    /* initialize telephone_use */
    telephone_use->area_num = 0x1;
    telephone_use->switch_station = 0x10;
    telephone_use->station_code = 0x100;

    /* initialize telephone_call */
    telephone_call->area_num = 0x2;
    telephone_call->switch_station = 0x20;
    telephone_call->station_code = 0x200;

    /* initialize telephone_code */
    telephone_pay->area_num = 0x3;
    telephone_pay->switch_station = 0x30;
    telephone_pay->station_code = 0x300;

    /* initialize long_way_call */
    long_way_call->date = "year = 2015, month = 9, day = 1";
    long_way_call->time = "hour = 13, minute = 45, seconds = 37";
    long_way_call->telephone_use = telephone_use;
    long_way_call->telephone_call = telephone_call;
    long_way_call->telephone_pay = telephone_pay;

    return long_way_call;
}

Sale *practice_2 (void) {
    Sale *sale = malloc(sizeof(*sale));
    strcpy(sale->customer_name, "chensu");
    strcpy(sale->customer_address, "nanjing, china");
    strcpy(sale->model, "BMW");
    sale->sale_type = LEASE;
    return sale;
}

machine_inst practice_3 (void) {
    machine_inst x;
    x.addr = (unsigned short)0x0fff;
    x.misc.opcode = (unsigned short)0x0001;
    return x;
}

void test_practice (void) {
#if DO_PRACTICE_1
    practice_1();
#endif
#if DO_PRACTICE_2
    practice_2();
#endif
#if DO_PRACTICE_3
    practice_3();
#endif
}
