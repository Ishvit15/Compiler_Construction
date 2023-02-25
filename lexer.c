#include<stdio.h>
#include<stdlib.h>
#include<string.h>

removeComment(char *testcaseFile, char *cleanFile)
{
    FILE *fp = fopen(testcaseFile,"r");
    FILE *fpt = fopen(cleanFile, "w");
    if(fpt == NULL)
        printf("Error");
    
    if(fp==NULL)
    {
        printf("File cannot be openned.");
        exit(1);
    }
    else
        printf("File openned"); 
    // checked if the files are openned or not

    char *c ="**";
    char ch = getChar(fp);
    char ch1 = getChar(fp); // taking first 2 char of the file
    while (ch1!=EOF)
    {
        if(strcmp(*c , strcat(ch,ch1))) // comparing for the start of the comment 
        {
            fscanf(fp, "%c", ch);
            fscanf(fp, "%c", ch1);
            while(!strcmp(*c , strcat(ch,ch1))) // lookinig for the end of comment
            {
                fprintf(fpt,"%c",'\n'); // keeping line no the same as original code
            }
        }
        else
        {
            fprintf(fpt, "%c", ch); // copying to cleanFile
        }
    }
    fclose(fp);
    fclose(fpt);

}
