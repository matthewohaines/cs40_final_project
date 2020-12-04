EXECS = simulation
OBJS = Simulation.o Animator.o VehicleBase.o Section.o Intersection.o Lane.o TrafficLight.o Vehicle.o Sim.o

#### use next two lines for Mac
# CC = clang++
# CCFLAGS = -std=c++17 -stdlib=libc++

#### use next two lines for mathcs* machines:
CC = g++
CCFLAGS = -std=c++17 -Wall -g

all: $(EXECS)

simulation: $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

%.o: %.cpp *.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<

clean:
	/bin/rm -f a.out $(OBJS) $(EXECS)
