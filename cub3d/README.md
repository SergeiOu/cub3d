*This project has been created as part of the 42 curriculum by sounania, mfassad.*

# cub3D

## Description

cub3D is a small 3D game engine written in C with the MiniLibX graphics
library. It renders a first-person view of a maze from a 2D map file
(`.cub`) using raycasting, the technique used by early games such as
Wolfenstein 3D.

What the program does:

- Parses a `.cub` scene file: four wall textures (`NO`, `SO`, `WE`, `EA`),
  floor (`F`) and ceiling (`C`) colors, and the map itself.
- Validates the scene: file extension, texture files, color ranges, a single
  player start, only valid map characters, and a map closed by walls.
- Opens a 1280x720 window and draws the maze with textured walls. Each wall
  side (north, south, east, west) uses its own texture.
- Lets the player walk and turn through the maze with collision against walls.
- Frees all memory and closes the window cleanly on ESC or on the window's
  close button.

How the rendering works: for every screen column a ray is cast from the player
through the map using the DDA algorithm until it hits a wall. The perpendicular
distance gives the wall height (no fisheye effect), and the exact hit position
selects the column of the texture to draw.

## Instructions

### Requirements

- Linux with X11
- `cc`, `make`
- X11 and BSD development headers (needed to build MiniLibX):
  `sudo apt install libx11-dev libxext-dev libbsd-dev`

### Build

```sh
make          # builds libft, minilibx-linux and the cub3D binary
make clean    # removes object files
make fclean   # removes object files and the binary
make re       # fclean + all
```

### Run

```sh
./cub3D maps/valid/valid_map.cub
```

### Controls

| Key | Action |
| --- | --- |
| `W` / `S` | move forward / backward |
| `A` / `D` | strafe left / right |
| `←` / `→` | turn left / right |
| `ESC` or window close button | quit |

### Map file format

```
NO ./textures/wall_blue_128.xpm
SO ./textures/wall_counter_128.xpm
WE ./textures/wall_shelf_128.xpm
EA ./textures/wall_star_128.xpm

F 220,100,0
C 225,30,0

111111
100001
10N001
100001
111111
```

- `NO`, `SO`, `WE`, `EA`: path to the `.xpm` texture for each wall side.
- `F` and `C`: floor and ceiling colors as `R,G,B`, each from 0 to 255.
- Map: `1` is a wall, `0` is empty floor, and `N`, `S`, `E` or `W` is the
  player's start position and facing direction. The map must be closed by
  walls, contain exactly one player, and come after the configuration lines.
  Spaces are allowed inside the map.

Test maps are in `maps/valid` (must open a window) and `maps/invalid` (must
print `Error` and a message, then exit with status 1).

## Resources

- Lode Vandevenne, *Raycasting* tutorial:
  https://lodev.org/cgtutor/raycasting.html
- 42 Docs, MiniLibX reference:
  https://harm-smits.github.io/42docs/libs/minilibx
- Wikipedia, *Ray casting* and *Digital differential analyzer (graphics
  algorithm)*.
- `man` pages for the allowed functions (`open`, `read`, `close`, `write`,
  `malloc`, `free`, math library).

### Use of AI

AI (Claude, through Claude Code) was used as a coding assistant on this
project. It was used for:

- integrating MiniLibX into the Makefile;
- writing the window and event handling, texture loading, player/camera setup,
  the raycasting and texture-sampling code, and player movement and collision;
- fixing Norm errors and writing the edge-case test maps;
- explaining the raycasting maths.

The configuration and map parsing (`src/parsing/`, `src/initialization/`) was
written by mfassad. [TEAM TO CONFIRM: state here whether AI was used for it.]

All AI-generated code was tested (valgrind, norminette, test maps).
[TEAM TO CONFIRM: both members have reviewed the AI-generated code and can
explain it.]
