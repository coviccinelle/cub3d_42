# 🎮 **cub3D** - _My First RayCaster with miniLibX_
[3D game coding in C] 

## Goals

This project aims to enhance fundamental programming skills, including rigor, C language proficiency, basic algorithms, and information research. As a graphic design project, cub3D provides an opportunity to improve skills in working with windows, colors, events, and shape filling. It serves as a playground to explore playful applications of mathematics without delving into the specifics.

## Common Instructions

- Project must be written in C.
- Adhere to the Norm. Bonus files/functions are included in the norm check.
- Functions should not quit unexpectedly; unexpected errors lead to a non-functional project.
- Properly free all heap-allocated memory space; no memory leaks tolerated.
- Submit a Makefile following specified rules.
- Create a separate bonus rule in the Makefile for bonus parts.
- Encouraged to create test programs, although they won't be graded.
- Submit work to the assigned git repository for grading.

## Mandatory Part - cub3D

### Program Details

- **Program Name:** cub3D
- **Turn in Files:** All your files
- **Makefile Rules:** all, clean, fclean, re, bonus
- **Arguments:** a map in the format *.cub

### External Functions Allowed

- `open`, `close`, `read`, `write`, `printf`, `malloc`, `free`, `perror`, `strerror`, `exit`
- All functions of the math library (`-lm man man 3 math`)
- All functions of the miniLibX

### Libft Authorized

Yes

### Description

Create a realistic 3D graphical representation of the inside of a maze from a first-person perspective using Ray-Casting principles. Use the miniLibX library for graphics.

### Constraints

- Use miniLibX version available on the operating system or from its sources.
- Smooth window management (changing, minimizing, etc.).
- Display different wall textures based on wall orientation (North, South, East, West).
- Set floor and ceiling colors.
- Implement keyboard controls for navigation and interaction.
- Parse a scene description file as the first argument.

### Scene Description File Format

- Map must be composed of 0 (empty space), 1 (wall), and N/S/E/W (player's start position).
- Map must be closed/surrounded by walls.
- Map parsing must handle various valid map formats.
- Define elements such as textures, floor color, ceiling color in the scene description file.

### Example Scene

![image](https://github.com/coviccinelle/cub3d_42/assets/51762886/bbbf116a-fae7-4e49-8008-0e41d9da4ae1)


### Error Handling

If any misconfiguration is encountered, the program must exit with an error message.

## Bonus Part

Bonuses will be evaluated only if the mandatory part is PERFECT. Bonus list includes features such as wall collisions, minimap system, doors, animated sprite, and rotating the point of view with the mouse.

Note: Prioritize a perfect mandatory part over spending excessive time on bonuses.

Feel free to modify the expected scene file format for bonus features. Be smart!


