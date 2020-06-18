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

enum class CharacterState
{
  Standing,
  Running,
  Jumping,
  Ducking,
};

CharacterState characterState = CharacterState::Standing;

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
      break;
  }
  arduboy.display();

}


void Standing()
{
  arduboy.print(F("Standing"));
}

void Running()
{
  arduboy.print(F("Running"));
}

void Jumping()
{
  arduboy.print(F("Jumping"));
}

void Ducking()
{
  arduboy.print(F("Ducking"));
}

void CharacterInput()
{
  if(arduboy.pressed(UP_BUTTON)) {
    Jumping();
  } else if (arduboy.pressed(DOWN_BUTTON)) {
    if (!c_jump) {
      Ducking();
    }
  } else if (arduboy.pressed(RIGHT_BUTTON)|| arduboy.pressed(LEFT_BUTTON)) {
    if (!c_jump) {
      Running();
    }
  } else {
    Standing();
  }
}
