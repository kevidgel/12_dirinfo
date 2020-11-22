#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>


int main()
{
    // Scanning current directory
    DIR *cur = opendir(".");

    // Current directory size
    struct stat tat;
    int total = 0; 
    struct dirent *dent;
    dent = readdir(cur);

    while(dent)
    {   
        if (dent->d_type = DT_REG)
        {
            stat(dent->d_name, &tat);
            total += tat.st_size;
        }
        dent = readdir(cur);
    }

    printf("Statistics for directory: .\n");
    printf("Total Directory Size: %d Bytes\n", total);

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