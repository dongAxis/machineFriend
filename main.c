//
//  main.c
//  machineFriend
//
//  Created by Axis on 6/28/16.
//  Copyright © 2016 Axis. All rights reserved.
//

#include "main.h"

#include <stdio.h>
#

#define JUNCK_BIT  "JUNCK"

void init_rflags()
{
    EFLAGS_BEGIN(struct rflags_entry)

    #include "./eflags.inc"

    EFLAGS_END
}

PyObject* rflags(PyObject* self, PyObject* str_num)
{
    uint32_t eflags = 0x0;
    PyObject *returnObj=NULL;
    char rflags_status[1024];

    //now rflags = eflags
    if(str_num==NULL)
        return NULL;

    PyArg_ParseTuple(str_num, "i", &eflags);

    bzero(rflags_status, sizeof(rflags_status));
    init_rflags();

    char * cur_ptr = rflags_status;
    int index = 0;
    for(int i=0; i<32; i++)
    {
//        if(eflags==0) break;

        if(strlen(rflags_map[i].name)!=0 && strncmp(rflags_map[i].name, JUNCK_BIT, sizeof(JUNCK_BIT))!=0)
        {
            if((eflags&0x01)!=0)
            {
                rflags_map[i].value=1;
            }

            //1. flags' name
            strcpy(cur_ptr, rflags_map[i].name);
            cur_ptr+=strlen(rflags_map[i].name);
            strcpy(cur_ptr, " = ");
            cur_ptr+=strlen(" = ");
            strcpy(cur_ptr, rflags_map[i].value==1?"1   ":"0   ");
            cur_ptr+=strlen("1   ");
            index ++;

            if(index%5==0)
            {
                strcpy(cur_ptr, "\n");
                cur_ptr++;
            }
        }

        eflags>>=1;
    }
    printf("%s\n", rflags_status);


    returnObj = Py_BuildValue("s", "hello");

    return returnObj;
}

static PyMethodDef externalMethods[] = {
//    {"add", PyCal_add, METH_VARARGS, "Add two integer values."},
    {"rflags", rflags, METH_VARARGS, "get rflags"},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initfriend(void)
{
    PyObject *module=NULL;

    module = Py_InitModule("friend", externalMethods);
    if(!module)
    {
        return ;
    }

    init_rflags();
}

