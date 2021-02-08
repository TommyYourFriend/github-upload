#include<stdio.h>
#include <string.h>
int main(int argc,char** argv)
{

    FILE *ptr;
    int ch, character_count,word_count = 0;
    ptr = fopen(argv[1],"r");//Opens the file in read mode,if file doesn't exist function returns NULL.
    if(ptr == NULL)
        printf("Failed to open the file.\n");
    else
    {
        //printf("starting");
        ch=fgetc(ptr);//get the first character in the file


        while(ch!=EOF)
        {




           if(ch=='/')
            {
                ch = fgetc(ptr);
                if(ch=='/')//line comment is detected
                {
                    character_count++;
                    ch=fgetc(ptr);
                    if(ch != '\n' && ch != ' '){
                        word_count++;
                    }
                    else
                        ch = fgetc(ptr);

                    while(ch!='\n')
                    {
                        if(ch == ' '){
                            word_count++;
                        }
                        ch = fgetc(ptr);
                    }
                }
                else {

                    if (ch == '*')//comment block is detected
                    {
                        ch = fgetc(ptr);

                        if (ch != '\n' && ch != ' ')
                            word_count++;


                        //keep going until you find the end astrik
                        while (ch != '*') {
                            character_count++;
                            if (ch == ' ' || ch == '\n') {

                                word_count++;
                            }
                            ch = fgetc(ptr);

                        }
                        ch = fgetc(ptr);

                    }
                }
            }


        ch = fgetc(ptr);
        }
        printf("Number of characters are %d.\n",character_count);
        printf("Number of words are %d.\n",word_count);
    }
    return 0;
}

