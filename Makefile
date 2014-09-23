# Makefile para aplicacion "lista"
CFLAGS	=
CC	= gcc
OBJS	= filetree.o   

filetree:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@

filetree.o:	filetree.c  
		$(CC) $(CFLAGS) -c filetree.c

clean:
		/bin/rm *.o filetree
