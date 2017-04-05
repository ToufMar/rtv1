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

int nb_obj(char *occ)
{
  int i;

  i = 0;
  while (*occ)
  {
    if (occ == ft_strstr(occ, "object"))
    {
      occ = &occ[ft_strlen("object")];
      i++;
    }
    occ++;
  }
  return (i > 0 ? i : 0);
}

void init_obj(t_global *g, int nb)
{
  int i;

  i = 0;
  while (i < nb)
  {
    ft_bzero(&g->object[i], sizeof(t_object));
    i++;
  }
}
