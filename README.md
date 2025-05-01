experiments with userland access to display register in 211BSD / PiDP11

1. an extension to 'mem'
   This adds a new minor device to mem allowing word-sized access to the display / switch register.
   Access to new entry in /dev/csw can be controlled like any other file.
   Unlike /dev/mem /dev/csw is writable in multiuser ( / securelevel -1 ) 

   install by copying the files over,  
   copy mem.patch to /tmp  
   patch -p0 < /tmp/mem.patch  
   mknod /dev/csw c 1 4  
   <chmod to however you want to allow r/w access)  
   cd /sys/PIDP11  
   make  
   observer any build errors and fix them...   
   <make backup of your existing kernel .. cp /unix /unix.old;cp /netnix /netnix.old>  
   make install  
   reboot  

   see mem-csw.c for an example.

   
   
