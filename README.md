# Projet_tetris
## Tetris game in c++ with SFML

All the game file are in the ProjectC++ directory. <br>
The tetris_todo.txt containes the specification for the tetris game.
The networkTest.sh can be used to test the multiplayer online by emulating two device on one PC (for testing purpose) . 

##  Network

The networkTest.sh creates 2 new network spaces (it's only temporary) and connect the two with a virtual link to simulate a fake network. <br>
To make it work you have to launch the command : <br>
`./networkTest.sh {red|blue}` 
Then launch the actual game (follow the readme contained in the projetC++ directory)
The two ip adresses in the virtual network are : <br>
`192.168.15.1/24` and `192.168.15.2/24`
