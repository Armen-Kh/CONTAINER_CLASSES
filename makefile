#$(dir pwd)  is equal to "./"
#$(CURDIR) is equal to "/home/armen/Documents/CONTAINER_CLASSES"

SOURCES = $(wildcard Sources/*.cpp)
HEADERS = $(patsubst Sources/%.cpp,Headers/%.hpp, $(SOURCES))
OBJECTS = $(patsubst Sources/%.cpp,Object_Files/%.o, $(SOURCES))

TARGET = ./Bin/my_containers_demonstration.exe

$(TARGET) : $(OBJECTS)
        @mkdir -pv Bin
        g++ $^ -o $@ 
        
Object_Files/%.o : Sources/%.cpp
        @mkdir -pv Object_Files
        g++ -c $< -o $@  -I Headers



