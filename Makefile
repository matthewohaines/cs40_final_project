EXECS = simulation
OBJS = Cars.o Intersection.o Lane.o Section.o simulation.o TrafficLight.o 

CC = g++
CCFLAGS = -std=c++17

all: $(EXECS)

Processor: $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

%.o: %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o: lab5/%.cpp lab5/%.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<

clean:
	/bin/rm -f a.out $(OBJS) $(EXECS)