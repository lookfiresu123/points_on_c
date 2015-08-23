/*
 * =====================================================================================
 *
 *       Filename:  practice.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月19日 16时07分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lookfiresu123 (chensu), lookfiresu123@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

void practice_1 (void);
void test_practice (void);

size_t my_strlen (char *str, unsigned int size);
void practice_2 (void);

char *my_strcpy (char *dest, char *src, unsigned int size);
void practice_3 (void);

char *my_strcat (char *dest, char *src, unsigned int size);
void practice_4 (void);

void my_strncat (char *dest, char *src, int dest_len);
void practice_5 (void);

char *my_strcpy_end(char *dest, char *src);
void practice_6 (void);

char *my_strrchr (char const *str, int ch);
void practice_7 (void);

char *my_strnchr (char const *str, int ch, int which);
void practice_8 (void);

char *count_chars (char const *str, char const *chars);
void practice_9 (void);

int palindrome (char *string);
void practice_10 (void);

int practice_11 (void);

int prepare_key (char *key);
void practice_12 (void);

void encrypt (char *data, char const *key);
void practice_13 (void);

void decrypt (char *data, char const *key);
void practice_14 (void);

void dollars (char *dest, char const *src);
void practice_14 (void);
