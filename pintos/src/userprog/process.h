#ifndef USERPROG_PROCESS_H
#define USERPROG_PROCESS_H

#include "threads/thread.h"
#include <list.h>
#include "threads/synch.h"
#include "filesys/file.h"
#include "lib/kernel/list.h"

struct pair
  {
    int fd;
    struct file *file;
    struct list_elem elem;
  };

struct exec_helper
  {
    const char file_name[16];   /* first part form cmd_line */
    char file_name_[16];
    size_t fn_length;           /* length of file_name */
    const char *cmd_line;       /* whole command line entry */
    struct semaphore semaphore;
    bool load_success;
    struct thread *thread;
    struct thread *parent;
  };


tid_t process_execute (const char *file_name);
int process_wait (tid_t);
void process_exit (void);
void process_activate (void);

#endif /* userprog/process.h */
