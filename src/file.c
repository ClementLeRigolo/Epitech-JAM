/*
** EPITECH PROJECT, 2021
** jam3
** File description:
** file.c
*/

#include "../include/jam.h"
#include "../include/pos.h"
#include "../include/images.h"

int get_file_nbr(char *pathname)
{
    int i = 0;
    DIR *folder;
    struct dirent *entry;
    int files;

    folder = opendir(pathname);
    for (; entry = readdir(folder); i++);
    closedir(folder);
    return (i);
}

char **get_file(char *pathname)
{
    char **dir = malloc(sizeof(char *) * (get_file_nbr(pathname) + 1));
    DIR *folder;
    struct dirent *entry;
    int files;

    folder = opendir(pathname);
    for (int i = 0; entry = readdir(folder); i++)
        dir[i] = strdup(entry->d_name);
    closedir(folder);
    dir[get_file_nbr(pathname)] = NULL;
    return (dir);
}