#include <Arduboy2.h>

Arduboy2 arduboy;

bool c_run;
bool c_stand;
bool c_jump;
bool c_duck;

enum class GameState
{
  Character,
};

GameState gameState = GameState::Character;

void reset()
{
  c_run = false;
  c_stand = true;
  c_jump = false;
  c_duck = false;
}

void setup() {
  arduboy.begin();
  arduboy.clear();
  reset();

}

void loop() {
  if(!arduboy.nextFrame()) {
    return;
  }
  arduboy.pollButtons();

  arduboy.clear();

  switch (gameState)
  {
    case GameState::Character:
      CharacterInput();
      CharacterDraw();
      break;
  }
  arduboy.display();

}

void CharacterDraw()
{
  arduboy.clear();
  arduboy.setCursor(0,0);
  
  if(c_stand == true) {
    arduboy.print(F("Standing"));
  }
  if(c_jump == true) {
    arduboy.print(F("Jumping"));
  }
  if(c_duck == true) {
    arduboy.print(F("Ducking"));
  }
  if(c_run == true) {
    arduboy.print(F("Running"));
  }
  arduboy.display();
}

void CharacterInput()
{
  if(arduboy.pressed(UP_BUTTON)) {
    c_jump = true;
    c_stand = false;
    c_duck = false;
    c_run = false;
  } else if (arduboy.pressed(DOWN_BUTTON)) {
    if (!c_jump) {
      c_duck = true;
      c_stand = false;
      c_run = false;
    }
  } else if (arduboy.pressed(RIGHT_BUTTON)|| arduboy.pressed(LEFT_BUTTON)) {
    if (!c_jump) {
      c_stand = false;
      c_run = true;
      c_jump = false;
      c_duck = false;
    }
  } else {
    c_stand = true;
    c_run = false;
    c_duck = false;
    c_jump = false;
  }
}
