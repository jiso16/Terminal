#include "terminal.h"

extern char path[100];
extern char file_path[_MAX_PATH];
extern char upperDir[100];
extern int check;
extern int len;

void CdCheck()
{
    scanf("%s", &path);

    if (strcmp(path, "..") == 0)
    {
        char upperDir[100] = "";
        char* ptr = strrchr(file_path, '\\');
        len = strlen(file_path) - strlen(ptr);
        for (int i = 0; i < len; i++)
        {
            upperDir[i] = file_path[i];
        }
        strcpy(file_path, upperDir);
        printf("\n");
    }
    else
    {
        strcat(file_path, "\\");
        strcat(file_path, path);

        check = FileCheck(file_path);
        if (check == 3)
        {
            char originDir[100] = "";
            char* ptr = strrchr(file_path, '\\');
            len = strlen(file_path) - strlen(ptr);
            for (int i = 0; i < len; i++)
            {
                originDir[i] = file_path[i];
            }
            strcpy(file_path, originDir);
            printf("\n");
        }
        else
        {
            printf("\n");
        }
    }
}