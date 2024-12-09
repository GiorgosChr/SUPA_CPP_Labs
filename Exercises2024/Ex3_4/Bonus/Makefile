CC=g++ #Name of compiler
FLAGS=-std=c++20 -w #Compiler flags (the s makes it silent)
TARGET=main #Executable name
OBJECTS=main.o CustomClass.o

#First target in Makefile is default
${TARGET}:${OBJECTS} #Make target from objects
	@echo "Linking..."
	${CC} ${FLAGS} ${OBJECTS} ${LIBS} -o ${TARGET}
	@make clean

main.o : main.cxx CustomClass.h
	${CC} ${FLAGS} ${LIBS} -c main.cxx

CustomClass.o : CustomClass.cxx CustomClass.h
	${CC} ${FLAGS} ${LIBS} -c CustomClass.cxx

clean: #No targets just run shell command to rm object files and emacs backups
	@rm -f *.o *~

cleantarget: #Delete the exectuable
	@rm -f ${TARGET}
