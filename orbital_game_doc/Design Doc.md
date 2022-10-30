# Concept

A single player 2D space exploration game with realistic orbital mechanics. Explore planets, moons, and asteroids which all have different levels of difficulty to reach and land on.

## Inspiration

- Famicom Art:
"Execute daring gravity swings and ballistic maneuvers in CALLISTO, an orbital-mechanics action game set in the Jupiter system."
![](https://famicase.com/22/softs/047.jpg)

- Kerbal Space Program

- Outer Wilds

# Scope

Goal is to practice C++, as well as practice using common complex elements in game development such as physics and vectors. Start out simple by just implementing orbital mechanics, then a ship where you can control it's thrust vectors, then a landing/physics component, and finally building multiple planets for exploration.

# Requirements

- Basic C++
	- No Templates
	- Single Threaded
- Point Based Gravity(gravity pulls to specific points e.g planets)
	- Drawing Orbital Paths
- Single Player
- Controllable ship
	- Can use RCS to rotate
	- Controlling strength of thrust
- Planets/Moons/Asteroids
	- Limit to a single planet while testing/implementing physics
	- Floor collisions
- Ship Resources
	- Health(hitting planet too hard will explode)
	- Fuel?(limited RCS and thruster fuel)

# Gameplay

## Basic UI

Game will have a minimal UI showing both the map and the real view at the same time. When a player is far out in outer space then the game will have the map be in large view and the real view in ther corner. If the player is landing on a surface then the view will automatically switch to have the real view be primary and the map in the corner.

Player gets objectives to explore specific points in the solar system, and then gets rewarded with upgrades or points.

If fuel will be implemeneted, a small guage in the corner for thruster and rcs fuel.

Mockup: 
![](https://cdn.discordapp.com/attachments/196119285444116480/1036362238073778187/unknown.png)

![](https://cdn.discordapp.com/attachments/196119285444116480/1036362507910131802/unknown.png)

- Animated Mockup: https://cdn.discordapp.com/attachments/196119285444116480/1034929320109555752/orbital2.gif

## Controls

- Desktop:
	- Q/E to rotate
	- WASD for RCS
	- Shift/Ctrl for Thrust Control
- Mobile:
	- Hold left/right side of screen to rotate
	- Slide up/down in center for Thrust Control
	- Toggle for RCS?
		- Slide from center of screen in any direction to activate RCS for that direction.

## Gameplay
Explore

# Application Design

Game app will be made of multiple source and header files split up according to the following:

- Main(app entry point)
- Resources
	- Loads textures and any other files into our game. They will be referenced by a special ID.
- Physics
	- Does all orbital calculations and then eventually also will do collision resolution.
- State
	- Holds the state of the game world such as:
		- player position
		- planets and their positions
		- fuel
		- etc
- Drawing
	- Reads the state and then draws to the screen based on that
- Gameplay
	- Takes input from player and applies it to the state