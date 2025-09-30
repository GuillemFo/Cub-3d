# cub3D - My First RayCaster with miniLibX

## 🎯 Project Overview

cub3D is a 3D graphical project inspired by the legendary **Wolfenstein 3D** - the first-ever First Person Shooter game. This project takes you back to 1992, recreating the revolutionary ray-casting technology that changed gaming forever.

> **Summary:** This project is inspired by the world-famous Wolfenstein 3D game, which is considered the first FPS ever created. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, where you will have to find your way.

## 🎮 What is cub3D?

cub3D is a **ray-casting engine** that creates a realistic 3D representation of a maze from a first-person perspective. Using mathematical principles and the miniLibX graphics library, you'll build a navigable 3D environment where you can explore corridors, view textured walls, and experience the fundamentals of 3D game rendering.

## ✨ Key Features

### Mandatory Requirements

- **3D Ray-casting Engine**: Implement the core ray-casting algorithm to render 3D perspective
- **Dynamic Window Management**: Smooth window handling (minimize, switch, close)
- **Textured Walls**: Different textures for each cardinal direction (North, South, East, West)
- **Customizable Environment**: Set floor and ceiling colors
- **Intuitive Controls**:
  - **WASD keys** for movement through the maze
  - **Arrow keys** for looking left/right
  - **ESC** or **window close** to exit cleanly
- **Map Parsing**: Read scene files (`.cub` extension) with custom format
- **Error Handling**: Comprehensive validation of map files and configurations

### Map Format

- **Characters**: `0` (empty space), `1` (wall), `N/S/E/W` (player start position & orientation)
- **Requirements**: Map must be surrounded by walls, handle spaces intelligently
- **Configuration File** includes:
  - Texture paths for each direction (NO, SO, WE, EA)
  - Floor and ceiling colors (F, C) in RGB format

## 🛠️ Technical Stack

| Component | Technology |
|-----------|------------|
| **Language** | C |
| **Graphics** | miniLibX |
| **Libraries** | math library (-lm) |
| **Memory** | Manual management (no leaks) |
| **Build System** | Makefile with standard rules |

## 🎯 Learning Objectives

- **Mathematics in Practice**: Apply trigonometric and geometric principles
- **Graphics Programming**: Window management, colors, textures, events
- **Algorithm Design**: Efficient ray-casting implementation
- **File Parsing**: Complex configuration file handling
- **Memory Management**: Proper allocation and freeing
- **Error Handling**: Robust program with clean exits

## 🏆 Bonus Features

- **Wall collisions** for realistic movement
- **Minimap system** for navigation
- **Interactive doors** that open and close
- **Mouse look** for intuitive camera control

# Direct link
[Watch on YouTube](https://www.youtube.com/watch?v=eyOCpuCgj4g)


## ⚒️ Tools we used:

Subject
*	https://cdn.intra.42.fr/pdf/pdf/111520/en.subject.pdf
*	https://harm-smits.github.io/42docs/  
       Math for raycasting
*	https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/
*	http://gamecodeschool.com/essentials/calculating-heading-in-2d-games-using-trigonometric-functions-part-1/
*	https://reactive.so/post/42-a-comprehensive-guide-to-cub3d

Minilibx
*	https://github.com/terry-yes/mlx_example
*	https://harm-smits.github.io/42docs/libs/minilibx
*	https://gontjarow.github.io/MiniLibX/
