#define _CRT_SECURE_NO_WARNINGS    // strcat ���� ���� ���� ������ ���� ����

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
        return 0; // ���丮�� 0 ��ȯ
    else
        return 1; // �׹��� ���� "�����ϴ� ����"�̱⿡ 1 ��ȯ

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
        //printf("No such file or directory\n");
        return 3;
    }

    while (_findnext(handle, &fd) == 0)
    {
        char file_pt[_MAX_PATH];
        strcpy(file_pt, file_path2);

        check = isFileOrDir();    //�������� ���丮 ���� �ĺ�

        if (check == 0 && fd.name[0] != '.')
        {
            printf("������ : %s\n", fd.name);    //���ϸ� ȣ��
        }
        else if (check == 1 && fd.size != 0 && fd.name[0] != '.')
        {
            printf("���ϸ� : %s\n", fd.name);
        }

    }
    _findclose(handle);
}

int File_check(file_path)
{
    intptr_t handle;
    char file_path2[_MAX_PATH];

    //strcat(file_path, "\\");
    strcpy(file_path2, file_path);
    //strcat(file_path, "*");

    if ((handle = _findfirst(file_path, &fd)) == -1)
    {
        //printf("No such file or directory\n");
        return 3;
    }
}

int main()
{
    char command[10];
    char path[100]=" ";
    char path2[_MAX_PATH] = "C:\\dev\\Terminal";
    char path3[_MAX_PATH] = "C:\\dev\\Terminal";
    char file_path[_MAX_PATH] = "C:\\dev\\Terminal";
    char upperDir[100] = "";
    int check = 0;
    int len = 0;

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
            printf("path:%s", file_path);

            check = File_check(file_path);
            if (check == 3)
            {
                printf("\nno file");
                strcpy(file_path, path3);
                strcpy(path2, file_path);
            }
            else
            {
                strcpy(path3, file_path);
            }

        }

        else if (strcmp(command, "ls") == 0)
        {
            FileSearch(file_path);
            //strcpy(file_path, path3);

        }
        else if (strcmp(command, "..") == 0)
        {
            char* ptr = strrchr(path2, '\\');
            len = strlen(path2) - strlen(ptr);
            for (int i = 0; i < len; i++)
            {
                upperDir[i] = path2[i];
            }
            strcpy(file_path, upperDir);
            strcpy(path2, upperDir);
            printf("path: %s", upperDir);
            printf("path2: %s", path2);
        }

        printf("\n");
    }
    return 0;

}