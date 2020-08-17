#define _CRT_SECURE_NO_WARNINGS    // strcat 보안 경고로 인한 컴파일 에러 방지

#pragma warning ( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <Windows.h>
#include <direct.h>
#include <errno.h>

struct _finddata_t fd;

int isFileOrDir()
{
    if (fd.attrib & _A_SUBDIR)
        return 0; // 디렉토리면 0 반환
    else
        return 1; // 그밖의 경우는 "존재하는 파일"이기에 1 반환

}
int FileSearch(char file_path[])
{
    intptr_t handle;
    int check = 0;
    char file_path2[_MAX_PATH];

    strcat(file_path, "\\");
    strcpy(file_path2, file_path);
    strcat(file_path, "*");

    if ((handle = _findfirst(file_path, &fd)) == -1)
    {
        return 3;
    }

    while (_findnext(handle, &fd) == 0)
    {
        char file_pt[_MAX_PATH];
        strcpy(file_pt, file_path2);

        check = isFileOrDir();    //파일인지 디렉토리 인지 식별

        if (check == 0 && fd.name[0] != '.')
        {
            printf("폴더명 : %s\n", fd.name);    //파일명 호출
        }
        else if (check == 1 && fd.size != 0 && fd.name[0] != '.')
        {
            printf("파일명 : %s\n", fd.name);
        }

    }
    _findclose(handle);
}

int File_check(file_path)
{
    intptr_t handle;
    char file_path2[_MAX_PATH];

    strcpy(file_path2, file_path);

    if ((handle = _findfirst(file_path, &fd)) == -1)
    {
        return 3;
    }
}

int main()
{
    FILE* sfp;
    FILE* dfp;
    char source[_MAX_PATH], dest[_MAX_PATH];
    char copy;
    char command[10];
    char path[100] = " ";
    char path2[_MAX_PATH] = "C:\\dev\\Terminal";
    char path3[_MAX_PATH] = "";
    char file_path[_MAX_PATH] = "C:\\dev\\Terminal";
    char upperDir[100] = "";
    char pathName[20] = "";
    char copyPath[_MAX_PATH] = "";
    int check = 0;
    int check2 = 0;
    int len = 0;
    int len2 = 0;

    scanf("%s", &command);

    if (strcmp(command, "ls") == 0)
    {
        FileSearch(file_path);
        strcpy(file_path, path2);
    }
    else
    {
        main();
        printf("No File\n\n");
    }

    while (1)
    {

        scanf("%s", &command);

        if (strcmp(command, "cd") == 0)
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
            }
            else
            {
                strcat(file_path, "\\");
                strcat(file_path, path);

                check = File_check(file_path);
                if (check == 3)
                {
                    char originDir[100] = "";
                    char* ptr2 = strrchr(file_path, '\\');
                    len2 = strlen(file_path) - strlen(ptr2);
                    for (int i = 0; i < len2; i++)
                    {
                        originDir[i] = file_path[i];
                    }
                    strcpy(file_path, originDir);
                }
                else
                {
                    continue;
                }
            }

        }

        else if (strcmp(command, "ls") == 0)
        {
            FileSearch(file_path);
            char originDir[100] = "";
            char* ptr2 = strrchr(file_path, '\\');

            len2 = strlen(file_path) - strlen(ptr2);
            for (int i = 0; i < len2; i++)
            {
                originDir[i] = file_path[i];
            }
            strcpy(file_path, originDir);
        }
        else if (strcmp(command, "cp") == 0)
        {
            scanf("%s", &pathName);
            
            strcpy(path2, file_path);
            strcat(file_path, "\\");
            strcat(file_path, pathName);
            
            check2 = File_check(file_path);

            if (check2 == 3)
            {
                strcpy(file_path, path2);
                check2 = File_check(pathName);
                
                if (check == 3)
                {
                    continue;
                }
                else
                {
                    scanf("%s", &copyPath);
                    char originDir[100] = "";
                    char* ptr2 = strrchr(copyPath, '\\');
                    len2 = strlen(copyPath) - strlen(ptr2);
                    for (int i = 0; i < len2; i++)
                    {
                        originDir[i] = copyPath[i];
                    }

                    check2 = File_check(originDir);
                    if (check2 == 3)
                    {
                        continue;
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
                char* ptr2 = strrchr(copyPath, '\\');
                len2 = strlen(copyPath) - strlen(ptr2);
                for (int i = 0; i < len2; i++)
                {
                    originDir[i] = copyPath[i];
                }

                check2 = File_check(originDir);
                if (check2 == 3)
                {
                    continue;
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
        }
        printf("\n");
    }
    return 0;
}