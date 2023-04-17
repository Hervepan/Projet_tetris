## Plateau de jeu

Le plateau de base a 10 colonnes et 20 lignes <br>
On a 7 tetrominos différents: <br>
 - Le tetromino "I" 
 - Le tetromino "O"  
 - Le tetromino "T"  
 - Le tetromino "S"  
 - Le tetromino "Z"  
 - Le tetromino "J"  
 - Le tetromino "L" <br><br>
![Tetrominos](https://tetris.wiki/images/3/3d/SRS-pieces.png)<br>

Trouver une manière de représenter le plateau et les tetrominos.(liste, tableau ...) 
## Rotation des tetrominos	

Pour faire tourner vu que les tetrominos sauf le I peuvent se mettre dans des blocs 3x3 donc c'est pas difficile ((x,y)->(-y,x) pour le sens horaire). Il faut juste faire attention au tetromino "I"

## Collision/Lock
Pour détecter les collisions, vous pouvez créer un tableau représentant la grille de jeu. Chaque cellule du tableau  a une valeur de 1 si elle est occupée par un bloc de tetris et 0 si elle est vide. Lorsqu’un tetris termine sa chute, on met à jour le tableau pour refléter sa position. Pour vérifier les collisions,on utilise ce tableau pour voir si l’une des cellules dans lesquelles le tetris essaie de se déplacer est déjà occupée.

## Score

Pour calculer le score, ça dépend du nombre de lignes que l'on clear en même temps :

    1 line: 40 points
    2 lines (double): 100 points
    3 lines (triple): 300 points
    4 lines (tetris): 1200 points

## Hold

Il faut aussi implémenter la possibilité d'échanger une pièce. <br>
Si c'est la première fois vous pouvez le faire n'importe quand mais sinon il faut que ce soit au début de la chute du tetromino

## Speed-up

Augmentez la vitesse de chute des tetrominos à chaque fois que 10 lignes sont clears.

# Additional

## Wall Kick:

Rotation when you collide with a wall to fit in and not go outside the matrix.
https://tetris.fandom.com/wiki/TGM_Rotation


