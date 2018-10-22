#include "mapFileReader.h"
#include <fstream>
#include <stdio.h>
//This file basically exists for the function which
//involves reading the text file
//ultimately, our text file will probably be encrypted
//that being said, for now I will make the foundation on the basis of a
//simple text file format and adjust it as it becomes more complex

//the parameter is the number of the map indicating which map file is being read
public void mapFileReader::readTextFile( int mapNumber ){
    std::string mapToRead = "mapNumber" + mapNumber + ".txt";
    ifstream fp(mapToRead);

if (! fp) {
    cout << "Error, file couldn't be opened" << endl;
    return 1;
}

    int x;
    int y;
    int ArrayToBeMade [x][y];

for(int row = 0; row < 9; row++) {  // stop loops if nothing to read
   for(int column = 0; column < 9; column++){
        fp >> Sudoku[row][column];
        if ( ! fp ) {
           cout << "Error reading file for element " << row << "," << col << endl;
           return 1;
        }
    }
}


    //
        //for (int i = 0; i < length of the first part of the 2D array; i++) {
            //for (int j = 0; j < length of the first part of the 2D array; j++) {
                //tileObject = TileFactory( collectionOfTiles[i][j], i, j);
                //tileObject.renderTile();
            //}
        //}
        //this next line is probably fp.close();
    in.close();
    return;
}
