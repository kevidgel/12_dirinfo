#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>


int main(int argc, char **argv)
{
    DIR *cur; 
    char path[100];
    // Input 
    if (argc > 1) strncpy(path, argv[1], sizeof(path)); 
    else
    {
        fgets(path, sizeof(path), stdin);
        path[strlen(path) - 1] = '\0'; 
    }
    cur = opendir(path);
    if (cur == NULL) {
        printf("errno: %d\terror: %s\n", errno, strerror(errno));
        return -1;
    }
    

    // Current directory size
    struct stat tat;
    long int total = 0; 
    struct dirent *dent;
    dent = readdir(cur);

    while(dent)
    {   
        if (dent->d_type = DT_REG)
        {
            stat(dent->d_name, &tat);
            printf("%s: %ld\n", dent->d_name, tat.st_size);
            total += tat.st_size;
        }
        dent = readdir(cur);
    }

    printf("Statistics for directory: %s\n", path);
    printf("Total Directory Size: %ld Bytes\n", total);

    rewinddir(cur);

    // Printing Directories
    printf("Directories:\n");
    dent = readdir(cur);
    while (dent) 
    {   
        if (dent->d_type == DT_DIR) 
        {
            printf("\t%s\n", dent->d_name);
        }
        dent = readdir(cur);
    }

    rewinddir(cur);

    // Printing Regular Files
    printf("Regular files:\n");
    dent = readdir(cur); 
    while (dent) 
    {
        if (dent->d_type == DT_REG) 
        {
            printf("\t%s\n", dent->d_name);
        }
        dent = readdir(cur);
    }

    closedir(cur);

}