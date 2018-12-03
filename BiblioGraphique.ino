/* void allumeTouche (int touche) {
  
}*/

void afficheTouche (const int t, const int delai) {
  switch (t) {
    case toucheHAUT :
        gb.lights.drawPixel(0, 0, RED);
        gb.lights.drawPixel(1, 0, RED);
        gb.display.setCursor(20,5);
        gb.display.setColor(RED);
        gb.display.print("HAUT");
        break;
      case toucheDROITE :
        gb.lights.drawPixel(1, 1, BLUE);
        gb.lights.drawPixel(1, 2, BLUE);
        gb.display.setCursor(50,31);
        gb.display.setColor(BLUE);
        gb.display.print("DROITE");
        break;
      case toucheBAS :
        gb.lights.drawPixel(0, 3, YELLOW);
        gb.lights.drawPixel(1, 3, YELLOW);
        gb.display.setCursor(25,53);
        gb.display.setColor(YELLOW);
        gb.display.print("BAS");
        break;
      case toucheGAUCHE :
        gb.lights.drawPixel(0, 1, GREEN);
        gb.lights.drawPixel(0, 2, GREEN);
        gb.display.setCursor(5,31);
        gb.display.setColor(GREEN);
        gb.display.print("GAUCHE");
        break;
  }
  delay (delai) ;
}

