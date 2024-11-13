/*Take multiple files as command-line arguments and print their file type and inode number.*/
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;
    for (int i = 1; i < argc; i++) {
        if (stat(argv[i], &fileStat) == 0) {
            printf("File: %s\n", argv[i]);
            printf("Inode: %ld\n", fileStat.st_ino);
            if (S_ISREG(fileStat.st_mode))
                printf("Type: Regular File\n\n");
            else if (S_ISDIR(fileStat.st_mode))
                printf("Type: Directory\n\n");
            else
                printf("Type: Other\n\n");
        } else {
            printf("Cannot access %s\n\n", argv[i]);
        }
    }
    return 0;
}




How To Run
--->  cc slip.c
---> ./a.out
--->  gcc slip.c -o slip
---> ./slip slip.c

/*$ ./a.out file1.txt directory1 file2.txt
File: file1.txt
Inode: 1234567
Type: Regular File

File: directory1
Inode: 1234589
Type: Directory

File: file2.txt
Inode: 1234590
Type: Regular File
*/