#ifndef RTV1_H
# define RTV1_H
# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>
#include <stdio.h>

typedef struct s_object
{
  char  *name;
  int   origin[3];
  int   size;
  char  color[3];
}             t_object;

typedef struct s_infos
{
  int   origin[3];
  int   rotation[3];
  int   spot[2];
}              t_infos;

typedef struct s_global
{
  struct s_infos  infos;
  struct s_object object;

}              t_global;

void    parse(char *av);
void    stock_data(t_global *g, char *str, int nb);
void    recup_data(char *buf, t_global *g);
void    stock_cam(char *occ, t_global *g, char *buf);
void    stock_origin(char **split_val, t_global *g, int wich);
void    stock_rotation(char **split_val, t_global *g);
void    stock_spot(char **split_val, t_global *g);
int     len_tab(char **split_val);
int     is_number(char *str);
void    stock_obj(char *occ, t_global *g, char *buf);
void    stock_name(char *name, t_global *g);

#endif
