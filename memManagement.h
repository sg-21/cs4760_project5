#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H

#define PROCESS_SIZE 32 
#define TOTAL_MEMORY 256 

/* Frame*/
typedef struct {
  unsigned ref : 8; /*reference bit*/
  unsigned dirty : 1; /*dirty bit*/
  int pid; /*process id of owner*/
} frame_t;

/* Page*/
typedef struct {
  int framePos; /*positio*/
} page_t;

/* Page Table*/
typedef struct {
  page_t pages[PROCESS_SIZE]; /*array of pages*/
} pagetable_t;


#endif
