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
        strcat(file_pt, fd.name);

        check = isFileOrDir();    //파일인지 디렉토리 인지 식별

        if (check == 0 && fd.name[0] != '.')
        {
            printf("폴더명 : %s\n", file_pt);    //파일명 호출
        }
        else if (check == 1 && fd.size != 0 && fd.name[0] != '.')
        {
            printf("파일명 : %s\n", file_pt);
        }

    }
    _findclose(handle);
}

void initial_ls()
{
    char file_path[_MAX_PATH] = "C:\\dev\\Terminal";
    FileSearch(file_path);
}

int main()
{
    char command[10];
    char path[100] = { 'a' };
    char path2[100] = { 'a' };


    scanf("%s", &command);

    if (strcmp(command, "ls") == 0)
    {
        initial_ls();
    }
    else
    {
        main();
    }

    while (1)
    {
        scanf("%s", &command);


        if (strcmp(command, "cd") == 0)
        { 
            scanf("%s", &path);

            printf("1: %s\n", path2);
        if (strcmp(path, "..") == 0)
            {
            printf("들어왔딷");
            printf("2: %s\n", path2);
            }
            char file_path[_MAX_PATH] = { 'a' };
            strcpy(file_path, path);
            strcpy(path2,file_path );

            printf("3: %s\n", path2);
            // path2에 path랑 동일한 값 저장
        }

        else if (strcmp(command, "ls") == 0)
        {

            char file_path[_MAX_PATH] = { 'a' };
            strcpy(file_path, path);
            FileSearch(file_path);
          
            printf("4: %s\n", path2);
        }
     

        printf("\n");
    }
    return 0;

}

