cmake_minimum_required(VERSION 3.14)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp util/ArrayList/ArrayList.cpp util/ArrayList/ArrayList.h characters/Hero.cpp characters/Hero.h characters/DwarfWarrior.cpp characters/DwarfWarrior.h characters/MagicMan.cpp characters/MagicMan.h characters/ElfScout.cpp characters/ElfScout.h Player.cpp Player.h RealPlayer.cpp RealPlayer.h util/ReaderWrapper/ReaderWrapper.cpp util/ReaderWrapper/ReaderWrapper.h BotPlayer.cpp BotPlayer.h Game.cpp Game.h)