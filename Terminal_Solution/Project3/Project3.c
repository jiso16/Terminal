#define _CRT_SECURE_NO_WARNINGS    // strcat 보안 경고로 인한 컴파일 에러 방지

#pragma warning ( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <Windows.h>

struct _finddata_t fd;

int isFileOrDir()
{
    if (fd.attrib & _A_SUBDIR)
        return 0; // 디렉토리면 0 반환
    else
        return 1; // 그밖의 경우는 "존재하는 파일"이기에 1 반환

}

void FileSearch(char file_path[])
{
    intptr_t handle;
    int check = 0;
    char file_path2[_MAX_PATH];

    strcat(file_path, "\\");
    strcpy(file_path2, file_path);
    strcat(file_path, "*");

    if ((handle = _findfirst(file_path, &fd)) == -1)
    {
        printf("No such file or directory\n");
        return;
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

int main()
{
    char command[10];
    char path[100]=" ";
    char path2[_MAX_PATH] = "C:\\dev\\Terminal";
    char file_path[_MAX_PATH] = "C:\\dev\\Terminal";


    scanf("%s", &command);

    if (strcmp(command, "ls") == 0)
    {
        FileSearch(file_path);
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

            strcat(path2, "\\");
            scanf("%s", &path);
            strcat(path2, path); 
            strcpy(file_path, path2);
        }

        else if (strcmp(command, "ls") == 0)
        {
            FileSearch(file_path);
            strcpy(file_path, path2);

        }

        printf("\n");
    }
    return 0;

}