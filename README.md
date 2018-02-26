# cpp_spider

Epitech second third project : cpp_spider

Advanced C++ Programming 1 module

Beginning of the project : 25/09/2017, 08h42

Deadline : 2 weeks

Group size : 6 persons

Contributors : 
* [beche_f](https://github.com/Francoisbeche)
* [onillo_l](https://github.com/LezardImperial)
* colett_j
* bourre_q
* durand_4

## Description

This project consists in a keylogger software, using a client/server architecture.

This project is divided in two parts:
* The client MUST run on Windows.
* The server MUST run on Unix.

On Windows, you MUST use Microsoft Visual Compiler (MSVC) to build your project. Using MinGW is NOT allowed.
The Spider project aims to create a keylogger “network” with many clients and one or more servers.

As such, you have to come up with a protocol that will allow both transmission of data from the clients to the server, but also the possibility of instructions sent by the server. It MUST be usable over the Internet (you cannot use anything LAN specific).

## Getting started

These instructions will allow you to obtain a copy of the operational project on your local machine for development and testing purposes.

### Prerequisites

What do you need to install the software and how to install it?

```
gcc
boost
```

### Installation

Here's how to start the project on your computer

Clone and go in the directory cpp_arcade

Project compilation

* Client
```
Compile with visual studio
```
* Server
```
cd server
make
```

Running project

```
./spider PORT
```

## Build with

* [C++](https://en.wikipedia.org/wiki/C%2B%2B)

## Autor

* **David Munoz** - [DavidMunoz-dev](https://github.com/davidmunoz-dev)
