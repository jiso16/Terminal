#include "terminal.h"

char path[100];
extern char file_path[_MAX_PATH];
extern int check;
extern int len;

void RmBackslash()
{
    char originDir[100] = "";
    char* ptr = strrchr(file_path, '\\');
    len = strlen(file_path) - strlen(ptr);
    for (int i = 0; i < len; i++)
    {
        originDir[i] = file_path[i];
    }
    strcpy(file_path, originDir);
}

void RmFuntion()
{
    scanf("%s", &path);

    strcat(file_path, "\\");
    strcat(file_path, path);

    check = FileCheck(file_path);
    if (check == 3) //�������� ���� ������ ��� �߸� �� ��� ����
    {
        RmBackslash();
        printf("\n");
    }
    else // �����ϴ� ������ ��� ���� �˻����
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

            check = isFileOrDir();    //�������� ���丮 ���� �ĺ�

            if (check == 0 && fd.name[0] != '.')
            {
                //������ ȣ��
                printf("%s\n", fd.name);
            }
            else if (check == 1 && fd.size != 0 && fd.name[0] != '.')
            {
                //���ϸ� ȣ��

                RmBackslash();
                strcat(file_path, "\\");
                strcat(file_path, fd.name);

                //char strPath = file_path;
                int Result = remove(file_path);

                if (Result == 0)
                {
                    printf("\n");
                }
                else if (Result == -1)
                {
                    printf("\n");
                }

            }
        }
        _findclose(handle);
    }
    RmBackslash();

    int pResult = _rmdir(file_path);

    if (pResult == 0)
    {
        RmBackslash();
    }
    else if (pResult == -1)
    {
        printf("\n");
    }
}