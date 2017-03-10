#include "GameInstance.h"
#include "MainMenu.h"
#include <memory>

int main()
{
	GameInstance FlyingBalloonGame = GameInstance(1200, 900, "FlyingBalloon");	
	FlyingBalloonGame.LoadGameScene(std::unique_ptr<MainMenu>(new MainMenu()));
	
    while (FlyingBalloonGame.IsWindowOpen())
    {
		FlyingBalloonGame.UpdateGame();
    }
	
    return 0;
}