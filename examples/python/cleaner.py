#!/usr/bin/env python

import os.path

def uniqueName():
    return "kross_python_example"

def description():
    return "##### KROSS PYTHON EXAMPLE #####"

def iconName():
    return "konqueror"

def youlaji():
    return os.path.isfile("/var/tmp/pythonsaolaji.txt")

def saolaji():
    os.remove("/var/tmp/pythonsaolaji.txt")
    return True
