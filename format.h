#ifndef FORMAT_H
#define FORMAT_H

#include <stdio.h>

typedef struct {
  unsigned int s;   /*seconds*/
  unsigned int ns;  /*nanoseconds*/
} simtime_t;

/*increment given simulated time t by given increment inc*/
void increment_sim_time(simtime_t *t, int inc) {
  t->ns += inc;
  if (t->ns >= 1000000000) {
    t->ns -= 1000000000;
    t->s += 1;
  }
}

/* returns a - b*/
simtime_t subtract_sim_times(simtime_t a, simtime_t b) {
  simtime_t diff = {.s = a.s - b.s,
                    .ns = a.ns - b.ns};
  if (diff.ns < 0) {
    diff.ns += 1000000000;
    diff.s -= 1;
  }
  return diff;
}

/*returns a + b*/
simtime_t add_sim_times(simtime_t a, simtime_t b) {
  simtime_t sum = {.s = a.s + b.s,
                   .ns = a.ns + b.ns};
  if (sum.ns >= 1000000000) {
    sum.ns -= 1000000000;
    sum.s += 1;
  }
  return sum;
}
/*returns 1 if a <= b*/
/*0 otherwise*/
int less_or_equal_sim_times(simtime_t a, simtime_t b) {
  if (a.s > b.s) {
    return 0;
  } else if (a.s == b.s && a.ns > b.ns) {
    return 0;
  }
  return 1;
}

#endif
