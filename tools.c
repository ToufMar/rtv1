#include "rtv1.h"

int len_tab(char **split_val)
{
  int nb_tab;

  nb_tab = 0;
  while (split_val[nb_tab])
    nb_tab++;
  return (nb_tab);
}

int is_number(char *str)
{
  while (*str)
  {
    if (!(*str >= '0' && *str <= '9'))
      return (0);
    str++;
  }
  return (1);
}
