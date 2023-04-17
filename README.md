# Projet_tetris
## Tetris game in c++ with SFML

All the game file are in the `ProjectC++` directory. <br>
The `tetris_todo.txt` containes the specification for the tetris game. <br>
The `multi_test` can be used to test the multiplayer part by emulating two device on one PC (for testing purpose) . 

##  multi_test

In the multi_test directory you have three files : <br>
`networkSetup` to setup the two network spaces (emulate two PC)<br>
`launchGame {red|blue}` to launch the game when you're in the red or blue network space (it will take care of launching the game with the right arguments and do the connection). Please follow the instruction that will appear in the command line <br>
`cleanup` to remove the spaces created <br>
