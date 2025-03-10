#include"mybook.h"

void print(book library[], int& filecount, FILE* pbooks,int real)
{

    int count = 0;
    int size = sizeof(book);

    if (filecount == 0)
        printf_s("No books.Too bad.\n");
    else {
        while ((fread(&library[count], size, 1, pbooks) == 1))
        {
            if (count == 0)
                puts("Current contents of books,dat:");
            if (library[count].delete_flag != 1) {
                printf_s("%s by %s: $%.2f\n", library[count].title,
                    library[count].author, library[count].value);
            }
            count++;
        }
    }
    printf_s("\n");
}