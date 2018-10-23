#include "MapGenerator.h"
#include <iostream>
#include <fstream>
using namespace std;

//static Tile[][] generateMap(int mapID){}

        int MapGenerator::determineColumns(int mapID){
    int number_of_columns = 0;
    //std::string line;
    std::string mapNum = std::to_string(mapID);
    std::string mapToRead = "assets/maps/mapNumber" + mapNum + ".txt";
    std::ifstream myfile(mapToRead);
    std::string line;
    std::getline(myfile,line);
    stringstream ss(std::getline(myfile,line));      // Set up up a stream from this line
         while ( ss >> item ) number_of_lines++;  // Each item delineated by spaces adds one to cols
    //while (!myfile.eof()){
    //    std::getline(myfile,line);
    //    printf("%s/n",line);
    //    number_of_++;
    //}
    std::cout << "Number of columns in text file: " << number_of_lines;
    return number_of_columns;
        }

       int MapGenerator::determineRows(int mapID){
    int number_of_lines = 0;
    std::string line;
    std::string mapNum = std::to_string(mapID);
    std::string mapToRead = "assets/maps/mapNumber" + mapNum + ".txt";
    std::ifstream myfile(mapToRead);
    while (!myfile.eof()){
        std::getline(myfile,line);
        printf("%s/n",line);
        number_of_lines++;
    }
    std::cout << "Number of lines in text file: " << number_of_lines;
    return number_of_lines;
        }
