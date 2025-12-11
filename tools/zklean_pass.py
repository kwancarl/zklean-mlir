#!/usr/bin/env python
import sys
import os
import tempfile

# TODO: Figure out how to do this in mlir

tmp=tempfile.mkstemp()


with open(sys.argv[1]) as fd1, open(tmp[1],'w') as fd2:
    for line in fd1:
        line = line.replace('=',':=')
        fd2.write(line)

os.rename(tmp[1],sys.argv[1])
