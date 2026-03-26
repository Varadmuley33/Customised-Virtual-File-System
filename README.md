# 📁 CVFS (Custom Virtual File System)

## 🚀 Overview

CVFS is a custom-built Virtual File System implemented in C/C++.
It simulates core file handling operations of an operating system using in-memory data structures.

This project demonstrates how file systems internally manage files using concepts like inodes, file descriptors, buffers, and system-level operations.

---

## 🎯 Purpose of the Project

The main goal of this project is to understand and implement:

* File system architecture (inode-based design)
* File creation, deletion, and manipulation
* Memory management using dynamic allocation
* File descriptor handling (similar to UNIX systems)
* Low-level system programming concepts

---

## 🧠 Key Concepts Used

* Inodes (Index Nodes)
* File Descriptors (FD)
* File Table (UFDT)
* Buffer Management
* Linked List (DILB)
* Dynamic Memory Allocation (malloc)
* Command-based shell interface

---

## ⚙️ Features

* Create files (`creat`)
* Write data into files (`write`)
* Read data from files (`read`)
* Delete files (`unlink`)
* Display file information (`stat`)
* List all files (`ls`)
* Help menu (`help`)
* Manual pages (`man`)

---

## 🏗️ Project Structure

```
📁 CVFS
 ├── cvfs.h        → Declarations, structures, macros
 ├── cvfs.cpp      → Core logic and functions
 ├── main.cpp      → Entry point and command handler
 └── README.md     → Project documentation
```

---

## 🖥️ How to Run

### Step 1: Open terminal in project folder

### Step 2: Compile

```
g++ main.cpp cvfs.cpp -o cvfs
```

### Step 3: Run

```
./cvfs
```

(For Windows: `cvfs.exe`)

---

## 💡 How to Use (Commands)

| Command                     | Description          |
| --------------------------- | -------------------- |
| `creat FileName Permission` | Create new file      |
| `write FD`                  | Write data into file |
| `read FD Size`              | Read data from file  |
| `ls`                        | List all files       |
| `stat FileName`             | Display file details |
| `unlink FileName`           | Delete file          |
| `man Command`               | Show manual          |
| `help`                      | Show all commands    |
| `exit`                      | Exit program         |

---

## 🧪 Example Usage

```
creat demo.txt 3
write 3
read 3 10
ls
stat demo.txt
unlink demo.txt
```

---

## ⚠️ Important Notes

* This is a **virtual file system** — files are stored in RAM (not on disk)
* All data is lost after program termination
* File descriptors are used for read/write operations
* Read and write operations use internal file offsets

---

## 🌍 Real-World Relevance

This project reflects how real operating systems manage files internally.
It is useful for understanding concepts used in:

* Operating Systems
* System Programming
* File Management Systems
* Low-level memory handling

---

## 🧑‍💻 Author

**Varad Nitin Muley**

---

## 📌 Conclusion

This project provides a strong foundation in system-level programming and demonstrates how file systems work internally. It is useful for learning, interviews, and understanding real-world OS concepts.
