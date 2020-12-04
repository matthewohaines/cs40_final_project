EXECS = simulation
OBJS = Simulation.o Section.o Intersection.o Lane.o VehicleBase.o TrafficLight.o Vehicle.o Sim.o Animator.o


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
