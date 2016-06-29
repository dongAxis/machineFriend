#!/usr/bin/python

import lldb
import commands
import optparse
import shlex
import string
import ctypes
import sys

import friend


# import machineFriend

def rflags(debugger, command, result, internal_dict):

	try:
		interpreter = lldb.debugger.GetCommandInterpreter()
		returnObject = lldb.SBCommandReturnObject()
		interpreter.HandleCommand("reg re rflags", returnObject)

		output = returnObject.GetOutput()
		output = output.strip('\n')
		output = output.strip('\r')
		output = output.strip()		#rflags = 0x0000000000000246

		#1. strip string
		value_array = output.split(' ')
		if len(value_array)!=3 : 
			raise "length of value_array should be 3, but %d" % len(value_array)

		rflags = value_array[2]		#get rflags' value
		rflags = rflags.strip()		#remove spaces

		rflags_number = int(rflags, 16)
		print rflags
		result = friend.rflags(rflags_number)
	except Exception,e:
		raise e


def init(debugger, command, result, internal_dict):
	debugger.HandleCommand('br set -n main')
	debugger.HandleCommand('r')
	debugger.HandleCommand('rflags')

def ls(debugger, command, result, internal_dict):
    print >>result, (comrflagsmands.getoutput('/bin/ls %s' % command))

# And the initialization code to add your commands 
def __lldb_init_module(debugger, internal_dict):
    debugger.HandleCommand('command script add ls -f intel.ls')
    debugger.HandleCommand('command script add init -f intel.init')
    debugger.HandleCommand('command script add rflags -f intel.rflags')

    # for test
    # debugger.HandleCommand('br set -n main')
    # debugger.HandleCommand('r')
    # debugger.HandleCommand('rflages')
    print 'The "ls" python command has been installed and is ready for use.'