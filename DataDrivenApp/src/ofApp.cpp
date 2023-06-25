#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    //API Docs available at: https://www.thecocktaildb.com/api.php?ref=apilist.fun
    json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=0");//returns old fashioned
   // cout << json.getRawString() << endl;

    state = States::MENU; //set initial app state to menu
    search = Searches::NEUTRAL; //set searches to neutral

   //set coordinates for button rectangles
    libraryBTN.set(ofGetWidth() / 2 - 100, 200, 200, 50);
    randomBTN.set(ofGetWidth() / 2 - 100, 600, 200, 50);
    homeBTN.set(ofGetWidth() - 80, 20, 50, 50);
    prevBTN.set(30, ofGetHeight() - 70, 50, 50);
    nextBTN.set(ofGetWidth() - 80, ofGetHeight() - 70, 50, 50);
    backBTN.set(30, 20, 50, 50);

    aBTN.set((ofGetWidth() / 8) * 1.5, (ofGetHeight() / 18) * 3, 50, 50);
    eBTN.set((ofGetWidth() / 8) * 1.5, (ofGetHeight() / 18) * 4.75, 50, 50);
    iBTN.set((ofGetWidth() / 8) * 1.5, (ofGetHeight() / 18) * 6.5, 50, 50);
    mBTN.set((ofGetWidth() / 8) * 1.5, (ofGetHeight() / 18) * 8.25, 50, 50);
    qBTN.set((ofGetWidth() / 8) * 1.5, (ofGetHeight() / 18) * 10, 50, 50);
    uBTN.set((ofGetWidth() / 8) * 1.5, (ofGetHeight() / 18) * 11.75, 50, 50);
    yBTN.set((ofGetWidth() / 8) * 1.5, (ofGetHeight() / 18) * 13.5, 50, 50);
    threeBTN.set((ofGetWidth() / 8) * 1.5, (ofGetHeight() / 18) * 15.25, 50, 50);
    sevenBTN.set((ofGetWidth() / 8) * 1.5, (ofGetHeight() / 18) * 17, 50, 50); //set coordinates for the first column of alphabet

    bBTN.set((ofGetWidth() / 8) * 3, (ofGetHeight() / 18) * 3, 50, 50);
    fBTN.set((ofGetWidth() / 8) * 3, (ofGetHeight() / 18) * 4.75, 50, 50);
    jBTN.set((ofGetWidth() / 8) * 3, (ofGetHeight() / 18) * 6.5, 50, 50);
    nBTN.set((ofGetWidth() / 8) * 3, (ofGetHeight() / 18) * 8.25, 50, 50);
    rBTN.set((ofGetWidth() / 8) * 3, (ofGetHeight() / 18) * 10, 50, 50);
    vBTN.set((ofGetWidth() / 8) * 3, (ofGetHeight() / 18) * 11.75, 50, 50);
    zBTN.set((ofGetWidth() / 8) * 3, (ofGetHeight() / 18) * 13.5, 50, 50);
    fourBTN.set((ofGetWidth() / 8) * 3, (ofGetHeight() / 18) * 15.25, 50, 50);
    nineBTN.set((ofGetWidth() / 8) * 3, (ofGetHeight() / 18) * 17, 50, 50);

    cBTN.set((ofGetWidth() / 8) * 4.5, (ofGetHeight() / 18) * 3, 50, 50);
    gBTN.set((ofGetWidth() / 8) * 4.5, (ofGetHeight() / 18) * 4.75, 50, 50);
    kBTN.set((ofGetWidth() / 8) * 4.5, (ofGetHeight() / 18) * 6.5, 50, 50);
    oBTN.set((ofGetWidth() / 8) * 4.5, (ofGetHeight() / 18) * 8.25, 50, 50);
    sBTN.set((ofGetWidth() / 8) * 4.5, (ofGetHeight() / 18) * 10, 50, 50);
    wBTN.set((ofGetWidth() / 8) * 4.5, (ofGetHeight() / 18) * 11.75, 50, 50);
    oneBTN.set((ofGetWidth() / 8) * 4.5, (ofGetHeight() / 18) * 13.5, 50, 50);
    fiveBTN.set((ofGetWidth() / 8) * 4.5, (ofGetHeight() / 18) * 15.25, 50, 50); //set coords for third column

    dBTN.set((ofGetWidth() / 8) * 6, (ofGetHeight() / 18) * 3, 50, 50);
    hBTN.set((ofGetWidth() / 8) * 6, (ofGetHeight() / 18) * 4.75, 50, 50);
    lBTN.set((ofGetWidth() / 8) * 6, (ofGetHeight() / 18) * 6.5, 50, 50);
    pBTN.set((ofGetWidth() / 8) * 6, (ofGetHeight() / 18) * 8.25, 50, 50);
    tBTN.set((ofGetWidth() / 8) * 6, (ofGetHeight() / 18) * 10, 50, 50);
    xBTN.set((ofGetWidth() / 8) * 6, (ofGetHeight() / 18) * 11.75, 50, 50);
    twoBTN.set((ofGetWidth() / 8) * 6, (ofGetHeight() / 18) * 13.5, 50, 50);
    sixBTN.set((ofGetWidth() / 8) * 6, (ofGetHeight() / 18) * 15.25, 50, 50);
    
    //load image files
    homeImg.load("home.png");
    leftImg.load("left.png");
    rightImg.load("right.png");

    //load font files
    mainFont.load("font.otf", 12);
    subFont.load("sub.otf", 17);
    headFont.load("header.ttf", 22);
    homeFont.load("header.ttf", 30);

    page = 0;//set current page - used to access array index
    ofBackground(164, 165, 174); //set background colour
}


void ofApp::getData() {
    page = 0;//reset page variable

    //check current state and open relevant API url
    if (state == States::ALPH) { //if the state is the alphabet
        if (search == Searches::A) { //if the a button is pressed
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=a");//search all cocktails beginning with
        }
        else if (search == Searches::B) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=b");
        }
        else if (search == Searches::C) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=c");
            state = States::LIBRARY;
        }
        else if (search == Searches::D) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=d");
            state = States::LIBRARY;
        }
        else if (search == Searches::E) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=e");
            state = States::LIBRARY;
        }
        else if (search == Searches::F) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=f");
            state = States::LIBRARY;
        }
        else if (search == Searches::G) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=g");
            state = States::LIBRARY;
        }
        else if (search == Searches::H) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=h");
            state = States::LIBRARY;
        }
        else if (search == Searches::I) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=i");
            state = States::LIBRARY;
        }
        else if (search == Searches::J) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=j");
            state = States::LIBRARY;
        }
        else if (search == Searches::K) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=k");
            state = States::LIBRARY;
        }
        else if (search == Searches::L) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=l");
            state = States::LIBRARY;
        }
        else if (search == Searches::M) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=m");
            state = States::LIBRARY;
        }
        else if (search == Searches::N) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=n");
            state = States::LIBRARY;
        }
        else if (search == Searches::O) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=o");
            state = States::LIBRARY;
        }
        else if (search == Searches::P) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=p");
            state = States::LIBRARY;
        }
        else if (search == Searches::Q) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=q");
            state = States::LIBRARY;
        }
        else if (search == Searches::R) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=r");
            state = States::LIBRARY;
        }
        else if (search == Searches::S) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=s");
            state = States::LIBRARY;
        }
        else if (search == Searches::T) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=t");
            state = States::LIBRARY;
        }
        else if (search == Searches::U) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=u");
            state = States::LIBRARY;
        }
        else if (search == Searches::V) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=v");
            state = States::LIBRARY;
        }
        else if (search == Searches::W) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=w");
            state = States::LIBRARY;
        }
        else if (search == Searches::X) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=x");
            state = States::LIBRARY;
        }
        else if (search == Searches::Y) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=y");
            state = States::LIBRARY;
        }
        else if (search == Searches::Z) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=z");
            state = States::LIBRARY;
        }
        else if (search == Searches::ONE) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=1");
            state = States::LIBRARY;
        }
        else if (search == Searches::TWO) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=2");
            state = States::LIBRARY;
        }
        else if (search == Searches::THREE) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=3");
            state = States::LIBRARY;
        }
        else if (search == Searches::FOUR) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=4");
            state = States::LIBRARY;
        }
        else if (search == Searches::FIVE) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=5");
            state = States::LIBRARY;
        }
        else if (search == Searches::SIX) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=6");
            state = States::LIBRARY;
        }
        else if (search == Searches::SEVEN) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=7");
            state = States::LIBRARY;
        }
        else if (search == Searches::NINE) {
            json.open("https://www.thecocktaildb.com/api/json/v1/1/search.php?f=9");
            state = States::LIBRARY;
        }
    }

    if (state == States::RANDOM or state == States::MENU) {
        json.open("https://www.thecocktaildb.com/api/json/v1/1/random.php");
    }

    cout << json.getRawString() << endl; //so you know if what is output to app from console is correct
    getDrink(); //call the get drink function
}

void ofApp::getDrink() {
    x = 0;
    y = 0; //set to 0
    url = json["drinks"][page]["strDrinkThumb"].asString();//set image url
    name = json["drinks"][page]["strDrink"].asString();//set drink name
    alcoholic = json["drinks"][page]["strAlcoholic"].asString();//set if drink has alcohol
    category = json["drinks"][page]["strCategory"].asString();//set drink category
    glass = json["drinks"][page]["strGlass"].asString();//set drink glass
    ingredients = "";//reset ingredients ready to append new info
    measures = "";//reset measures ready to append new info
    //set the headers
    ingredients.append("Ingredients:\n");
    measures.append("Measures:\n");
    do {
        if (json["drinks"][page]["strIngredient1"].isNull()) {//checks if the string is null
        }
        else{//if not then appends the ingredient and the same measure
            ingredients.append(json["drinks"][page]["strIngredient1"].asString() + '\n');
            measures.append(json["drinks"][page]["strMeasure1"].asString() + '\n');
            x++;//for while loop
            y++;//used for spacing
        }

        if (json["drinks"][page]["strIngredient2"].isNull()) {//checks if the string is null
            x = 15;//if it is null then ends the while loop
        }
        else {//if not then appends the ingredient and the same measure
            ingredients.append(json["drinks"][page]["strIngredient2"].asString() + '\n');
            measures.append(json["drinks"][page]["strMeasure2"].asString() + '\n');
            x++;
            y++;
        }

        if (json["drinks"][page]["strIngredient3"].isNull()) {//checks if the string is null
            x = 15;
        }
        else {//if not then appends the ingredient and the same measure
            ingredients.append(json["drinks"][page]["strIngredient3"].asString() + '\n');
            measures.append(json["drinks"][page]["strMeasure3"].asString() + '\n');
            x++;
            y++;
        }

        if (json["drinks"][page]["strIngredient4"].isNull()) {//checks if the string is null
            x = 15;
        }
        else {//if not then appends the ingredient and the same measure
            ingredients.append(json["drinks"][page]["strIngredient4"].asString() + '\n');
            measures.append(json["drinks"][page]["strMeasure4"].asString() + '\n');
            x++;
            y++;
        }

        if (json["drinks"][page]["strIngredient5"].isNull()) {//checks if the string is null
            x = 15;
        }
        else {//if not then appends the ingredient and the same measure
            ingredients.append(json["drinks"][page]["strIngredient5"].asString() + '\n');
            measures.append(json["drinks"][page]["strMeasure5"].asString() + '\n');
            x++;
            y++;
        }

        if (json["drinks"][page]["strIngredient6"].isNull()) {//checks if the string is null
            x = 15;
        }
        else {//if not then appends the ingredient and the same measure
            ingredients.append(json["drinks"][page]["strIngredient6"].asString() + '\n');
            measures.append(json["drinks"][page]["strMeasure6"].asString() + '\n');
            x++;
            y++;
        }

        if (json["drinks"][page]["strIngredient7"].isNull()) {//checks if the string is null
            x = 15;
        }
        else {//if not then appends the ingredient and the same measure
            ingredients.append(json["drinks"][page]["strIngredient7"].asString() + '\n');
            measures.append(json["drinks"][page]["strMeasure7"].asString() + '\n');
            x++;
            y++;
        }

        if (json["drinks"][page]["strIngredient8"].isNull()) {//checks if the string is null
            x = 15;
        }
        else {//if not then appends the ingredient and the same measure
            ingredients.append(json["drinks"][page]["strIngredient8"].asString() + '\n');
            measures.append(json["drinks"][page]["strMeasure8"].asString() + '\n');
            x++;
            y++;
        }

        if (json["drinks"][page]["strIngredient9"].isNull()) {//checks if the string is null
            x = 15;
        }
        else {//if not then appends the ingredient and the same measure
            ingredients.append(json["drinks"][page]["strIngredient9"].asString() + '\n');
            measures.append(json["drinks"][page]["strMeasure9"].asString() + '\n');
            x++;
            y++;
        }

        if (json["drinks"][page]["strIngredient10"].isNull()) {//checks if the string is null
            x = 15;
        }
        else {//if not then appends the ingredient and the same measure
            ingredients.append(json["drinks"][page]["strIngredient10"].asString() + '\n');
            measures.append(json["drinks"][page]["strMeasure10"].asString() + '\n');
            x++;
            y++;
        }

        if (json["drinks"][page]["strIngredient11"].isNull()) {//checks if the string is null
            x = 15;
        }
        else {//if not then appends the ingredient and the same measure
            ingredients.append(json["drinks"][page]["strIngredient11"].asString() + '\n');
            measures.append(json["drinks"][page]["strMeasure11"].asString() + '\n');
            x++;
            y++;
        }

        if (json["drinks"][page]["strIngredient12"].isNull()) {//checks if the string is null
            x = 15;
        }
        else{//if not then appends the ingredient and the same measure
            ingredients.append(json["drinks"][page]["strIngredient12"].asString() + '\n');
            measures.append(json["drinks"][page]["strMeasure12"].asString() + '\n');
            x++;
            y++;
        }

        if (json["drinks"][page]["strIngredient13"].isNull()) {//checks if the string is null
            x = 15;
        }
        else {//if not then appends the ingredient and the same measure
            ingredients.append(json["drinks"][page]["strIngredient13"].asString() + '\n');
            measures.append(json["drinks"][page]["strMeasure13"].asString() + '\n');
            x++;
            y++;
        }

        if (json["drinks"][page]["strIngredient14"].isNull()) {//checks if the string is null
            x = 15;
        }
        else {//if not then appends the ingredient and the same measure
            ingredients.append(json["drinks"][page]["strIngredient14"].asString() + '\n');
            measures.append(json["drinks"][page]["strMeasure14"].asString() + '\n');
            x++;
            y++;
        }

        if (json["drinks"][page]["strIngredient15"].isNull()) {//checks if the string is null
            x = 15;
        }
        else {//if not then appends the ingredient and the same measure
            ingredients.append(json["drinks"][page]["strIngredient15"].asString() + '\n');
            measures.append(json["drinks"][page]["strMeasure15"].asString() + '\n');
            x++;
            y++;
        }
    }while (x < 15);

    y = y * 20;
    method = wrapString(json["drinks"][page]["strInstructions"].asString(), 380);//set description
    name[0] = toupper(name[0]);//set first character of drink name to upper case
    icon.load(url);//load drink image via image url set earlier*/
    if (state == States::ALPH) {//if the state is alpha
        state = States::LIBRARY;//set to library to display the drinks
    }
}


//--------------------------------------------------------------

void ofApp::printInfo() {
    ofSetColor(41, 77, 74);//set colour to dark blue
    headFont.drawString(name, ofGetWidth() / 2 - headFont.stringWidth(name) / 2, 120);//draw creature name to top middle of screen
    ofSetColor(255);//set colour to white (avoids tint on image)
    icon.draw(ofGetWidth() / 2 - 75, 150, 150, 150);//draw image icon to screen
    ofSetColor(164, 165, 174);//set colour to silver
    ofSetColor(41, 77, 74);
    headFont.drawString("Information", ofGetWidth() / 2 - headFont.stringWidth("Information") / 2, 350);//draw sub header
    ofSetLineWidth(3);//set line width
    ofDrawLine(10, 370, ofGetWidth() - 10, 370);//draw seperating line
    ofSetColor(101, 76, 79);
    mainFont.drawString("Alcoholic: " + alcoholic, 30, 400);//draw if alcoholic
    mainFont.drawString("Category: " + category, 30, 430);//draw category to screen
    mainFont.drawString("Glass: " + glass, 30, 460);//draw glass type to screen
    mainFont.drawString(ingredients, 30, 490);//draw ingredients to screen
    mainFont.drawString(measures, ofGetWidth() / 2, 490);//draw measures to screen
    mainFont.drawString("Instructions: \n" + method, 30, 510 + y);//draw method to screen

    homeImg.draw(homeBTN);//draw home icon

}


//--------------------------------------------------------------


void ofApp::draw() {

    if (state == States::MENU) {
        ofSetColor(255);//set colour to white to avoid tint
        getData();//calls the get data function
        icon.draw(ofGetWidth() / 2 - 150, ofGetHeight() /2 -150, 300, 300);//draw image icon to screen
        ofSetColor(164, 165, 174);//sets background colour to silver
        ofSetColor(41, 77, 74);//set colour to dark blue
        homeFont.drawString("Cocktail Library", ofGetWidth() / 2 - homeFont.stringWidth("Cocktail Library") / 2, 120);//draw title at top middle of screen
        ofDrawRectangle(libraryBTN);//draw rectangle based on libraryBTN coordinates
        ofDrawRectangle(randomBTN);//draw rectangle based on randomBTN coordinates

        ofSetColor(164, 165, 174);//set colour to silver

        //Draw button text, position values set to sit over button rectangles
        subFont.drawString("Library", ofGetWidth() / 2 - subFont.stringWidth("Library") / 2, 230);
        subFont.drawString("Random", ofGetWidth() / 2 - subFont.stringWidth("Random") / 2, 630);
    }

    else if (state == States::ALPH) {
        ofSetColor(101, 76, 79);//set colour to dark red
        headFont.drawString("Click on first letter \n of chosen cocktail", ofGetWidth() / 2 - headFont.stringWidth("Click on first letter \n of chosen cocktail") / 2, 100);

        ofDrawRectangle(aBTN);
        ofDrawRectangle(bBTN);
        ofDrawRectangle(cBTN);
        ofDrawRectangle(dBTN);
        ofDrawRectangle(eBTN);
        ofDrawRectangle(fBTN);
        ofDrawRectangle(gBTN);
        ofDrawRectangle(hBTN);
        ofDrawRectangle(iBTN);
        ofDrawRectangle(jBTN);
        ofDrawRectangle(kBTN);
        ofDrawRectangle(lBTN);
        ofDrawRectangle(mBTN);
        ofDrawRectangle(nBTN);
        ofDrawRectangle(oBTN);
        ofDrawRectangle(pBTN);
        ofDrawRectangle(qBTN);
        ofDrawRectangle(rBTN);
        ofDrawRectangle(sBTN);
        ofDrawRectangle(tBTN);
        ofDrawRectangle(uBTN);
        ofDrawRectangle(vBTN);
        ofDrawRectangle(wBTN);
        ofDrawRectangle(xBTN);
        ofDrawRectangle(yBTN);
        ofDrawRectangle(zBTN);
        ofDrawRectangle(oneBTN);
        ofDrawRectangle(twoBTN);
        ofDrawRectangle(threeBTN);
        ofDrawRectangle(fourBTN);
        ofDrawRectangle(fiveBTN);
        ofDrawRectangle(sixBTN);
        ofDrawRectangle(sevenBTN);
        ofDrawRectangle(nineBTN);//draw the alphabt buttons

        ofSetColor(255);//set font to white

        headFont.drawString("A", (ofGetWidth() / 8) * 1.5 + 18, (ofGetHeight() / 18) * 3 + 35);
        headFont.drawString("B", (ofGetWidth() / 8) * 3 + 18, (ofGetHeight() / 18) * 3 + 35);
        headFont.drawString("C", (ofGetWidth() / 8) * 4.5 + 18, (ofGetHeight() / 18) * 3 + 35);
        headFont.drawString("D", (ofGetWidth() / 8) * 6 + 18, (ofGetHeight() / 18) * 3 + 35);//draw first row of letters

        headFont.drawString("E", (ofGetWidth() / 8) * 1.5 + 18, (ofGetHeight() / 18) * 4.75 + 35);
        headFont.drawString("F", (ofGetWidth() / 8) * 3 + 18, (ofGetHeight() / 18) * 4.75 + 35);
        headFont.drawString("G", (ofGetWidth() / 8) * 4.5 + 18, (ofGetHeight() / 18) * 4.75 + 35);
        headFont.drawString("H", (ofGetWidth() / 8) * 6 + 19, (ofGetHeight() / 18) * 4.75 + 35);//draw second row of letters

        headFont.drawString("I", (ofGetWidth() / 8) * 1.5 + 18, (ofGetHeight() / 18) * 6.5 + 35);
        headFont.drawString("J", (ofGetWidth() / 8) * 3 + 18, (ofGetHeight() / 18) * 6.5 + 35);
        headFont.drawString("K", (ofGetWidth() / 8) * 4.5 + 18, (ofGetHeight() / 18) * 6.5 + 35);
        headFont.drawString("L", (ofGetWidth() / 8) * 6 + 18, (ofGetHeight() / 18) * 6.5 + 35);//draw third row of letters

        headFont.drawString("M", (ofGetWidth() / 8) * 1.5 + 18, (ofGetHeight() / 18) * 8.25 + 35);
        headFont.drawString("N", (ofGetWidth() / 8) * 3 + 18, (ofGetHeight() / 18) * 8.25 + 35);
        headFont.drawString("O", (ofGetWidth() / 8) * 4.5 + 18, (ofGetHeight() / 18) * 8.25 + 35);
        headFont.drawString("P", (ofGetWidth() / 8) * 6 + 18, (ofGetHeight() / 18) * 8.25 + 35);//draw fourth row of letters

        headFont.drawString("Q", (ofGetWidth() / 8) * 1.5 + 18, (ofGetHeight() / 18) * 10 + 35);
        headFont.drawString("R", (ofGetWidth() / 8) * 3 + 18, (ofGetHeight() / 18) * 10 + 35);
        headFont.drawString("S", (ofGetWidth() / 8) * 4.5 + 18, (ofGetHeight() / 18) * 10 + 35);
        headFont.drawString("T", (ofGetWidth() / 8) * 6 + 18, (ofGetHeight() / 18) * 10 + 35);//draw fifth row of letters

        headFont.drawString("U", (ofGetWidth() / 8) * 1.5 + 18, (ofGetHeight() / 18) * 11.75 + 35);
        headFont.drawString("V", (ofGetWidth() / 8) * 3 + 18, (ofGetHeight() / 18) * 11.75 + 35);
        headFont.drawString("W", (ofGetWidth() / 8) * 4.5 + 18, (ofGetHeight() / 18) * 11.75 + 35);
        headFont.drawString("X", (ofGetWidth() / 8) * 6 + 18, (ofGetHeight() / 18) * 11.75 + 35);//draw sixth row of letters

        headFont.drawString("Y", (ofGetWidth() / 8) * 1.5 + 18, (ofGetHeight() / 18) * 13.5 + 35);
        headFont.drawString("Z", (ofGetWidth() / 8) * 3 + 18, (ofGetHeight() / 18) * 13.5 + 35);
        headFont.drawString("1", (ofGetWidth() / 8) * 4.5 + 18, (ofGetHeight() / 18) * 13.5 + 35);
        headFont.drawString("2", (ofGetWidth() / 8) * 6 + 18, (ofGetHeight() / 18) * 13.5 + 35);//draw seventh row of letters

        headFont.drawString("3", (ofGetWidth() / 8) * 1.5 + 18, (ofGetHeight() / 18) * 15.25 + 35);
        headFont.drawString("4", (ofGetWidth() / 8) * 3 + 18, (ofGetHeight() / 18) * 15.25 + 35);
        headFont.drawString("5", (ofGetWidth() / 8) * 4.5 + 18, (ofGetHeight() / 18) * 15.25 + 35);
        headFont.drawString("6", (ofGetWidth() / 8) * 6 + 18, (ofGetHeight() / 18) * 15.25 + 35);//draw eigth row of letters

        headFont.drawString("7", (ofGetWidth() / 8) * 1.5 + 18, (ofGetHeight() / 18) * 17 + 35);
        headFont.drawString("9", (ofGetWidth() / 8) * 3 + 18, (ofGetHeight() / 18) * 17 + 35);//draw ninth row of letters

        homeImg.draw(homeBTN);//draw home icon

    }

    else if (state == States::LIBRARY) {
        ofSetColor(255);//set colour ot white
        leftImg.draw(prevBTN);//draw home icon
        rightImg.draw(nextBTN);//draw home icon
        leftImg.draw(backBTN);
        ofSetColor(50);//set colour to grey
        printInfo();//draw out drinks info
    }


    else if (state == States::RANDOM) {
        ofSetColor(255);//set colour to white
        printInfo();//draw out drinks info
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

    if (state == States::LIBRARY) {//if on library page
        //if left arrow key pressed and not on first page
        if (key == OF_KEY_LEFT && page > 0) {
            page--; //decrease page value
            getDrink();//get new drink info
        }
        //if left arrow key pressed and not on last page
        if (key == OF_KEY_RIGHT && page < json["drinks"].size() - 1 ) {//as long as page is one smaller than drinks size
            page++;//increase page value
            getDrink();//get new cdrink info
        }
    }

    if (state == States::RANDOM) {//makes a new random cocktail
        if (key == OF_KEY_RIGHT) {
            state = States::RANDOM;//set state to RANDOM
            getData();//run function which calls API
        }
    }

}

//-----------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

    if (state == States::MENU) {
        if (libraryBTN.inside(x, y)) {
            state = States::ALPH;//set state to ALPH
        }
        if (randomBTN.inside(x, y)) {
            state = States::RANDOM;//set state to RANDOM
            getData();//run function which calls API
        }
    }

    if (state == States::ALPH) {
        if (aBTN.inside(x, y)) {
            search = Searches::A;//sets search to A, etc
            getData();
        }
        else if (bBTN.inside(x, y)) {
            search = Searches::B;
            getData();
        }
        else if (cBTN.inside(x, y)) {
            search = Searches::C;
            getData();
        }
        else if (dBTN.inside(x, y)) {
            search = Searches::D;
            getData();
        }
        else if (eBTN.inside(x, y)) {
            search = Searches::E;
            getData();
        }
        else if (fBTN.inside(x, y)) {
            search = Searches::F;
            getData();
        }
        else if (gBTN.inside(x, y)) {
            search = Searches::G;
            getData();
        }
        else if (hBTN.inside(x, y)) {
            search = Searches::H;
            getData();
        }
        else if (iBTN.inside(x, y)) {
            search = Searches::I;
            getData();
        }
        else if (jBTN.inside(x, y)) {
            search = Searches::J;
            getData();
        }
        else if (kBTN.inside(x, y)) {
            search = Searches::K;
            getData();
        }
        else if (lBTN.inside(x, y)) {
            search = Searches::L;
            getData();
        }
        else if (mBTN.inside(x, y)) {
            search = Searches::M;
            getData();
        }
        else if (nBTN.inside(x, y)) {
            search = Searches::N;
            getData();
        }
        else if (oBTN.inside(x, y)) {
            search = Searches::O;
            getData();
        }
        else if (pBTN.inside(x, y)) {
            search = Searches::P;
            getData();
        }
        else if (qBTN.inside(x, y)) {
            search = Searches::Q;
            getData();
        }
        else if (rBTN.inside(x, y)) {
            search = Searches::R;
            getData();
        }
        else if (sBTN.inside(x, y)) {
            search = Searches::S;
            getData();
        }
        else if (tBTN.inside(x, y)) {
            search = Searches::T;
            getData();
        }
        else if (uBTN.inside(x, y)) {
            search = Searches::U;
            getData();
        }
        else if (vBTN.inside(x, y)) {
            search = Searches::V;
            getData();
        }
        else if (wBTN.inside(x, y)) {
            search = Searches::W;
            getData();
        }
        else if (xBTN.inside(x, y)) {
            search = Searches::X;
            getData();
        }
        else if (yBTN.inside(x, y)) {
            search = Searches::Y;
            getData();
        }
        else if (zBTN.inside(x, y)) {
            search = Searches::Z;
            getData();
        }
        else if (oneBTN.inside(x, y)) {
            search = Searches::ONE;
            getData();
        }
        else if (twoBTN.inside(x, y)) {
            search = Searches::TWO;
            getData();
        }
        else if (threeBTN.inside(x, y)) {
            search = Searches::THREE;
            getData();
        }
        else if (fourBTN.inside(x, y)) {
            search = Searches::FOUR;
            getData();
        }
        else if (fiveBTN.inside(x, y)) {
            search = Searches::FIVE;
            getData();
        }
        else if (sixBTN.inside(x, y)) {
            search = Searches::SIX;
            getData();
        }
        else if (sevenBTN.inside(x, y)) {
            search = Searches::SEVEN;
            getData();
        }
        else if (nineBTN.inside(x, y)) {
            search = Searches::NINE;
            getData();
        }
        else if (homeBTN.inside(x, y)) {
            state = States::MENU;//set state to MENU
            search = Searches::NEUTRAL;
        }
    }

    if (state == States::LIBRARY) {
        if (prevBTN.inside(x, y) && page > 0) {//if prev button clicked and not first page
            page--;//decrease page value
            getDrink();//get new drinks info
        }
        if (nextBTN.inside(x, y) && page < json["drinks"].size() -1) {
            page++;//increase page value
            getDrink();//get new drinks info
        }
        if (homeBTN.inside(x, y)) {
            state = States::MENU;//set state to MENU
            search = Searches::NEUTRAL;//set search to neutral
        }
        if (backBTN.inside(x, y)) {
            state = States::ALPH;
            search = Searches::NEUTRAL;
        }
    }

    if (state == States::RANDOM) {
        if (homeBTN.inside(x, y)) {
            state = States::MENU;//set state to MENU
        }
    }
        /*
         If not on menu screen check for clicks on prev, next or home buttons
         Perform appropriate actions depending which button is pressed
         */
}

//--------------------------------------------------------------

string ofApp::wrapString(string text, int width) {
    string typeWrapped = "";
    string tempString = "";
    vector <string> words = ofSplitString(text, " "); //create vector full of individual words in string passed in

    for (int i = 0; i < words.size(); i++) { //run through vector
        string wrd = words[i]; //get current word in vector

        // if we aren't on the first word, add a space
        if (i > 0) {
            tempString += " ";
        }
        tempString += wrd; //add current word to temp string

        int stringwidth = mainFont.stringWidth(tempString); //set string width to length of line

        if (stringwidth >= width) {//check string with to add either space or new line before current word
            typeWrapped += "\n"; //if line is now longer than desired width add a new line
            tempString = wrd; // make sure we're including the extra word on the next line
        }
        else if (i > 0) {
            typeWrapped += " "; // if we aren't on the first word, add a space
        }
        typeWrapped += wrd; //add current word to string to be returned with new lines for wrapping
    }

    return typeWrapped;

}
