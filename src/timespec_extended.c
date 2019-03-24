/*
** Made by Emmanuel Chambon
** chambo_e  <chambon.emmanuel@gmail.com>
**
** Started on  Fri Jul  3 05:56:50 2015 Emmanuel Chambon
** Last update Sun Jul 12 21:24:34 2015 Emmanuel Chambon
*/

#include "timespec_extended.h"

/*
**
*/
struct timespec		*timespec_now()
{
  struct timespec	*time;

  if (!(time = malloc(sizeof(struct timespec))))
    return (NULL);
  timespec_update(time);
  return (time);
}

/*
**
*/
struct timespec		*timespec_init(struct timespec *base)
{
  struct timespec	*time;

  if (!(time = malloc(sizeof(struct timespec))))
    return (NULL);
  if (!base)
    timespec_update(time);
  else
    {
      time->tv_sec = base->tv_sec;
      time->tv_nsec = base->tv_nsec;
    }
  return (time);
}

/*
**
*/
void			timespec_update(struct timespec *time)
{
  assert(time != NULL);
#if defined(_POSIX_C_SOURCE) || defined(__APPLE__)
  if (clock_gettime(CLOCK_BOOTTIME, time))
    perror("clock_gettime");
#else
  if (!timespec_get(time, TIME_UTC))
    perror("timespec_get");
#endif
}

/*
**
*/
void			timespec_release(struct timespec *t)
{
  assert(t != NULL);
  free(t);
}
