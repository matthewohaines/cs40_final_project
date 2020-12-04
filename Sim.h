#ifndef __SIM_H__
#define __SIM_H__

#include "Animator.h"
#include "Section.h"
#include "Intersection.h"
#include "Lane.h"
#include "TrafficLight.h"
#include "Vehicle.h"
#include <string>
#include <vector>

class Sim{
    private:  
        std::string fileName;
        int seed;       

        int maximum_simulated_time;                       
        int number_of_sections_before_intersection;    
        int green_north_south;                       
        int yellow_north_south;   
        int red_north_south;                  
        int green_east_west;                       
        int yellow_east_west;   
        int red_east_west;                 
        double prob_new_vehicle_northbound;          
        double prob_new_vehicle_southbound;            
        double prob_new_vehicle_eastbound;            
        double prob_new_vehicle_westbound;        
        double proportion_of_cars;         
        double proportion_of_SUVs;          
        double proportion_of_trucks;           
        double proportion_of_right_turn_cars; 
        double proportion_of_left_turn_cars;             
        double proportion_of_right_turn_SUVs;
        double proportion_of_left_turn_SUVs;             
        double proportion_of_right_turn_trucks;    
        double proportion_of_left_turn_trucks; 

        std::vector<Vehicle *> vehicleVector; 


        void createVehicle(Lane *lane, double laneProb, double createProb, double vehicleProb, double turnProb);          
        void move();                                     

    public:
        Sim() {}
        Sim(std::string file, int seed);
        ~Sim();
        void simulate(); 
};

#endif
