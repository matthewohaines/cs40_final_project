To compile the code, enter the directory using cd <directoryName>
Type make
To run: ./simulation [input file] [intitial seed]

The most important design decision we had to make were involving Section class and Intersection class. Those two classes are at the center of the simulation. It made the most sense to make Intersection a child class of Section, because Intersection should contain all that Section contains, with a few additions and changes.

One of the most challenging parts was to implement spawning of the vehicles when only one section is available. We tried to implement the check in the move method, that would check if the Vehicle occupies the correct number of Sections, but we found this to be hard.
Instead we decided that making 4 extra Sections was the most efficient way. 

We created a class Vehicle that is a child class of VehicleBase. This approach is perhaps not the best, as we could just added what is needed to VehicleBase. It would be easier to have just one class handling the Vehicles. However, having a seperate class made the code less messy. 



