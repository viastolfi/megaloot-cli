# Megaloot-cli

Megaloot CLI is a CLI game inspired by megaloot __You should play the real game [here](https://store.steampowered.com/app/2440380/Megaloot/).__ 
Even if my game isn't a complete copy of it lot of menachic are inspired by it (and it's excellent so just buy it you won't regret I promise)

# Requirement 

You only need a C++ compiler of your choice

* g++

# Installation

To play megaloot-cli just follow those step 

```bash
git clone https://github.com/viastolfi/megaloot-cli.git
cd megaloot-cli
chmod +x build.sh
./build.sh
```

If you want to see a quick showcase of the different features of the game just run 

```bash
./build.sh dev
```

If you want to play the game interactively but without fancy menu and maybe unsafe part you can run

```bash
./build.sh loop
```

# How to play

The main purpose of the game is to go through all the stage of a dungeon by defeating the monster you could face. At each stage, you drop 4 new Equipement that have random rarity and stats depending on how far you are in the dungeon. \
You can only equip one equipment of each type (one weapon, one shield, ...) so you have to choose wisely what you want to equip because you can't change after you the next stage ! \
After clearing a stage, you will be granted of 4 new equipment and you can change your loadout for the new one. \
Game is finished after you reached stage 100 (could change later on) \

__I have lot of other idea that I may introduce later but let's do things in the right order for once__

Currently, the game is only playable in loop mode which is a bit less cooler that the final gameplay that I want to include.

But you can still play it like that :

- Start the game using the command wrote earlier
- To choose what equipment to equip just write the place of it in your inventory. The Item on the top is number '0' then '1' ...
- When you are ready for next stage write 'q'
- To attack ennemies, write 'f' or 'b' depending if you want to attack ennemies on the front or the back line and then write the number of it. For example top ennemy of the back line -> 'b', '0'


# Author 

This project is entirely made by me (ASTOLFI Vincent). I suggest you to check on my github profile if you want to see the other project I've done for my studies or the ones I do in my free time.
