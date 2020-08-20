#include "terminal.h"


extern FILE* sfp;
extern FILE* dfp;
extern char source[_MAX_PATH], dest[_MAX_PATH];
extern char copy;
extern char path2[_MAX_PATH];
extern char file_path[_MAX_PATH];
extern char pathName[20];
extern char copyPath[_MAX_PATH];
extern int check;
extern int check2;
extern int len;

void CpCheck()
{
    scanf("%s", &pathName);

    strcpy(path2, file_path);
    strcat(file_path, "\\");
    strcat(file_path, pathName);

    check2 = FileCheck(file_path);

    if (check2 == 3)
    {
        strcpy(file_path, path2);
        check2 = FileCheck(pathName);

        if (check2 == 3)
        {
            printf("\n");
        }
        else
        {
            scanf("%s", &copyPath);
            char originDir[100] = "";
            char* ptr = strrchr(copyPath, '\\');
            len = strlen(copyPath) - strlen(ptr);
            for (int i = 0; i < len; i++)
            {
                originDir[i] = copyPath[i];
            }

            check2 = FileCheck(originDir);
            if (check2 == 3)
            {
                printf("\n");
            }
            else
            {
                sfp = fopen(pathName, "r");
                dfp = fopen(copyPath, "w");

                while (!feof(sfp))
                {
                    copy = fgetc(sfp);
                    fputc(copy, dfp);
                }

                fclose(sfp);
                fclose(dfp);
            }
        }
    }
    else
    {
        scanf("%s", &copyPath);
        char originDir[100] = "";
        char* ptr = strrchr(copyPath, '\\');
        len = strlen(copyPath) - strlen(ptr);
        for (int i = 0; i < len; i++)
        {
            originDir[i] = copyPath[i];
        }

        check2 = FileCheck(originDir);
        if (check2 == 3)
        {
            printf("\n");
        }
        else
        {
            sfp = fopen(file_path, "r");
            dfp = fopen(copyPath, "w");

            while (!feof(sfp))
            {
                copy = fgetc(sfp);
                fputc(copy, dfp);
            }

            fclose(sfp);
            fclose(dfp);
        }
        strcpy(file_path, path2);
    }
    printf("\n");
}