#include "terminal.h"

extern char source[_MAX_PATH], dest[_MAX_PATH];
extern char path2[_MAX_PATH];
extern char file_path[_MAX_PATH];
extern int check;

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

int FileCheck(file_path)
{
    intptr_t handle;
    char file_path2[_MAX_PATH];

    strcpy(file_path2, file_path);

    if ((handle = _findfirst(file_path, &fd)) == -1)
    {
        return 3;
    }
}