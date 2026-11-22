#ifndef __KSU_MANUAL_HOOKS_H
#define __KSU_MANUAL_HOOKS_H

#include <linux/types.h>
#include <linux/uaccess.h>
#include "uapi/supercall.h"

int ksu_handle_sys_reboot(int magic1, int magic2, unsigned int cmd,
                          void __user **arg);
struct filename;

int ksu_handle_execveat(int *fd, struct filename **filename_ptr,
                        void *argv, void *envp, int *flags);
void ksu_handle_sys_read(unsigned int fd);
int ksu_handle_input_handle_event(unsigned int *type,
                                  unsigned int *code, int *value);
struct stat;
struct stat64;
struct compat_stat;
void ksu_handle_newfstat_ret(unsigned int *fd,
                             struct stat __user **statbuf_ptr);

void ksu_handle_compat_newfstat_ret(unsigned int *fd,
                                    struct compat_stat __user **statbuf_ptr);


void ksu_handle_fstat64_ret(unsigned long *fd,
                            struct stat64 __user **statbuf_ptr);

#endif /* __KSU_MANUAL_HOOKS_H */
