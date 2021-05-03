#ifndef MESSAGE_H
#define MESSAGE_H

typedef struct {
  long mtype;
  int pid;
  int address;
  int action;
} msg_t;

enum actions {READ, WRITE, TERMINATE};

/*mtype that oss will be looking for*/
const int ossChannel = 20;

#endif

