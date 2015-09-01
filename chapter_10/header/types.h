/*
 * =====================================================================================
 *
 *       Filename:  types.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月23日 21时30分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

typedef struct {
    int a;
    short b[2];
} Ex2;

typedef struct Ex {
    int a;
    char b[3];
    Ex2 c;
    struct Ex *d;
} Ex;

typedef struct {
	short b;
	int c;
	long int d;
	char a;
} Ex3;

/* practice 2 in chapter 10 */
typedef struct {
    unsigned int area_num;
    unsigned int switch_station;
    unsigned int station_code;
} Telephone_info;

typedef struct {
    char *date;
    char *time;
    Telephone_info *telephone_use;
    Telephone_info *telephone_call;
    Telephone_info *telephone_pay;
} Long_way_call;

typedef struct {
    float manufacturer_seggested_retail_price;
    float actual_selling_price;
    float down_payment;
    float security_deposit;
    float monthly_payment;
    int lease_term;
} Transaction_lease;


typedef struct {
    float manufacturer_seggested_retail_price;
    float actual_selling_price;
    float sales_tax;
    float licensing_fee;
} Transaction_all_pay;

typedef struct {
    float manufacturer_seggested_retail_price;
    float actual_selling_price;
    float sales_tax;
    float licensing_fee;
    float down_payment;
    int loan_duration;
    float interest_rate;
    float monthly_payment;
    char bank_name[21];
} Transaction_credit;

typedef struct {
    char customer_name[21];
    char customer_address[41];
    char model[21];
    enum SALE_TYPE {ALL_PAY, LEASE, CREDIT} sale_type;       /* sale's type */
    union {
        Transaction_all_pay all_pay;
        Transaction_lease lease;
        Transaction_credit credit;
    } transaction;
} Sale;

/* practice 3 in chapter 10 */
typedef struct {
    unsigned int opcode : 16;
} MISC;

typedef struct {
    unsigned int offset : 8;
    unsigned int opcode : 8;
} BRANCH;

typedef struct {
    unsigned int dst_reg : 3;
    unsigned int dst_mode : 3;
    unsigned int opcode : 10;
} SGL_OP;

typedef struct {
    unsigned int dst_reg : 3;
    unsigned int dst_mode : 3;
    unsigned int src_reg : 3;
    unsigned int opcode : 7;
} REG_SRC;

typedef struct {
    unsigned int dst_reg : 3;
    unsigned int dst_mode : 3;
    unsigned int src_reg : 3;
    unsigned int src_mode : 3;
    unsigned int opcode : 4;
} DBL_OP;

typedef struct {
    unsigned int addr : 16;
    MISC misc;
    BRANCH branch;
    SGL_OP sgl_op;
    REG_SRC reg_src;
    DBL_OP dbl_op;
} machine_inst;







