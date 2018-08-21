cmake_minimum_required(VERSION 2.8 FATAL_ERROR)



add_library(ApplicationScripts "")

target_sources(ApplicationScripts
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/Aircraft.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Buildings.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/BuildingsMute.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Detenshn.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/EnemyAI.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Infantry.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/MachineShop.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/MainMenu.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Mission.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Projectiles.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Scar.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Schrap.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Towers.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Upgrade.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/Vehicles.cpp"
)
