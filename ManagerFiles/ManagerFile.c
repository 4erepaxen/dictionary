#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <ManagerFile.h>

FILE *fopen_from_proj_dir(const char *file_name,const char *path_to_root_dir, char *mode)
{
    char *path = malloc(sizeof(char) * 512);
    FILE *return_file;
    for (int i = 0; i < 512; i++)
        path[i] = '\0';
    strcpy(path, realpath(path_to_root_dir, 0));
    
    int tem_index = 0; 
    while (path[tem_index++] != '\0');
    while (path[--tem_index] != '/')
        path[tem_index] = '\0';

    snprintf(path, sizeof(char) * 512, "%s%s", path, file_name);
    return_file  = fopen(path, mode);
    return return_file;
}
