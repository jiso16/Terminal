#include "terminal.h"

void MkDir();
void RmDir();
void LsCheck();
int Rm(char file_path[]);
void RmFile();


FILE* sfp;
FILE* dfp;
char copy;
char command[10];
char path[100] = " ";
char path2[_MAX_PATH] = "C:\\dev\\Terminal";
char path3[_MAX_PATH] = "";
char file_path[_MAX_PATH] = "C:\\dev\\Terminal";
char upperDir[100] = "";
char pathName[20] = "";
char copyPath[_MAX_PATH] = "";
char mkFolder[_MAX_PATH] = "";
char folderName[20] = "";
char rmFolder[_MAX_PATH] = "";
int check = 0;
int check2 = 0;
int len = 0;

int main()
{
    printf("미니 터미널을 시작합니다.\n");
    printf("현재 디렉토리는 C:입니다.\n\n");

    while (1)
    {
        scanf("%s", &command);

        if (strcmp(command, "cd") == 0)
        {
            CdCheck();
        }
        else if (strcmp(command, "ls") == 0)
        {
            LsCheck();
        }
        else if (strcmp(command, "cp") == 0)
        {
            CpCheck();
        }
        else if (strcmp(command, "mkdir") == 0)
        {
            MkDir();
        }
        else if (strcmp(command, "rmdir") == 0)
        {
            RmDir();
        }
        else if (strcmp(command, "rm") == 0)
        {
            Rm(file_path);
        }
    }
    return 0;
}

void LsCheck()
{
    FileSearch(file_path);
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


void MkDir()
{
    strcpy(mkFolder, file_path);
    scanf("%s", folderName);
    strcat(mkFolder, "//");
    strcat(mkFolder, folderName);

    int nResult = _mkdir(mkFolder);

    if (nResult == 0)
    {
        printf("\n");
    }
    else if (nResult == -1)
    {
        printf("\n");
    }
}

void RmDir()
{
    strcpy(rmFolder, file_path);
    scanf("%s", folderName);
    strcat(rmFolder, "//");
    strcat(rmFolder, folderName);

    int pResult = _rmdir(rmFolder);

    if (pResult == 0)
    {
        printf("\n");
    }
    else if (pResult == -1)
    {
        printf("\n");
    }
}

int Rm(char file_path[])
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
            //파일명 호출
            RmFile();
        }
        else if (check == 1 && fd.size != 0 && fd.name[0] != '.')
        {
            printf("%s\n", fd.name);
        }

    }
    _findclose(handle);
}

void RmFile()
{
    char strPath = file_path;

    int Result = remove(strPath);

    if (Result == 0)
    {
        printf("파일 삭제 성공\n");
    }
    else if (Result == -1)
    {
        perror("파일 삭제 실패\n");
    }
}

