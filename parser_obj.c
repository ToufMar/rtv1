#include "rtv1.h"

void    stock_objet(char *buf, t_global *g)
{
  int i;
  int nb;

  i = 0;
  nb = nb_obj(buf);
  while (*buf)
  {
    if (buf == ft_strstr(buf, "object") && buf[ft_strlen("object") + 1] == '{')
    {
      if (i < nb)
      {
        stock_obj(buf, g, &g->object[i]);
        buf = &buf[ft_strlen("object") + 4];
        i++;
      }
    }
    buf++;
  }
}

void    stock_size(char **split_val, t_object *obj)
{
  if (len_tab(split_val) == 1)
  {
    if (is_number(split_val[0]))
        obj->size = ft_atoi(split_val[0]);
  }
  else
    ERROR_SI;
}

void    stock_color(char **split_val, t_object *obj)
{
  if (len_tab(split_val) == 3)
  {
    int i;

    i = 0;
    while (split_val[i])
    {
       if (is_number(split_val[i]))
        obj->color[i] = ft_atoi(split_val[i]);
      i++;
    }
  }
  else
    ERROR_CO;
}

void    stock_name(char *name, t_object *obj)
{
  if (!ft_strcmp(name, "sphere") || !ft_strcmp(name, "cylindre") ||
      !ft_strcmp(name, "plan") || !ft_strcmp(name, "cone"))
    obj->name = ft_strdup(name);
  else
    ERROR_NAM;
}
