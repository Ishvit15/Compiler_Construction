/* 
GROUP NO. 19
ID: 2019B3A70545P  Name: ANIMESH BHARGAVA 
ID: 2019B5A70226P  Name: ISHVIT BHASIN 
ID: 2019B2A70878P  Name: RITIK THAKUR 
ID: 2019B3A70154P  Name: SAHIL GUPTA
ID: 2019B4A70704P  Name: UTKARSH YASHVARDHAN
*/

#include "driver.h"
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "hashtable.h"
#include "parseDef.h"
#include<time.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("!!!!!!!Please check the command!!!!!!!");
        exit(1);
    }
    FILE *fp = fopen(argv[1], "r");
    int len = atoi(argv[2]);
    clock_t startTime, endTime;
    double totalCPUtime, inSec;
    // printf("1\n");
    fillEnumToNonTerminal(fp);
    fillEnumToTerminal(fp);
    // printf("1\n");
    // for(int i = 0; i < TERMINALS_COUNT; i++)
    //      printf("%s\n", enumToTerminal[i]);
    //printf("1\n");
    //printf("1\n");
    


    // int rno;
    // printf("Enter rule number\n"); 
    // scanf("%d", &rno);
    // rhsOfGrammarRuleNode *n = rules[rno];
    // while (n != NULL)
    // {
    //     if (n->symbol.isTerminal)
    //         printf("%s\t", enumToTerminal[n->symbol.tno]);
    //     else
    //         printf("%s\t", enumToNonTerminal[n->symbol.ntno]);
    //     n = n->next;
    // }
    // printf("\n");

    // driver as per ma'am instructions

    printf("------------------------------IMPLEMENTATION STATUS----------------------------------\n");
    printf(" \n");
    while(1)
    {
        int menu =0;
        printf("--------------------------------------------------------MENU--------------------------------------------------------\n");
        printf(" 0. EXIT. \n" 
               " 1. To see your source code without COMMENTS.\n"
               " 2. Print the token list generated by the Lexer along with lexical errors (if any).\n"
               " 3. Verify the syntatic correctness of the source code and print the parse tree for it.\n"
               " 4. Print the total time taken by Lexer and Parser while verifying the sytantic correctness.\n");
        printf("PLEASE ENTER YOUR CHOICE: %d", menu);

        switch (menu)
        {
        case 0:
            exit(0);
            break;
        case 1: 
            char *newFile = "cleanFile.txt";
            removeComment(argv[1], newFile);
            printf("New file has been created (named cleanFile) after removing the comments from given file.\n");
            break;
        case 2:
            initLex(fp, len);
            getStream();
            break;
        case 3:
            initLex(fp, len);
            initParser();
            //populateGrammar();
            // ////////need to add the parse tree print and stuff (UTKARSH's WORK)/////////
//             int me=1;
//             while(me!=0)
//             {
//                 printf("Enter your choics to print : \n1. FIRST Set. \n2. FOLLOW SET \n0.EXIT \n");
//                 scanf("%d", &me);
//                 if(me == 1)
//                 {  // PRINT FIRST SET 
//                     continue;
//                 }
//                 else if(me==2)
//                 {// PRINT FOLLOW SET
//                     continue;
//                 }
//                 else if( me==0)
//                     continue;
//                 else
//                     printf("Enter valid argument.");
//             }
            break;
        case 4:
            startTime = clock();
            fillEnumToNonTerminal(fp);
            fillEnumToTerminal(fp);
            initLex(fp, len);
            getStream();
            populateGrammar();
            // NEED TO ADD ALL THE LEXER AND PARSER FUNCTIONANILTY

            endTime = clock();
            totalCPUtime = (double)(endTime - startTime);
            inSec = totalCPUtime / CLOCKS_PER_SEC;
            printf("Total time taken by CPU %ld", totalCPUtime,
            "\n Total time taken by CPU in Seconds %ld", inSec);
            break;
        default:
            printf("!!!!!!! PLEASE ENTER VALID INPUT !!!!!!!\n");
            break;
        }
    }
    fclose(fp);
}
