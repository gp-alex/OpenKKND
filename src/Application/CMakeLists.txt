cmake_minimum_required(VERSION 2.8 FATAL_ERROR)


set(APPLICATION_SOURCES
	Game.cpp
	GameFactory.cpp
	GameConfig.cpp
    GameConfigFactory.cpp
	Scripts/Aircraft.cpp
	Scripts/Buildings.cpp
	Scripts/BuildingsMute.cpp
	Scripts/Detenshn.cpp
	Scripts/EnemyAI.cpp
	Scripts/Infantry.cpp
	Scripts/MainMenu.cpp
	Scripts/Mission.cpp
	Scripts/Projectiles.cpp
	Scripts/Scar.cpp
	Scripts/Schrap.cpp
	Scripts/Towers.cpp
	Scripts/Upgrade.cpp
	Scripts/Vehicles.cpp
)

set(APPLICATION_HEADERS
	Game.h
	GameConfig.h
    GameConfigFactory.h
	GameFactory.h
)


add_library(Application STATIC ${APPLICATION_SOURCES} ${APPLICATION_HEADERS})
