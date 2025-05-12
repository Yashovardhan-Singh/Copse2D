# Vendor Directory
This directory contains third-party libraries used by Copse2D, a custom OpenGL game framework library developed by Yashovardhan-Singh. These libraries are not part of the original codebase and are provided under their respective licenses. They are included as dependencies to support the functionality of Copse2D.
Users are free to use these libraries for their own purposes, provided they comply with the licenses specified in each library’s LICENSE file and give appropriate credit to the original authors. The inclusion of these libraries does not imply ownership by Yashovardhan-Singh.
Third-Party Libraries
The following libraries are included in the vendor/ directory:

* stb_image
    * Description: A public domain/MIT-licensed image loading library.
    * Author: Sean Barrett
    * License: Dual-licensed under MIT License or public domain. See stb_image/LICENSE or stb_image/stb_image.h for details.
    * Usage: Used for loading image files (e.g., textures) in Copse2D.

* glad
    * Description: An MIT-licensed OpenGL loader library.
    * Author: David Herberth
    * License: MIT License. See glad/LICENSE for details.
    * Usage: Used to load OpenGL function pointers for rendering in Copse2D.

* tomlc
    * Description: An MIT-licensed TOML parsing library (tomlc99).
    * Author: Cktan
    * License: MIT License. See tomlc/LICENSE for details.
    * Usage: Used for parsing configuration files in Copse2D.


## Licensing
Each library in the vendor/ directory is governed by its own license, as specified in the respective LICENSE file or source files. These licenses are separate from the GNU Affero General Public License v3.0 (AGPLv3) that applies to Copse2D. Users must review and comply with the individual licenses when using or redistributing these libraries.
For the main project’s licensing, see the LICENSE file in the project root.
Giving Credit
When using these libraries, please give appropriate credit to their authors:

Sean Barrett for stb_image.
David Herberth for glad.
Cktan for tomlc.

This respects the terms of their licenses (where applicable) and acknowledges their contributions to the open-source community.
Directory Structure
vendor/
├── README.md               # This file
├── stb_image/
│   ├── stb_image.h         # Source with MIT/public domain notice
│   ├── LICENSE             # MIT/public domain license
├── glad/
│   ├── glad.c              # Source with possible MIT notice
│   ├── glad.h
│   ├── LICENSE             # MIT license
├── tomlc/
│   ├── toml.c              # Source with possible MIT notice
│   ├── toml.h
│   ├── LICENSE             # MIT license

For further details on each library, refer to their respective subdirectories and license files.
