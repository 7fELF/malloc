/*
** main.c for PSU_2016_malloc in /home/antoine/PSU_2016_malloc
**
** Made by Antoine Baudrand
** Login   <antoine.baudrand@epitech.eu>
**
** Started on  mar. janv. 31 11:20:18 2017 Antoine Baudrand
** Last update mar. janv. 31 11:20:18 2017 Antoine Baudrand
*/

#include "malloc.h"

int main()
{
  int *a;

  a = (int*) malloc(sizeof(int));
  *a = 5;
  a = (int*) malloc(sizeof(int));
  *a = 5;
  a = (int*) malloc(sizeof(int));
  *a = 5;
  a = (int*) malloc(sizeof(int));
  *a = 5;
  show_alloc_mem();
}
