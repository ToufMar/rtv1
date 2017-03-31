#include "rtv1.h"

void    stock_size(char **split_val, t_global *g)
{
  if (len_tab(split_val) == 3)
  {
    int i;

    i = 0;
    while (split_val[i])
    {
      if (is_number(split_val[i]))
        g->infos.rotation[i] = ft_atoi(split_val[i]);
      i++;
    }
  }
  else
    printf("pb valeurs dans size");
}

void    stock_name(char *name, t_global *g)
{

  if (!ft_strcmp(name, "sphere") || !ft_strcmp(name, "cylindre") ||
      !ft_strcmp(name, "plan") || !ft_strcmp(name, "cone"))
    g->object.name = ft_strdup(name);
  else
    printf("pb valeurs dans stock_name");
}

void    stock_spot(char **split_val, t_global *g)
{
  if (len_tab(split_val) == 2)
  {
    int i;

    i = 0;
    while (split_val[i])
    {
       if (is_number(split_val[i]))
        g->infos.spot[i] = ft_atoi(split_val[i]);
      i++;
    }
  }
  else
    printf("pb valeurs dans rotation");
}

void    stock_rotation(char **split_val, t_global *g)
{
  if (len_tab(split_val) == 3)
  {
    int i;

    i = 0;
    while (split_val[i])
    {
      if (is_number(split_val[i]))
        g->infos.rotation[i] = ft_atoi(split_val[i]);
      i++;
    }
  }
  else
    printf("pb valeurs dans rotation");
}

void    stock_origin(char **split_val, t_global *g, int wich)
{
  if (len_tab(split_val) == 3)
  {
    int i;

    i = 0;
    while (split_val[i])
    {
      if (is_number(split_val[i]))
      {
        if (wich == 1)
          g->infos.origin[i] = ft_atoi(split_val[i]);
        if (wich == 2)
          g->object.origin[i] = ft_atoi(split_val[i]);
      }
      i++;
    }
  }
  else
    printf("pb valeurs dans origin");
}
