#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include "message.h"

int msqid;
/*destination (pid of receiving process) and action sent to them (denied or granted)*/
void send_msg(int dest, int pid, int address, enum actions action) {
  msg_t msg = { .mtype = dest,
                .pid = pid, /*child doesn't need to know*/
                .address = address,
                .action = action
                };
  if (msgsnd(msqid, &msg, sizeof(msg_t), 0) == -1) {
    perror("./user: Error: msgsnd ");
    exit(EXIT_FAILURE);
  }
  return;
}

int read_or_write() {
  if(rand() % 4 > 0)
    return READ;
  else
    return WRITE;
}

int rand_address() {
  return rand() % 32768;
}

int main(int argc, char *argv[]) {
  srand(time(0));
  msqid = atoi(argv[1]);
  int simPid = atoi(argv[2]);
  int accessCounter = 0;
  while (1) {
    accessCounter++;
    /*Check to terminate*/
    if (accessCounter % 1000 == 0) {
      if (rand() % 10 > 4) {
        send_msg(ossChannel, simPid, 0, TERMINATE);
        return 0;
      }
    }
    /*send random memory request*/
    send_msg(ossChannel, simPid, rand_address(), read_or_write());
  }
  return 0;
}

