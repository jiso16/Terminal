#pragma once

#define _CRT_SECURE_NO_WARNINGS    // strcat ���� ���� ���� ������ ���� ����

#pragma warning ( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <Windows.h>
#include <direct.h>
#include <errno.h>
#include "terminal.h"

struct _finddata_t fd;

int isFileOrDir();
int FileSearch(char file_path[]);
int FileCheck(file_path);
void CdCheck();
void CpCheck();
