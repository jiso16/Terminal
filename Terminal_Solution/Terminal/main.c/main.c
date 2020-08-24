#include "terminal.h"

void MkDir();
void RmDir();
void LsCheck();


FILE* sfp;
FILE* dfp;
char copy;
char command[10];
char path[100] = " ";
char path2[_MAX_PATH] = "C:";
char path3[_MAX_PATH] = "";
char file_path[_MAX_PATH] = "C:";
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
        /*else if (strcmp(command, "rm") == 0)
        {
            Rm();
        }*/
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


