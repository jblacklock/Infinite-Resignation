#include "Map.h"
#include "TileFactory.h"
#include "Tile.h"

    //a 2d array indicating the layout of tiles
    int collectionOfTiles[][];
    //the location of the camera on the x axis
    int cameraX;
    //the location of the camera on the y axis
    int cameraY;
    //I have questions about this member variable: It's in as per our UML diagram
    SDL_Texture mapTexture;

    //whatever function will end up reading the text files and calling the map constructor
    //will send in the 2d array of tiles as the argument, as well as the initial
    //x and y positions of the camera
    Map::Map( int parameterTiles[][], int camX, int camY )
    {
        collectionOfTiles = parameterTiles;
        cameraX = camX;
        cameraY = camY;
    }

    //This function will have the map rendered on the screen
    //This function is under construction
    void Map::renderMap()
    {
        //for (int i = 0; i < length of the first part of the 2D array; i++) {
            //for (int j = 0; j < length of the first part of the 2D array; j++) {
                //tileObject = TileFactory( collectionOfTiles[i][j], i, j);
                //tileObject.renderTile();
            //}
        //}
    }
