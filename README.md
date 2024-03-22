# File Downloader
A simple File Downloader using C++ and libcURL.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Compilation](#compilation)
- [Contributions](#contributions)
- [License](#license)
- [Feedback](#feedback)

## Introduction
The File Downloader is a C++ project developed using the libcURL library. It facilitates downloading files from provided URLs using the cURL library and provides real-time download progress information, including download speed, percentage completion, and total download size.

<img width="1061" alt="screenshot_filedownloader" src="https://github.com/ezBinary/File-Downloader/assets/164413461/3a934709-5c81-4125-ba4a-a9a2396e7f6c">

## Features
- Downloads files from provided URLs using cURL.
- Displays real-time download progress, including percentage completion and download speed.
- Provides a simple and easy to use command line interface for downloading files.

## How to Use
1. **Input URL**: Provide the download link of the file you want to download.
2. **Start Download**: Press enter to initiate the download process.
3. **Monitor Progress**: Monitor the download progress, including the percentage completed and the download speed.
4. **Completion**: Once the download is complete, the file will be available for use.

## Why File Downloader?
File Downloader was developed as a training project to learn more about the capabilities of the cURL and enhance understanding of network programming in C++. It aims to provide a practical example for those interested in integrating file downloading functionality into their projects.

## Compilation

To use File Downloader, simply clone the repository and compile the source code using your preferred C++ compiler. Ensure that you have the libcURL library installed on your system.

### Compiling with Different Compilers

File Downloader can be compiled using various compilers on different platforms. Below are instructions for compiling the project with commonly used compilers:

#### 1. g++

```bash
g++ main.cpp downloader.cpp console.cpp -o FileDownloader -lcurl
```

#### 2. clang++

```bash
clang++ main.cpp downloader.cpp console.cpp -o FileDownloader -lcurl
```

#### 3. Microsoft Visual C++ (MSVC)

```bash
cl /EHsc main.cpp downloader.cpp console.cpp /link /out:FileDownloader.exe
```

### Platform Compatibility

This project's Makefile is designed to work seamlessly on both macOS and Linux systems. Below are instructions on how to use it :

To compile the project on macOS and Linux systems, simply navigate to the project directory in the terminal and run the `make` command. This will compile the source files and generate the executable `FileDownloader`.

---

Feel free to let me know if you need any further modifications!

## Contributions
Contributions to File Downloader are welcome! Feel free to fork the repository, make improvements, and submit pull requests.

## License
This project is licensed under the [MIT License](LICENSE). Feel free to use and modify it according to your needs.

## Disclaimer
File Downloader is provided as-is, without any warranties or guarantees. I am not liable for any damages or issues arising from the use of this software.

## Feedback
If you have any feedback, suggestions, or issues, please feel free to [open an issue](https://github.com/ezBinary/File-Downloader/issues) or [contact me](mailto:ez.like.binary@proton.me). I appreciate your input!

Enjoy using File Downloader for your file downloading needs!
