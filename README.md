# Swallow Project README

## Introduction:
The Swallow project is a versatile command-line interface (CLI) tool designed to interact with an microcontrollers (currently only Arduino UNO 3). The primary goal of Swallow is to provide a streamlined way to control and test Arduino functionalities, in my case, for UAV's and in future also for rockets.

## Features:
- **basic terminals commands**
- **led and memory tests** Checks if Arduino works correctly
- **run:** Compile and upload Arduino code stored in the "obc-sets" directory, enabling seamless execution of custom programs.

## Dependencies:
- CMake: 3.10 or newer
- Arduino CLI: Required for code compilation and uploading.

## How to Run:
1. Navigate to the Swallow project directory.
2. Create a build directory: `mkdir build && cd build`.
3. Run CMake: `cmake ..`.
4. Build the Swallow executable: `make`.
5. Run Swallow: `./Swallow`.
Note: You can also `make` command, and skip the CMake, but one day i will stop updating the Makefile

## Example Commands:
- `echo Hello, Swallow!`
- `led 3`
- `run`

## Project Structure:
- **Terminal:** Contains the main CLI components.
- **Arduino:** Stores Arduino-related code and tests.

## Contributing:
Contributions are more than welcome!