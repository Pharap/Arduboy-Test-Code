#include <Arduboy2.h>

Arduboy2 arduboy;

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

void setup()
{
  arduboy.begin();
}

void loop()
{
  if(!arduboy.nextFrame())
    return;
	
  arduboy.pollButtons();

  arduboy.clear();

  switch (gameState)
  {
    case GameState::Character:
      updateCharacter();
      drawCharacter();
      break;
  }
  
  arduboy.display();
}

void drawCharacter()
{
  switch(characterState)
  {
  case CharacterState::Standing:
    arduboy.print(F("Standing"));
    break;
    
  case CharacterState::Jumping:
    arduboy.print(F("Jumping"));
    break;
    
  case CharacterState::Ducking:
    arduboy.print(F("Ducking"));
    break;
    
  case CharacterState::Running:
    arduboy.print(F("Running"));
    break;
  }
}

void updateCharacter()
{
	switch(characterState)
	{
		case CharacterState::Standing:
			updateCharacterStanding();
			break;
			
		case CharacterState::Jumping:
			updateCharacterJumping();
			break;
			
		case CharacterState::Ducking:
			updateCharacterDucking();
			break;
			
		case CharacterState::Running:
			updateCharacterRunning();
			break;
	}
}

void updateCharacterStanding()
{
	// Handle input and such...
}

void updateCharacterJumping()
{
	// Handle input and such...
}

void updateCharacterDucking()
{
	// Handle input and such...
}

void updateCharacterRunning()
{
	// Handle input and such...
}
