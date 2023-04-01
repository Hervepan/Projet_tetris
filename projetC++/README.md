# Setup and installation

## Requirement 

For the project we used the SFML library to take care of the graphics and the network part of the project. <br>
So before doing anything you need to install SFML on your PC. <br>
To do so you can click on the link here :
[Download SFML](https://www.sfml-dev.org/download/sfml/2.5.1/)
You'll also need to have a way to compile C++ file (g++, Mingw, clang etc ....) and a way to run a Makefile 

## Launching the game

To launch the game you can juste launch the Makefile. <br>
You can launch the following command : <br> 
**Soloplayer mode**  : `make run` to launch the game <br>
**Multiplayer mode** :
>You'll have to give more arguments to play the game in twoplayer mode. <br>
Template : `make run {server|client} {if client: Server IP adress}` <br>
When you play with two player you need one of the two to host the game. In this case he'll need to run the command <br> 
`make run server` 
Then the other player (the client) needs to launch the following commmand. <br>
`make run client IP_adress` where the `IP_adress` is the IP adress of the server (the host) <br>
To check your IP adress on linux you can use `ip -4 a` 

# TETRIS GAME 

## Control keys

|Key|Output|Key|Output |
|-|-|-|-|
|&#8592; or `Q`| Move left |`Z`| Rotate CCW |
|&#8594; or `D`| Move right |`Space` | Hard drop |
|&#8595; or `S`| Move down |`Escape`| Quit the game |
|&#8595; or `X`| Rotate clockwise | `C` | Hold |

`CCW` : stands for Counterclockwise <br>
`Hold` : It will switch the current tetromino with the one in the hold space  
`Hard drop`: The tetromino will drop down instantly

## Multiplayer 

When you're playing two player mode, we added the "garbage". <br> 
When a player clears n lines it will send n-1 lines to the opponent.

## What you should have 

![Tetris game](tetris.png)






