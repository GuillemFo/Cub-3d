*****AI used to explain this project*****
# cub3D - Raycasting Engine with miniLibX

## 🎯 Project Overview

**cub3D** is a graphical programming project inspired by the classic game **Wolfenstein 3D**, widely considered the first **First-Person Shooter (FPS)**.

The goal of the project is to implement a **ray-casting engine** capable of rendering a 3D-like environment from a 2D map. Using mathematical principles and the **miniLibX** graphics library, the program generates a dynamic first-person view of a maze where the player can move and explore.

This project introduces fundamental concepts in:

* computer graphics
* real-time rendering
* ray-casting algorithms
* event-driven programming

---

## 🎮 What is cub3D?

**cub3D** is a simple 3D engine based on the **ray-casting technique**, which simulates a three-dimensional environment using a two-dimensional map.

The program renders a maze from a **first-person perspective**, where walls are projected vertically depending on their distance from the player. This technique was famously used in early 3D games such as **Wolfenstein 3D**.

Players can navigate the environment, rotate their view, and interact with the map while the engine dynamically renders the scene in real time.

---

## ✨ Key Features

### Mandatory Requirements

* **Ray-casting engine** that renders a 3D perspective from a 2D map
* **Window management** using miniLibX (open, minimize, close)
* **Textured walls** for each cardinal direction:

  * North
  * South
  * East
  * West
* **Configurable floor and ceiling colors**
* **Player controls**

  * **W / A / S / D** — move through the maze
  * **Arrow keys** — rotate the camera
  * **ESC** or window close — exit the program
* **Map parsing** from `.cub` configuration files
* **Robust error handling** for invalid maps or configurations

---

## 🗺️ Map Format

The map is defined inside a **`.cub` configuration file**.

### Map Characters

| Character       | Meaning                               |
| --------------- | ------------------------------------- |
| `0`             | Empty space                           |
| `1`             | Wall                                  |
| `N` `S` `E` `W` | Player start position and orientation |

### Map Rules

* The map must be **completely surrounded by walls**
* Only one **player starting position** is allowed
* Spaces must be handled correctly during parsing

### Configuration Parameters

The `.cub` file also defines environment settings:

| Identifier | Description         |
| ---------- | ------------------- |
| `NO`       | North wall texture  |
| `SO`       | South wall texture  |
| `WE`       | West wall texture   |
| `EA`       | East wall texture   |
| `F`        | Floor color (RGB)   |
| `C`        | Ceiling color (RGB) |

---

## 🛠️ Technical Stack

| Component             | Technology                         |
| --------------------- | ---------------------------------- |
| **Language**          | C                                  |
| **Graphics Library**  | miniLibX                           |
| **Math Library**      | `-lm`                              |
| **Memory Management** | Manual allocation and deallocation |
| **Build System**      | Makefile                           |

---

## 🎯 Learning Objectives

This project focuses on developing fundamental skills in:

* **Mathematics for graphics**

  * trigonometry
  * vector calculations
  * ray-casting geometry
* **Graphics programming**

  * window management
  * event handling
  * pixel rendering
* **Algorithm design**

  * efficient ray-casting implementation
* **File parsing**

  * handling complex configuration files
* **Memory management**

  * avoiding leaks and segmentation faults
* **Robust error handling**

---

## 🏆 Bonus Features

The bonus part of the project includes additional gameplay features such as:

* **Wall collision detection**
* **Minimap for navigation**  Activate with *M* key
* **Mouse-based camera control**

---

## 🎥 Demo

Watch a demonstration of the project:

https://www.youtube.com/watch?v=eyOCpuCgj4g

*Note: The recording was done while the computer was under heavy load, so the actual performance is smoother.*

---

## 📚 Resources & References

### Project Documentation

* https://cdn.intra.42.fr/pdf/pdf/111520/en.subject.pdf
* https://harm-smits.github.io/42docs/

### Ray-casting Mathematics

* https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/
* http://gamecodeschool.com/essentials/calculating-heading-in-2d-games-using-trigonometric-functions-part-1/
* https://reactive.so/post/42-a-comprehensive-guide-to-cub3d

### miniLibX

* https://github.com/terry-yes/mlx_example
* https://harm-smits.github.io/42docs/libs/minilibx
* https://gontjarow.github.io/MiniLibX/
