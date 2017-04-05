#ifndef RTV1_H
# define RTV1_H
# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

#define ERROR_O ft_putendl("There's no object mamen");
#define ERROR_OBJ { ERROR_O exit(0); }
#define ERROR_C ft_putendl("There's no camera mamen");
#define ERROR_CAM { ERROR_C exit(0); }
#define ERROR_R ft_putendl("Pb syntax in rotation");
#define ERROR_ROT { ERROR_R exit(0); }
#define ERROR_OR ft_putendl("Pb syntax in origin");
#define ERROR_ORI { ERROR_OR exit(0); }
#define ERROR_S ft_putendl("Pb syntax in spot");
#define ERROR_SP { ERROR_S exit(0); }
#define ERROR_N ft_putendl("The obect does not exist");
#define ERROR_NAM { ERROR_N exit(0); }
#define ERROR_CO ft_putendl("Pb syntax in color");
#define ERROR_COL { ERROR_CO exit(0); }
#define ERROR_SI ft_putendl("Pb syntax in size");
#define ERROR_SIZ { ERROR_SI exit(0); }





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

typedef struct s_sdl
{
  SDL_Window  *window;
  SDL_Renderer *render;
  SDL_Event   event;
}
                t_sdl;

typedef struct s_global
{
  struct s_infos  infos;
  struct s_object *object;
  struct s_sdl    *sdl;
  int             nb_obj;

}              t_global;



void    parse(char *av, t_global *g);
void    stock_data(t_global *g, char *str, int nb, t_object *obj);
void    recup_data(char *buf, t_global *g);
void    stock_cam(char *occ, t_global *g, char *buf);
void    stock_origin(char **split_val, t_global *g, int wich, t_object *obj);
void    stock_rotation(char **split_val, t_global *g);
void    stock_spot(char **split_val, t_global *g);
int     len_tab(char **split_val);
int     is_number(char *str);
void    stock_obj(char *occ, t_global *g, t_object *obj);
void    stock_name(char *name, t_object *obj);
void    stock_size(char **split_val, t_object *obj);
void    stock_color(char **split_val, t_object *obj);
int     nb_obj(char *occ);
void    stock_objet(char *buf, t_global *g);
void    init_obj(t_global *g, int nb);
void open_window(t_global *g);


#endif
