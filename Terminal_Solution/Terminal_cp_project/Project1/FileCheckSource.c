#include "terminal.h"

extern char source[_MAX_PATH], dest[_MAX_PATH];
extern char path2[_MAX_PATH];
extern char file_path[_MAX_PATH];
extern int check;

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