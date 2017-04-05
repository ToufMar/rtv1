#include "rtv1.h"

int main(int ac, char **av)
{
  if (ac == 2)
  {
    t_global g;
    ft_bzero(&g, sizeof(t_global));
    parse(av[1], &g);
    open_window(&g);
  }
  return (0);
}
