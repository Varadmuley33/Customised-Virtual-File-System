
Marvellous CVFS - Customized Virtual File System
-----------------------------------------------------------------------

Author: Neha Navin Desai 
Date: 10/08/2025  
Language: C++  
Description: A command-line-based virtual file system simulator.

-----------------------------------------------------------------------
Overview
-----------------------------------------------------------------------
This project simulates a **Custom Virtual File System (CVFS)**. 
It mimics basic file system operations like creating, reading, 
writing, deleting, and managing files using user-defined structures 
(e.g., SuperBlock, Inode, FileTable) and logic implemented in C++.

-----------------------------------------------------------------------
Features
-----------------------------------------------------------------------
- Create a regular file with permissions
- Delete existing files
- List all created files
- View file statistics (similar to `stat` in Unix)
- Read from and write to files
- Display help and command manuals

-----------------------------------------------------------------------
How It Works
-----------------------------------------------------------------------
The project defines and manages:
- `BootBlock` – stores boot information
- `SuperBlock` – manages inode usage
- `Inode` – represents metadata of a file
- `FileTable` – contains info for opened files
- `UAREA` – user area, simulates a process environment

The virtual file system supports a limited number of files (`MAXINODE = 5`)
and opened files (`MAXOPENEDFILES = 20`).

-----------------------------------------------------------------------
Commands Available (via CLI)
-----------------------------------------------------------------------
Use the following commands in the CVFS shell:

- `man <command>`        → Show manual/help for a command
- `exit`                 → Exit the virtual file system
- `clear`                → Clear the terminal
- `creat <filename> <permission>` → Create a new file
- `unlink <filename>`    → Delete a file
- `stat <filename>`      → Display file information
- `ls`                   → List all files
- `write <fd>`           → Write data to file using file descriptor
- `read <fd> <size>`     → Read data from file using file descriptor

Permissions:
- 1 → Read
- 2 → Write
- 3 → Read + Write

-----------------------------------------------------------------------
Error Codes
-----------------------------------------------------------------------
The system uses error codes for handling exceptions:

- `-1` → Invalid Parameter
- `-2` → No Inodes Available
- `-3` → File Already Exists
- `-4` → File Not Found
- `-5` → Permission Denied
- `-6` → Insufficient Space
- `-7` → Insufficient Data
