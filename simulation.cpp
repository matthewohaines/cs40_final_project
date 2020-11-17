#include <iostream>
#include <fstream>
#include "TrafflicLane.h"
#include "Lane.h"
#include "Section.h"
#include "Intersection.h"
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    //checks if there are 3 command line arguments
    if (argc != 3)
    {
        //gives an error message if there are not 3 arguements
        std::cerr << "Usage: " << argv[0] << " [input file]" << " [initial seed value]" << std::endl;
        std::exit(1);
    }
    //reads argument 1 as an input file
    std::ifstream infile(argv[1]);
        
    //checks if file can be opened
    if (!infile.is_open())  // or: if (!infile)
    {
        //gives an error message if file cannot be opened
        std::cerr << "Error: could not open file: " << argv[1] << std::endl;
        std::exit(1);
    }
    //reads argument 2 as the initial seed
    int initialSeed;
    initialSeed = atoi(argv[2]);
     
    //Creates and initializes the variables to be read off the file
    int maximum_simulated_time = 0;
    int number_of_sections_before_intersection = 0;
    int green_north_south = 0;
    int yellow_north_south = 0;
    int green_east_west = 0;
    int yellow_east_west = 0;
    double prob_new_vehicle_northbound = 0;
    double prob_new_vehicle_southbound = 0;
    double prob_new_vehicle_eastbound = 0;
    double prob_new_vehicle_westbound = 0;
    double proportion_of_cars = 0;
    double proportion_of_SUVs = 0;
    double proportion_right_turn_cars = 0;
    double proportion_left_turn_cars = 0;
    double proportion_right_turn_SUVs = 0;
    double proportion_left_turn_SUVs = 0;
    double proportion_right_turn_trucks = 0;
    double proportion_left_turn_trucks = 0;
        
    //Creates and initializes vector that will store strings from infile
    std::string paramName;
    std::string paramValue;
    std::vector <std::string> paramValues;
        
        
    //Reads all of the strings and integers of each line
    while (infile >> paramName >> paramValue)
    {
        paramValues.push_back(paramValue);
    }
        
    if (infile.fail() && !infile.eof())
    {
        std::cerr << "Error: bad file format: " << argv[1] << std::endl;
        std::exit(1);
    }
        
    //closes the infile
    infile.close();
        
    maximum_simulated_time = stoi(paramValues[0]);
    number_of_sections_before_intersection = stoi(paramValues[1]);
    green_north_south = stoi(paramValues[2]);
    yellow_north_south = stoi(paramValues[3]);
    green_east_west = stoi(paramValues[4]);
    yellow_east_west = stoi(paramValues[5]);
    prob_new_vehicle_northbound = stod(paramValues[6]);
    prob_new_vehicle_southbound = stod(paramValues[7]);
    prob_new_vehicle_eastbound = stod(paramValues[8]);
    prob_new_vehicle_westbound = stod(paramValues[9]);
    proportion_of_cars = stod(paramValues[10]);
    proportion_of_SUVs = stod(paramValues[11]);
    proportion_right_turn_cars = stod(paramValues[12]);
    proportion_left_turn_cars = stod(paramValues[13]);
    proportion_right_turn_SUVs = stod(paramValues[14]);
    proportion_left_turn_SUVs = stod(paramValues[15]);
    proportion_right_turn_trucks = stod(paramValues[16]);
    proportion_left_turn_trucks = stod(paramValues[17]);
       
    return 0;
    
}   
