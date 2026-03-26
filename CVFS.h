#ifndef CVFS_H
#define CVFS_H

//////////////////////////////////////////////////////////
//
//  Header File Inclusion
//
//////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<string.h>

//////////////////////////////////////////////////////////
//
//  User Defined Macros
//
//////////////////////////////////////////////////////////

#define MAXFILESIZE 50
#define MAXOPENFILES 20
#define MAXINODE 5

#define READ 1
#define WRITE 2
#define EXECUTE 4

#define START 0
#define CURRENT 1
#define END 2

#define EXECUTE_SUCCESS 0

#define REGULARFILE 1
#define SPECIALFILE 2

//////////////////////////////////////////////////////////
//
//  Error Codes
//
//////////////////////////////////////////////////////////

#define ERR_INVALID_PARAMETER -1
#define ERR_NO_INODES -2
#define ERR_FILE_ALREADY_EXIST -3
#define ERR_FILE_NOT_EXIST -4
#define ERR_PERMISSION_DENIED -5
#define ERR_INSUFFICIENT_SPACE -6
#define ERR_INSUFFICIENT_DATA -7
#define ERR_MAX_FILES_OPEN -8

//////////////////////////////////////////////////////////
//
//  Structures
//
//////////////////////////////////////////////////////////

struct BootBlock
{
    char Information[100];
};

struct SuperBlock
{
    int TotalInodes;
    int FreeInodes;
};

#pragma pack(1)
struct Inode
{
    char FileName[20];
    int InodeNumber;
    int FileSize;
    int ActualFileSize;
    int FileType;
    int ReferenceCount;
    int Permission;
    char *Buffer;
    struct Inode *next;
};

typedef struct Inode INODE;
typedef struct Inode * PINODE;
typedef struct Inode ** PPINODE;

struct FileTable
{
    int ReadOffset;
    int WriteOffset;
    int Mode;
    PINODE ptrinode;
};

typedef struct FileTable FILETABLE;
typedef struct FileTable * PFILETABLE;

struct UAREA
{
    char ProcessName[20];
    PFILETABLE UFDT[MAXOPENFILES];
};

//////////////////////////////////////////////////////////
//
//  Global Variables (extern)
//
//////////////////////////////////////////////////////////

extern struct BootBlock bootobj;
extern struct SuperBlock superobj;
extern struct UAREA uareaobj;

extern PINODE head;

//////////////////////////////////////////////////////////
//
//  Function Declarations
//
//////////////////////////////////////////////////////////

void InitialiseUAREA();
void InitialiseSuperBlock();
void CreateDILB();
void StartAuxillaryDataInitilisation();

void DisplayHelp();
void ManPageDisplay(char Name[]);

bool IsFileExist(char *name);

int CreateFile(char *name, int permission);
void LsFile();
void StatFile(char *name);
int UnlinkFile(char *name);

int WriteFile(int fd, char *data, int size);
int ReadFile(int fd, char *data, int size);

#endif