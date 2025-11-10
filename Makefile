CC = clang++
CFLAGS = 
3rd_INC_PATH = -I./3rd/lib1/inc -I./3rd/asio_1.36.0/include
3rd_LIB_PATH = -L./3rd/lib1/lib
3rd_LIB = -lcalcu -lws2_32 -lmswsock
INC_PATH = -I./ -I./Protocol $(3rd_INC_PATH)
LIB_PATH = $(3rd_LIB_PATH)
LIB = $(3rd_LIB)

preDef = _Litening_

ifndef CFG
CFG=Release
endif
ifeq "$(CFG)" "Debug"
CFLAGS = -g
OUTDIR = Debug
endif
ifeq "$(CFG)" "Release"
CFLAGS = -O3
OUTDIR = Release
endif

OUTFILE=$(OUTDIR)/main


SRC = $(wildcard ./*.cpp Protocol/*.cpp)
OBJ = $(patsubst %.cpp, $(OUTDIR)/%.o, $(notdir $(SRC)))

COMPILE=$(CC) $(CFLAGS) -c -D$(preDef) -o $(OUTDIR)/$(*F).o $(INC_PATH) $<
LINK=$(CC) $(CFLAGS) -o $(OUTFILE) $(OBJ) $(LIB_PATH) $(LIB)

$(OUTDIR)/%.o : %.cpp
	$(COMPILE)

$(OUTDIR)/%.o : Protocol/%.cpp
	$(COMPILE)



all: $(OUTFILE)
$(OUTFILE): $(OUTDIR) $(OBJ)
	$(LINK)

$(OUTDIR):
	mkdir "$(OUTDIR)"

.PHONY: check
check:
	@echo "OBJ:"$(OBJ)

.PHONY: clean
clean:
	del *.exe *.o




#main: main.o func.o
#	$(CC) $(CFLAGS) $(3rd_INC_PATH) -o main main.o func.o $(3rd_PATH) $(3rd_LIB)
#main.o: main.cpp
#	$(CC) $(CFLAGS) $(3rd_INC_PATH) -c main.cpp
#func.o: func.cpp
#	$(CC) $(CFLAGS) -c func.cpp