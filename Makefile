CC  	= gcc
CCLIBS	= -lGL -lGLU -lglut -lSOIL
CFLAGS	= -lm
PROGRAM	= copyCrash
OBJ 	= 		 	 \
	main.o  	 	 \
	Calbacks.o	 	 \
	Draw_elements.o  	 \
	Check.o			 \
	
	
VPATH 	= src


%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(PROGRAM): $(OBJ)
	$(CC) -o $@ $^ $(CCLIBS) $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o $(PROGRAM)
