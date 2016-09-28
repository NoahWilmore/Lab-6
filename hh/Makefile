AutomatedMakefile = am
CC = g++
CXXFLAGS = -Wno-deprecated-declarations -g -O0

PROJECT_PATH = $(CURRENT_DIR)
GUI_PATH = $(DRIVE_LETTER)/MinGW/wxWidgets-3.1.0

#INC_DIRS = -I$(CURRENT_DIR)/2111/CSC2110 -I$(CURRENT_DIR)/2111/GUI -I$(GUI_PATH)/include -I$(GUI_PATH)/lib/gcc510TDM_x64_dll/mswu
INC_DIRS = -I$(CURRENT_DIR)/2111/CSC2110 -I$(CURRENT_DIR)/2111/GUI -I$(GUI_PATH)/include -I$(GUI_PATH)/lib/gcc510TDM_x64_dll/mswud
LIB_DIRS = -L$(CURRENT_DIR)/2111/CSC2110 -L$(CURRENT_DIR)/2111/GUI -L$(GUI_PATH)/lib/gcc510TDM_x64_dll
LDFLAGS = -Wl,-Bstatic
#LIBS = $(LDFLAGS) -lCSC2110 -lrandom -lGUI -lwxmsw31u_core -lwxbase31u -lgdi32
LIBS = $(LDFLAGS) -lCSC2110 -lrandom -lGUI -lwxmsw31ud_core -lwxbase31ud -lgdi32

COMPILE = $(CC) $(CXXFLAGS) $(INC_DIRS) -c 
LINK = $(CC) $(CXXFLAGS) $(LIB_DIRS)
#LINK = $(CC) $(CXXFLAGS) $(LIB_DIRS) -o


FILES = MazeApp.o Cell.o Maze.o MazeGUI.o
EXECUTABLE = Lab06.exe

all: Lab06
	$(EXECUTABLE)

Lab06: 			$(FILES)
			$(LINK) $(FILES) $(LIBS) -o $(EXECUTABLE)

Cell.o:			Cell.h Cell.cpp
			$(COMPILE) Cell.cpp

Maze.o:			StackLinked.h Update.h Maze.h Maze.cpp
			$(COMPILE) Maze.cpp

MazeGUI.o:		MazeGUI.h MazeGUI.cpp
			$(COMPILE) MazeGUI.cpp

MazeApp.o:		MazeApp.cpp
			$(COMPILE) MazeApp.cpp





