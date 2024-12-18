<h1 align="center">so_long</h1>

> Hive Helsinki (School 42) 6th curriculum project (Rank02)

<h2 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#program">Program</a>
	<span> · </span>
	<a href="#requirements">Requirements</a>
	<span> · </span>
	<a href="#instructions">Instructions</a>
	<span> · </span>
	<a href="#references">References</a>
</h2>

## About
The repository contains a program for lauchning a 2D top down game using functions from the MLX42 graphics library running on GLFW and OpenGL.

## Program
The player is able to move in 4 directions and can pick up collectibles. Once all collectibles are picked up, the game
can be exited via a special exit field. Collision detection is used in order to avoid that the player can go through walls.
The executable takes a .ber file as argument which contains the map of the game. The requirements for a valid map are:
- only one player ('P') present
- map must be closed by walls ('1')
- map must have open spaces ('0')
- at leat 1 collectible ('C)
- an exit ('E')

## Requirements
- `gcc` compiler
- `GLFW` library

## Instructions

### 1. Compiling the program

To compile the program, navigate into the repo folder and run:

```
$ make 
```

### 2. Start the game

Start the game by passing a valid .ber map file (see respective map folder) to the executable e.g.:
```
$ ./so_long valid.ber
```

### 3. Navigation within the game

```
W, A, S, D
```
or
```
⬅︎⬆︎⬇︎➡︎
```
All collectibles need to be picked up before the exit field is functional.
The game can be closed by hitting `ESC` or clicking on the `x` of the window.

## References
The MLX42 library was downloaded from the following repo: (https://github.com/codam-coding-college/MLX42)  
The sprites for player, collectibles, floor and walls where taken from: (https://itch.io)
