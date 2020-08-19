#pragma once

#define _CRT_SECURE_NO_WARNINGS    // strcat 보안 경고로 인한 컴파일 에러 방지

#pragma warning ( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <Windows.h>
#include <direct.h>
#include <errno.h>


extern int isFileOrDir();
extern int FileSearch(char file_path[]);
extern int FileCheck(file_path);
extern void MkDir();
extern void RmDir();
extern void CdCheck();
extern void CpCheck();
extern void LsCheck();

struct _finddata_t fd;

FILE* sfp;
FILE* dfp;
extern char source[_MAX_PATH], dest[_MAX_PATH];
extern char copy;
extern char command[10];
extern char path[100] = " ";
extern char path2[_MAX_PATH] = "C:\\dev\\Terminal";
extern char path3[_MAX_PATH] = "";
extern char file_path[_MAX_PATH] = "C:\\dev\\Terminal";
extern char upperDir[100] = "";
extern char pathName[20] = "";
extern char copyPath[_MAX_PATH] = "";
extern char mkFolder[_MAX_PATH] = "";
extern char folderName[20] = "";
extern char rmFolder[_MAX_PATH] = "";
extern int check = 0;
extern int check2 = 0;
extern int len = 0;
