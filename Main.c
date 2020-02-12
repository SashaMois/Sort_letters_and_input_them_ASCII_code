/*
 * Main.c
 *
 * It sorts the input letters by his ASCII code and outputs it from 
 * the smallest to the largest letters codes with his ASCII code.
 *
 *  Created to; 8 February 2020 y.
 *      Author: SashaMois
 */

#include <stdio.h>

#define MAXLINE 100000 /* max count of input letters */
#define CODES 255 /* codes in ASCII */
#define NO -1

int check_entry_in_control_characters(int symbol_for_check);

int main()
{
    int c; /* saves input letter */
    int i; /* count */
    int status_for_cont_ch = 1; /* status for check: is it a control character? */
    char letters[MAXLINE]; /* array for save inputed letters */

    /* start input characters */
    for (i = 0; (c = getchar()) != EOF; ++i) 
        letters[i] = c;

    /* description of input information */
    printf("\nLetter:   ASCII code:\n");

    /* start sorting inputed letters */
    for (i = 0; i <= CODES; ++i) 
        for (int i2 = 0; i2 < MAXLINE; ++i2) 
            if (i == letters[i2]) {
                if (i == ' ')
                    printf("    ' ' - %10d\n", i);
                else if ((status_for_cont_ch = check_entry_in_control_characters(i)) == NO)
                    printf("    %c   - %10d\n", letters[i2], i);
                else
                    printf("    \\%c  - %10d\n", status_for_cont_ch, i);
            }
                
    return 0;
}

check_entry_in_control_characters(int symbol)
{
    char control_characters[] = "\a\b\f\n\r\t\v\0"; /* array of control characters */
    char letters_of_control_characters[] = "abfnrtv0"; /* array of letters of control characters */
    const int border = 12; /* border of 'control_characters' array */

    for (int i = 0; i < border; ++i)
        if (symbol == control_characters[i])
            return letters_of_control_characters[i];
    
    return NO;
}