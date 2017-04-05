#include "rtv1.h"

void    stock_data(t_global *g, char *str, int nb, t_object *obj)
{
  int i;
  char *str_val;
  char **split_val;

  i = 0;
  while (str[i] != ';')
    i++;
  str_val = ft_strndup(str, i);
  split_val = ft_strsplit(str_val, ' ');
  free(str_val);
  if (nb == 1)
    stock_origin(split_val, g, 1, NULL);
  if (nb == 2)
    stock_rotation(split_val, g);
  if (nb == 3)
      stock_spot(split_val, g);
  if (nb == 4)
      stock_name(str_val, obj);
  if (nb == 5)
    stock_origin(split_val, g, 2, obj);
  if (nb == 6)
    stock_size(split_val, obj);
  if (nb == 7)
    stock_color(split_val, obj);
}

void    stock_cam(char *occ, t_global *g, char *buf)
{
  occ = &occ[ft_strlen("camera") + 4];
  if ((occ = ft_strstr(buf, "origin = ")))
  {
      occ = &occ[ft_strlen("origin = ")];
      stock_data(g, occ, 1, NULL);
  }
  if ((occ = ft_strstr(buf, "rotation = ")))
  {
      occ = &occ[ft_strlen("rotation = ")];
      stock_data(g, occ, 2, NULL);
  }
  if ((occ = ft_strstr(buf, "spot = ")))
  {
      occ = &occ[ft_strlen("spot = ")];
      stock_data(g, occ, 3, NULL);
  }
}

void    stock_obj(char *occ, t_global *g, t_object *obj)
{
  occ = &occ[ft_strlen("object") + 4];
  if ((occ = ft_strstr(occ, "name = ")))
  {
      occ = &occ[ft_strlen("name = ")];
      stock_data(g, occ, 4, obj);
  }
  if ((occ = ft_strstr(occ, "origin = ")))
  {
      occ = &occ[ft_strlen("origin = ")];
      stock_data(g, occ, 5, obj);
  }
  if ((occ = ft_strstr(occ, "size = ")))
  {
      occ = &occ[ft_strlen("size = ")];
      stock_data(g, occ, 6, obj);
  }
  if ((occ = ft_strstr(occ, "color = ")))
  {
      occ = &occ[ft_strlen("color = ")];
      stock_data(g, occ, 7, obj);
  }
}

void    recup_data(char *buf, t_global *g)
{
  char *occ;

  if ((occ = ft_strstr(buf, "camera")) && (occ = ft_strstr(buf, "object")))
  {
     if ((occ[ft_strlen("camera") + 1]) == '{')
       stock_cam(occ, g, buf);
     if (occ[ft_strlen("object") + 1] == '{')
       stock_objet(occ, g);
  }
  else
  {
    ERROR_OBJ;
    ft_putstr("or\n");
    ERROR_CAM;
  }
}

void    parse(char *av, t_global *g)
{
  char      *buf;
  int       fd;
  size_t    size;

  size = 2000;
  fd = open(av, O_RDONLY);
  if (fd >= 0)
  {
    buf = (char *)malloc(sizeof(char) * size);
    read(fd, buf, size * sizeof(char));
    close(fd);
    if ((g->nb_obj = nb_obj(buf)))
    {
      g->object = (t_object*)malloc(sizeof(t_object) * g->nb_obj);
      init_obj(g, g->nb_obj);
      recup_data(buf, g);
    }
  }
  else
    exit(0);
  free(buf);

}
