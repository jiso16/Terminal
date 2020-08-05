#pragma warning ( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <Windows.h>

typedef enum { false, true } bool;
struct _finddata_t fd;

int isFileOrDir()
{
    if (fd.attrib & _A_SUBDIR)
        return 0; // ���丮�� 0 ��ȯ
    else
        return 1; // �׹��� ���� "�����ϴ� ����"�̱⿡ 1 ��ȯ

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

        check = isFileOrDir();    //�������� ���丮 ���� �ĺ�

        if (check == 0 && fd.name[0] != '.')
        {
            printf("������ : %s\n", file_pt);    //���ϸ� ȣ��
        }
        else if (check == 1 && fd.size != 0 && fd.name[0] != '.')
        {
            printf("���ϸ� : %s\n", file_pt);
        }

    }
    _findclose(handle);
}

void initial_ls()
{
    char file_path[_MAX_PATH] = "C:\\dev\\Mini_Terminal";
    FileSearch(file_path);
}

int main()
{
    char command[10];
    char path[100] = { 'a' };
    bool isCommand = true;

    scanf("%s", &command);

    if (strcmp(command, "ls") == 0)
    {
        initial_ls();
        isCommand = true;
    }
    else
    {
        printf("���� ����� �����ϴ�");
        isCommand = false;
    }

    while (isCommand == true)
    {
        scanf("%s", &command);


        if (strcmp(command, "cd") == 0)
        {
            scanf("%s", &path);
            char file_path[_MAX_PATH] = { 'a' };
            strcpy(file_path, path);
        }

        else if (strcmp(command, "ls") == 0)
        {
            char file_path[_MAX_PATH] = { 'a' };
            strcpy(file_path, path);
            FileSearch(file_path);

        }

        else
        {
            printf("���� ����� �����ϴ�");
        }
        printf("\n");
    }
    return 0;

}

