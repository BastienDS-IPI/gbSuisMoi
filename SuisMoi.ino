#include <Gamebuino-Meta.h>

int ordreTouches [30];
int score = 0;
int tour = 0;
int inst = 0;
bool modeInstruction = true; // true si mode Instruction et false si mode JEU pendant lequel le joueur peut saisir les touches
const int duree = 200;
const int dureeInstruction = 1000;
bool bienJoue = true;
const int toucheHAUT = 1;
const int toucheDROITE = 2;
const int toucheBAS = 3;
const int toucheGAUCHE = 4;
const int toucheMENU = 10;

int touche;



void setup() {
  gb.begin();
  ordreTouches[score]= random(1,5); // entre 1 et 4 pour savoir quele touche doit être appuyée en premier
}

void loop() {
  while (!gb.update());
  gb.display.clear();
  gb.lights.fill(BLACK);

  if (modeInstruction) {
    // AFFICHE DEFI //
    if ( inst <= score ) {
      gb.display.setCursor(5,20);
      gb.display.setColor(ORANGE);
      gb.display.print("Instructions");
      afficheTouche(ordreTouches[inst],dureeInstruction);
      inst++;
      if (inst > score) {
        inst = 0;
        modeInstruction = false;
      }
    }
  } else { //modeJEU
    // ENTREES //
    touche = 0;
    if (gb.buttons.released(BUTTON_MENU)) {
      gb.sound.playCancel();
      touche = toucheMENU;
      if (bienJoue == false) {
        // Redémarre le jeu
        bienJoue = true;
        modeInstruction = true;
        score = 0;
        ordreTouches[score]=random(1,5);
      }
    } else {
      if (gb.buttons.released(BUTTON_UP)){
        touche = toucheHAUT;
      } else if (gb.buttons.released(BUTTON_RIGHT)){
        touche = toucheDROITE;
      } else if (gb.buttons.released(BUTTON_DOWN)){
        touche = toucheBAS;
      } else if (gb.buttons.released(BUTTON_LEFT)){
        touche = toucheGAUCHE;
      }
      if (touche != 0) {
        afficheTouche(touche, duree);
        if (touche != ordreTouches[tour]) {
          // la touche appuyée n'est pas la bonnne
          bienJoue = false;
          gb.sound.playOK();
          gb.display.setCursor(25,20);
          gb.display.setColor(WHITE);
          gb.display.print("PERDU ");
          gb.display.print(score);
          gb.lights.fill(WHITE);
          delay (dureeInstruction * 2);
        } else {
          if (tour < score) {
            // la bonne touche est appuyée, il en reste dans les touches déjà montrées, on passe à la suivante
            tour++;  
          } else {
            // on ajoute une touche dans la série
            score++;
            ordreTouches[score]=random(1,5);
            tour = 0;
            modeInstruction = true;
          }
        }
      }
    }
  }
    

  // LOGIQUE //
  
/*
  
  // DESSIN //
  gb.display.setColor(ORANGE);
  gb.display.fillRect(0, 0, counter, gb.display.height());
  gb.display.setColor(GREEN);
  gb.display.setFontSize(3);
  gb.display.setCursor((gb.display.width()-3)/2,(gb.display.height()-2)/2);

  */
}
