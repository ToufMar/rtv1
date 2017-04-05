#include "rtv1.h"

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
    ERROR_SP;
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
    ERROR_ROT;
}

void    stock_origin(char **split_val, t_global *g, int wich, t_object *obj)
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
          obj->origin[i] = ft_atoi(split_val[i]);
      }
      i++;
    }
  }
  else
    ERROR_OR;
}
