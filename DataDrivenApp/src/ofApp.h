#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include <vector>

class ofApp : public ofBaseApp {

public:
	//functions
	void setup();
	void draw();

	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	
	//Custom functions
	//function which calls the API
	void getData();
	//function gets drink info
	void getDrink();
	//function returns a wrapped string to keep text on screen
	string ofApp::wrapString(string text, int width);
	string text, newText;
	void printInfo();
	

	//variables
	ofxJSONElement json;//stores data from API
	//rectangle objects used for clickable buttons
	ofRectangle libraryBTN, randomBTN, nextBTN, prevBTN, homeBTN, backBTN;
	ofRectangle aBTN, bBTN, cBTN, dBTN, eBTN, fBTN, gBTN, hBTN, iBTN, jBTN, kBTN, lBTN, mBTN, nBTN, oBTN, pBTN, qBTN, rBTN, sBTN, tBTN, uBTN, vBTN, wBTN, xBTN, yBTN, zBTN;
	ofRectangle oneBTN, twoBTN, threeBTN, fourBTN, fiveBTN, sixBTN, sevenBTN, nineBTN;
	//font objects for drawing text
	ofTrueTypeFont mainFont, headFont, subFont, homeFont;
	//enum handles the Apps state
	enum class States { MENU, ALPH, LIBRARY, RANDOM, NEUTRAL };
	States state;
	//enum handles the search function
	enum class Searches { NEUTRAL, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO };
	Searches search;

	string name, url, alcoholic, category, glass, ingredients, measures, method;
	//image objects for drawing images to screen
	ofImage icon, homeImg, leftImg, rightImg;
	//int and string variables to store key information
	int page, x, y;


};
