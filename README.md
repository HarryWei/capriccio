> [Capriccio](http://capriccio.cs.berkeley.edu/index.html) was a project at Berkeley whose goal was to create a high performance systems software library, while keeping the programming model simple. This was done through 3 techniques:
>
>1.  Cooperative threading (via coroutines)
>2.  Dynamic stack sizing
>3.  Dynamic scheduling based on the blocking graph
>
> This project seems to have ended in 2004. But there are some interesting papers in the [papers folder](https://github.com/bernied/capriccio/tree/master/papers).
>
> What follows is the readme from the currently available [download](http://capriccio.cs.berkeley.edu/downloads.html). These files have not been ported or upgraded. They are here for historical purposes. I have no personal stake in the project, other then I thnk its cool.


## Introduction

This is the Capriccio source code repository for the [SOSP 2003](http://www.cs.rochester.edu/meetings/sosp2003/)
conference CD.  This file contains basic instructions on getting
started with Capriccio.  For more detailed documentation, and for
updated source code, please visit our web site:

  [http://capriccio.cs.berkeley.edu/](http://capriccio.cs.berkeley.edu/)


## Getting Started

To build Capriccio, simply copy "Make.opts.sample" to "Make.opts", and
edit appropriately.  There are a number of comments in the file that
describe various compile-time options.  The default settings should
work for a vanilla Linux 2.4 kernel.  To build, simply type "make" in
this directory.


##  Building applications

To build your own applications against Capriccio, simply link against
the static "lib/libpthread.a" library.  For examples, see the Makefiles
in the apss/* directories (eg apps/knot/Makefile). 

To use Capriccio with a dynamically linked executable, set the
LD_LIBRARY_PATH or LD_PRELOAD environment variables, as follows:

   LD_LIBRARY_PATH=/path/to/capriccio/src/lib /bin/ls
      _OR_
   LD_PRELOAD=/path/to/capriccio/src/lib/libpthread.so.0 /bin/ls

The former works if the executable was originally linked against
libthread; the later should work in any case.  Both have trouble with
symbol versions, and may not work with applications that are expecting
particular versions of standard library sybols to be defined.

Dynamic linking generally works better for GLIBC versions 2.2 and
older, although we have not verified this recently.  For GLIBC 2.3,
dynamic linking will correctly override calls made directly within the
running application, but will _not_ override all IO system calls
correctly.  The problem is that GLIBC 2.3's symbol versioning is set
up such that GLIBC internal functions (such as printf) always use the
internal versions of write(), etc., which hence bypasses Capriccio.
While applications will probably still run, one user-level thread
doing IO may end up blocking all others.


##  Runtime options

Capriccio includes a number of parameters that can be chosen at
runtime, including the asynchronous IO mechanisms and the scheduling
algorithm.  These are controlled through environment variables.  For a
list of which environment variables are available, see util/config.c.  


##  Caveats

The source code in this CD is a snapshot of our working development
repository, and as such, not all things are working.  For example,
some recent changes we have made have introduced bugs into the
resource-aware scheduler.  Additionally, the compile-time stack
analysis is not well integrated with our current makefiles, so hand
configuration is required to include it.  We are actively working on
these and other issues, so check the web site for a source update!



Best regards,

-Rob von Behren
 August 17, 2003
 
 `Last edited 2014-05-17`
 

