#include"mybook.h"

void input(book library[], FILE* pbooks,int& filecount,int real)
{
   
    int index = 0;
    int count = 0;
    int size = sizeof(book);
    

    if (filecount == MAXBKS)
        fputs("The book.dat file is full", stderr);

    else {
        puts("Please add new book titles:");
        puts("Press [enter] at the start of a line to stop.");
        while (filecount < MAXBKS && s_gets(library[filecount].title, MAXTITL) != NULL
            && library[filecount].title[0] != '\0')
        {
            puts("Now enter the author.");
            s_gets(library[filecount].author, MAXAUTL);
            library[filecount].delete_flag = 0;
            puts("Now enter the value.");
            scanf_s("%f", &library[filecount++].value);

            while (getchar() != '\n')
                continue;
            if (filecount < MAXBKS)
                puts("Enter the next title ([enter] at the start of a line to stop).");

        }
        fwrite(&library[index], size, filecount, pbooks);
        /*if (filecount > 0)
        {
            io = fwrite(&library[count], size, filecount - count, pbooks);
            fflush(pbooks);
        }*/
        if (filecount < real)
        {
            for (book as = {} ; count < real - filecount; count++)
            {
                as.delete_flag = 1;
                fwrite(&as, size, 1, pbooks);
            }
        }
        
            
        if(filecount==0)
            puts("No books? Too bad.\n");
    }

}
