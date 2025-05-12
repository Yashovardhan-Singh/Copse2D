# Copse2D
Copse2D is a custom OpenGL game framework library designed to simplify the development of OpenGL-based games and applications. Developed by Yashovardhan-Singh, this library provides tools for window management, texture loading, configuration parsing, and OpenGL rendering, leveraging modern C programming practices.  

## Features
* **Window Management**: Easy-to-use window creation and event handling with GLFW.
* **Texture Loading**: Support for loading images (PNG, JPEG, etc.) via stb_image.
* **Configuration Parsing**: TOML-based configuration file parsing with tomlc.
* **OpenGL Integration**: Seamless OpenGL function loading with glad.
* **Modular Design**: Extensible architecture for adding custom rendering pipelines and game logic.


## Installation
### Prerequisites

* C Compiler: GCC, Clang, or equivalent.
* GLFW: Version 3.3 or later (for window and input handling).
* OpenGL: Version 3.3 or later (for rendering).
* Meson: Version 0.59 or later (build system).
* Ninja: Typically used as the backend for Meson.
* Dependencies: The vendor/ directory includes stb_image, glad, and tomlc, so no external downloads are required for these.

### Build Instructions

1) Install Meson and Ninja (if not already installed):

   * On Ubuntu/Debian:sudo apt install meson ninja-build
   ```sudo apt install meson ninja-build```

   * On macOS (with Homebrew):brew install meson ninja
   ```brew install meson ninja```

   * On Windows, use pip or download from https://mesonbuild.com/.

2) Clone the Repository:
```
git clone https://github.com/[your-username]/[your-repo].git
cd [your-repo]
```

3) Configure with Meson:
```meson setup build```

4) Build the Project:
```meson compile -C build```

5) Run the Example (if included):
```build/example```


## Dependencies
The project includes the following third-party libraries in the vendor/ directory:

* **stb_image**: Image loading (MIT/public domain).
* **glad**: OpenGL function loader (MIT).
* **tomlc**: TOML parsing (MIT).

See vendor/README.md for details on these dependencies and their licenses.
Usage


## Licensing
Copse2D is licensed under the GNU Affero General Public License v3.0 (AGPLv3). See the LICENSE file in the project root for details.
The vendor/ directory contains third-party libraries (stb_image, glad, tomlc) that are not part of the original codebase and are provided under their respective licenses:

stb_image: MIT License or public domain.
glad: MIT License.
tomlc: MIT License.

These libraries are not covered by the AGPLv3 unless specified in their license files. Users are free to use these libraries for their own purposes, provided they comply with their respective licenses and give appropriate credit to the original authors (Sean Barrett, David Herberth, Cktan). For details, see vendor/README.md and the LICENSE files in each subdirectory (vendor/stb_image/, vendor/glad/, vendor/tomlc/).
Contributing
Contributions are welcome! To contribute:


## Fork the Repository:
`git clone https://github.com/[your-username]/[your-repo].git`

1) Create a Branch:
`git checkout -b feature/your-feature`

2) Make Changes:
Follow the coding style in existing source files.
Update documentation and tests (if applicable).


3) Submit a Pull Request:
Push your branch and create a pull request on GitHub.
Describe your changes and their purpose.

Please ensure your contributions comply with the AGPLv3 license. For third-party code, submit changes to the respective library’s repository (e.g., stb_image, glad, tomlc) rather than modifying files in vendor/.


## Contact
For questions, issues, or feedback:

GitHub Issues: https://github.com/Yashovardhan-Singh/Copse2D/issues
Email: yashovardhansingh08@gmail.com

Acknowledgments
Copse2D builds on the work of the open-source community. Special thanks to:

Sean Barrett for stb_image.
David Herberth for glad.
Cktan for tomlc.

These third-party libraries are critical to the project’s functionality and are included in the vendor/ directory under their respective licenses.
