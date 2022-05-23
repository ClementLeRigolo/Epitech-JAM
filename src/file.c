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
    int i = 0;
    int minus = 0;

    folder = opendir(pathname);
    while (entry = readdir(folder)) {
        if (entry->d_name[0] != '.') {
            dir[i] = strdup(entry->d_name);
            i++;
        } else {
            minus++;
        }
    }
    closedir(folder);
    dir[get_file_nbr(pathname) - minus] = NULL;
    return (dir);
}