# Cub3D 🎲
![Autores](https://img.shields.io/badge/Autores-yasminefontenele%20%26%20EMcova-blue) 

Welcome to **cub3D**, a project inspired by the legendary game **Wolfenstein 3D**! This project is your opportunity to create a 3D graphical representation of a maze using **Ray-Casting** principles, implemented in C with the **MiniLibX** library. Dive into the world of game development and relive the history of first-person shooters.

---

## Table of Contents

1. [Introduction](#introduction)
2. [Goals](#goals)
3. [Features](#features)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Map Configuration](#map-configuration)
7. [Controls](#controls)

---

## Introduction

**Wolfenstein 3D**, developed by **John Carmack** and **John Romero** in 1992, is considered the first true "First-Person Shooter" (FPS) in the history of video games. It paved the way for iconic games like **Doom**, **Quake**, and **Duke Nukem 3D**.

In this project, **cub3D**, you will recreate a simplified version of this classic game using **Ray-Casting** techniques. To achieve this, we utilize **Bresenham's Algorithm** for efficient line drawing and rendering. The goal is to render a 3D maze from a first-person perspective, complete with textures, colors, and smooth controls.

---

## Bresenham's Algorithm 🌟

**Bresenham's Algorithm** is an efficient method for line rasterization, i.e., drawing straight lines on a pixel grid. Developed by **Jack Elton Bresenham** in 1962, it is widely used in computer graphics due to its simplicity and efficiency, using only integer calculations and avoiding floating-point operations.

### How It Works

The algorithm determines which pixels should be colored to form a line between two points \((x_0, y_0)\) and \((x_1, y_1)\). It works incrementally, calculating a decision parameter to choose the next pixel to be drawn.

### Advantages

- **Efficiency**: Uses only integer operations.
- **Simplicity**: Easy to implement.
- **Speed**: Ideal for hardware with limited resources.

### Applications

- Drawing lines on computer screens.
- Rendering in game graphics engines.
- Path tracing in CNC machines.
- Edge detection in image processing.

### Example Usage

To draw a line from point \((1, 1)\) to \((4, 3)\), the algorithm selects the pixels \((1, 1)\), \((2, 2)\), \((3, 2)\), and \((4, 3)\).

---

## Goals of the project

- **Rigor**: Write clean, efficient, and well-structured code in C.
- **Mathematics**: Use mathematical concepts like vectors and trigonometry to implement Ray-Casting.
- **Graphics**: Learn to work with the **MiniLibX** library to manage windows, colors, and events.
- **Problem Solving**: Parse and validate map files, handle errors gracefully, and optimize performance.

---

## Features

- **3D Rendering**: Use Ray-Casting to render a 3D maze from a first-person perspective.
- **Textures**: Apply different wall textures based on their orientation (North, South, East, West).
- **Colors**: Set custom floor and ceiling colors.
- **Smooth Controls**:
  - Move forward, backward, left, and right using the **W**, **A**, **S**, and **D** keys.
  - Rotate the camera using the **left** and **right** arrow keys.
- **Window Management**:
  - Close the window using the **ESC** key or the window's close button.
  - Handle window resizing and minimizing gracefully.
- **Map Parsing**:
  - Parse `.cub` files to configure the maze and textures.
  - Validate map files to ensure they are closed and correctly formatted.

---

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yasminefontenele/42_cub3D.git
   cd cub3d
2. Compile the project using the provided Makefile:
   ```bash
   make
3. Run the program with a .cub map file:
   ```bash
   ./cub3D name_of_the_map.cub

## Usage

### Controls

- **W**: Move forward.
- **S**: Move backward.
- **A**: Move left.
- **D**: Move right.
- **Left Arrow**: Rotate camera left.
- **Right Arrow**: Rotate camera right.
- **ESC**: Close the window and exit the program.

---

### Example Map File (`map.cub`)

```plaintext
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0

1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

## Map Configuration

The `.cub` file must contain the following elements in any order (except the map, which must be last):

### Textures

- `NO ./path_to_the_north_texture`
- `SO ./path_to_the_south_texture`
- `WE ./path_to_the_west_texture`
- `EA ./path_to_the_east_texture`

### Colors

- `F R,G,B` (Floor color, e.g., `F 220,100,0`)
- `C R,G,B` (Ceiling color, e.g., `C 225,30,0`)

### Map

- Composed of `0` (empty space), `1` (wall), and `N`, `S`, `E`, or `W` (player's starting position and orientation).
- The map must be closed/surrounded by walls.

### Controls

- Movement: W, A, S, D.
- Rotation: Left Arrow, Right Arrow.
- Exit: ESC or close the window.

### Link util:

[Cub3d code explanation](https://hackmd.io/@nszl/H1LXByIE2)
