![C++latro](./assets/c++latro.png)

# C++latro - Balatro rewritten for speed
C++latro is a rewrite of Balatro written in C++, with a focus on speed. This project is a faithful recreation of the logic behind the game, with plans for it to be used for AI / brute-forcing algorithms.

This project is strictly a CLI tool for developers, with **no** plans for a GUI.

## Building
### Requirements
- g++ 13.1 (via [MSYS2](https://www.msys2.org/) for Windows users)
- ninja 1.3 ([Link](https://ninja-build.org/))
- Python 3.6

### How to build
Generate the build file:
```bash
python3 configure.py
```

Then run ninja to build:
```bash
ninja
```

To run the executable:
```bash
cd out
./C++latro --seed TEST
The Goad
```

## I want to contribute!
**Please** make an issue discussing the feature before implementing it. Chances are I already have a design in mind for how it should be made.
