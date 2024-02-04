# Hatsuki ( Discord bot written on c++ )

## Overview
Hatsuki is a Discord bot written in C++ that utilizes the dpp library (dpp.dev) and spdlog for logging.

## License
This project is licensed under GPL 3.0. See the [LICENSE](LICENSE) file for details.

## Dependencies
- [dpp library](https://dpp.dev)
- [spdlog](https://github.com/gabime/spdlog)

## Build Instructions
Follow these steps to build and run Hatsuki:

1. Create a build directory:
   ```bash
   mkdir build
   ```

2. Change to the build directory:
   ```bash
   cd build
   ```

3. Run CMake:
   ```bash
   cmake ..
   ```

4. Build the project:
   ```bash
   make
   ```

5. Run Hatsuki:
   ```bash
   ./hatsuki
   ```

6. Fill out the configuration file:
   ```bash
   nano config.conf or vim config.conf
   ```

## Configuration
Make sure to fill out the `config.conf` file with the required settings before running Hatsuki.

## GitLab Repository
This project is hosted on GitLab. You can find it [here](https://gitlab.com/miruchigawa/hatsuki).

## Support and Issues
For any questions or issues, please check the [GitLab repository](https://gitlab.com/miruchigawa/hatsuki) or open a new issue.

Feel free to contribute and improve Hatsuki!