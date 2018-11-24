#include "Map/MapGenerator.h"
#include <iostream>
#include <fstream>
using namespace std;



int MapGenerator::determineColumns(int mapID)
{

    int number_of_columns = 0;
    std::string mapNum = std::to_string(mapID);
    std::string mapToRead = "assets/maps/mapNumber" + mapNum + ".txt";
    std::ifstream myfile(mapToRead);
    std::string sLine;
    getline(myfile, sLine);
    ///this next set of lines is potentially buggy: it actually only counts the number of spaces and adds one
    ///this will be a liability later
    //for( int iLoop( 0 ); iLoop < ( sizeof( sLine ) / sizeof( sLine[ 0 ] ) ); iLoop++ )
    //if( sLine[ iLoop ] == ' ' ){
    //number_of_columns++;

    //}
    //number_of_columns++;
    istringstream ss(sLine);
    int num;
    while(ss >> num)
    {
        number_of_columns++;
    }

    ///
    return number_of_columns;
}

int MapGenerator::determineRows(int mapID)
{
    int number_of_lines = 0;
    std::string line;
    std::string mapNum = std::to_string(mapID);
    std::string mapToRead = "assets/maps/mapNumber" + mapNum + ".txt";
    std::ifstream myfile(mapToRead);
    while (!myfile.eof())
    {
        std::getline(myfile,line);
        number_of_lines++;
    }
    return number_of_lines;
}
