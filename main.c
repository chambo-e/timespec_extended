/*
** main.c for  in /home/chambo_e/Perso/timespec_extended
**
** Made by Emmanuel Chambon
** chambo_e  <chambon.emmanuel@gmail.com>
**
** Started on  Sun Jul 12 21:51:05 2015 Emmanuel Chambon
** Last update Sun Jul 12 21:57:19 2015 Emmanuel Chambon
*/

#include "timespec_extended.h"

#define timespec_t	struct timespec

int main()
{
  timespec_t	*now = timespec_now();

  while (1)
    {
      printf("%ld %ld\n", now->tv_sec, now->tv_nsec);
      timespec_t	*n = timespec_now();
      printf("%d\n", timespec_is_lower(now, n));
      printf("%d\n", timespec_is_greater(now, n));
      timespec_update(now);
      usleep(1000);
    }
}
