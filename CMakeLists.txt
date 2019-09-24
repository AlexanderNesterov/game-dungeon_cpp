cmake_minimum_required(VERSION 3.14)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp util/ArrayList/ArrayList.cpp util/ArrayList/ArrayList.h characters/hero/Hero.cpp characters/hero/Hero.h characters/dwarfwarrior/DwarfWarrior.cpp characters/dwarfwarrior/DwarfWarrior.h characters/magicman/MagicMan.cpp characters/magicman/MagicMan.h characters/elfscout/ElfScout.cpp characters/elfscout/ElfScout.h players/Player.cpp players/Player.h players/realplayer/RealPlayer.cpp players/realplayer/RealPlayer.h util/ReaderWrapper/ReaderWrapper.cpp util/ReaderWrapper/ReaderWrapper.h players/botplayer/BotPlayer.cpp players/botplayer/BotPlayer.h game/Game.cpp game/Game.h)