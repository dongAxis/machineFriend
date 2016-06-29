//
//  main.h
//  machineFriend
//
//  Created by Axis on 6/28/16.
//  Copyright © 2016 Axis. All rights reserved.
//

#ifndef main_h
#define main_h

#include <Python/Python.h>

#undef EXPORT_FUNC
#define EXPORT_FUNC __attribute__((visibility("default")))

#define EFLAGS_MAP_MACRO(array, n, init_value)              \
        ({                                                  \
            typeof(var) *test=&var;                         \
            bzero(test->name, sizeof(test->name));          \
            strcpy(test->name, n);                          \
            test->value = (init_value);                     \
            test;                                           \
        })

#define INIT_RFLAGS(entry)          \
        bzero(entry, )

#define EFLAGS_BEGIN(type)                         \
        do {                                       \
            int step=0;                     \
            static type var;

#define EFLAGS_END              \
        }while(0);

#define EFLAGS_SET_VALUE(array, name, init_value)            \
        array[step++] = *EFLAGS_MAP_MACRO(array, name, init_value);

struct rflags_entry
{
    char name[16];
    uint16_t value;
}rflags_map[64];

#endif /* main_h */
