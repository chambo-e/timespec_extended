/*
** timespec_sub.c for  in /home/chambo_e/epitech/PSU_2014_zappy/src/srv
**
** Made by Emmanuel Chambon
** chambo_e  <chambon.emmanuel@gmail.com>
**
** Started on  Fri Jul  3 05:58:11 2015 Emmanuel Chambon
** Last update Sun Jul 12 21:20:13 2015 Emmanuel Chambon
*/

#include "timespec_extended.h"

void            timespec_sub_usec(struct timespec *time,
				  unsigned long long int usec, bool reset)
{
  assert(time != NULL);
  timespec_sub_timespec(time, timespec_convert(usec), reset);
}

void            timespec_sub_timespec(struct timespec *one,
				      struct timespec *two, bool reset)
{
  assert(one != NULL && two != NULL);
  if (reset)
    timespec_update(one);
  one->tv_sec -= two->tv_sec;
  one->tv_nsec -= two->tv_nsec;
}
