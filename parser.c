#include "rtv1.h"

void    stock_data(t_global *g, char *str, int nb)
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
    stock_origin(split_val, g, 1);
  if (nb == 2)
    stock_rotation(split_val, g);
  if (nb == 3)
    stock_spot(split_val, g);
  if (nb == 4)
    stock_name(str_val, g);
  if (nb == 5)
    stock_origin(split_val, g, 2);
  if (nb == 6)
    stock_size(split_val, g);
  if (nb == 7)
    stock_color(split_val, g);
}

void    stock_obj(char *occ, t_global *g, char *buf)
{
  occ = &occ[ft_strlen("object") + 4];
  if ((occ = ft_strstr(buf, "name = ")))
  {
      occ = &occ[ft_strlen("name = ")];
      stock_data(g, occ, 3);
  }
  if ((occ = ft_strstr(buf, "origin = ")))
  {
      occ = &occ[ft_strlen("origin = ")];
      stock_data(g, occ, 4);
  }
  if ((occ = ft_strstr(buf, "size = ")))
  {
      occ = &occ[ft_strlen("size = ")];
      stock_data(g, occ, 5);
  }
  if ((occ = ft_strstr(buf, "color = ")))
  {
      occ = &occ[ft_strlen("color = ")];
      stock_data(g, occ, 6);
  }
}

void    stock_cam(char *occ, t_global *g, char *buf)
{
  occ = &occ[ft_strlen("camera") + 4];
  if ((occ = ft_strstr(buf, "origin = ")))
  {
      occ = &occ[ft_strlen("origin = ")];
      stock_data(g, occ, 1);
  }
  if ((occ = ft_strstr(buf, "rotation = ")))
  {
      occ = &occ[ft_strlen("rotation = ")];
      stock_data(g, occ, 2);
  }
  if ((occ = ft_strstr(buf, "spot = ")))
  {
      occ = &occ[ft_strlen("spot = ")];
      stock_data(g, occ, 3);
  }
}

void    recup_data(char *buf, t_global *g)
{
  int i;
  char *occ;

  if ((occ = ft_strstr(buf, "camera")))
  {
     if ((occ[ft_strlen("camera") + 1]) == '{')
       stock_cam(occ, g, buf);
  }
  else
    ft_putstr("Error file\n");
  if ((occ = ft_strstr(buf, "object")))
  {
    if (occ[ft_strlen("object") + 1] == '{')
      stock_obj(occ, g, buf);
  }
  else
    ft_putstr("Error file\n");
}

void    parse(char *av)
{
  char      *buf;
  int       fd;
  size_t    size;
  t_global  g;

  size = 2000;
  ft_bzero(&g, sizeof(t_global));
  fd = open(av, O_RDONLY);
  if (fd >= 0)
  {
    buf = (char *)malloc(sizeof(char) * size);
    read(fd, buf, size * sizeof(char));
    close(fd);
  }
  else
    exit(0);
  recup_data(buf, &g);
  int i = 0;

  while(i < 3)
  {
    printf("%d\n", g.infos.rotation[i]);
    i++;
  }
}
