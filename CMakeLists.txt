cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME .SFML_Template)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp StateName.h States.cpp States.h AssetName.h Assets.cpp Assets.h Button.cpp Button.h Card.cpp Card.h Deck.cpp Deck.h Node.h DoublyLinkedList.cpp DoublyLinkedList.h Stack.cpp Stack.h Queue.cpp Queue.h CardHand.cpp CardHand.h CardName.h GameScreenName.h GameScreen.cpp GameScreen.h DiscardPile.cpp DiscardPile.h OpponentHand.cpp OpponentHand.h ExplodingDickens.cpp ExplodingDickens.h Sounds.cpp Sounds.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.5.1)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#set(SFML_DIR C:/SFML/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML  REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()