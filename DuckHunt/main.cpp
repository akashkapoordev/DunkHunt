#include <SFML/Graphics.hpp>
#include "../../Header/GameService/GameService.h"

using namespace GameService;

int main()
{
    GameServce* game_service = new GameServce();

    game_service->ignite();
    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    } 

    return 0;
}
