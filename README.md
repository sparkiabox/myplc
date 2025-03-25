# Why myplc ?

**myplc** is an open-source C++ library designed to replicate the behavior of PLC (Programmable Logic Controller) functions and function blocks, bringing industrial automation into the C++ ecosystem.

At Sparkia Box, we see C++ as the ultimate language for programming microcontrollers, PLCs, PC-based controls, and any device automating industrial tasks. Here’s why:

- **Embedded Systems Standard**: C/C++ dominates embedded programming.
- **PLC Compatibility**: Many modern PLCs and automation controls now support C++.
- **IT-OT Bridge**: C++ classes and objects can replace traditional PLC function blocks, aligning with scalable IT practices like AI integration and rapid development.

We lean toward the IT side of the IT-OT divide, believing it accelerates project delivery and future-proofs automation.

# Current Status

This project is in early development. Core function blocks are being implemented, with more features to come.

# Requirements

- C++17 or later
- CMake 3.10+
- A C++ compiler (e.g., GCC, MSVC)

# Getting Started

1. Clone the repo: `git clone https://github.com/sparkiabox/myplc.git`
2. Navigate to the folder: `cd myplc`
3. (CMake setup coming soon—stay tuned!)

# How We Manage Files

- **src/**: Contains the source code developed to build the `myplc` library.
- **samples/**: Includes standalone sample programs that work independently of the environment.
- **Makefile**: We’ll release a CMake file soon to automate installation and library setup.
- **user_code**: We’ll release a CMake file soon to automate installation and library setup.

# Our Roadmap

We’re building `myplc` in our spare time, so there’s no set timeline—just consistent progress. Our goals are:

- **Replicate PLC Behavior**: Create C++ equivalents for common PLC functions and function blocks.
- **Sample Projects**: Provide examples showing how simple C++ statements can mimic PLC behavior.

# Contributing

We welcome contributions! make changes, and submit a pull request. Focus areas: new FBs, tests, or samples.

# License

This project is licensed under the GNU General Public License v3.0. See [LICENSE](https://github.com/sparkiabox/myplc/blob/main/LICENSE) for details.

# Contact

Questions? Reach out via [GitHub Issues](https://github.com/sparkiabox/myplc/issues) or join the [myplc discussion](https://github.com/sparkiabox/myplc/discussions).