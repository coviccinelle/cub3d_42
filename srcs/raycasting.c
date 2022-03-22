

a ray (from player to wall) depending on:
-> player's looking direction 
-> the x-coordinate of the screen.


I/ a loop to find out if ray hits a wall (has to)
    1/ start at player's position
    2/ check each time if ray inside a wall or not. check at every side of a wall the ray will encounter. 
    We give each square width 1, so each side of a wall is an integer value and the places in between have a value after the point.
    3/ have to trace the ray further if the ray position is no in a wall (aka add a certain value to its position, in the direction of this ray, and for this new position, again check if it's inside a wall or not) 
II/ if ray finally hits a wall, calculate the distance and draw the wall with the correct height
    1/ the smaller the distance from the player to the wall, the bigger the wall
    2/ the bigger the distance from the player to the wall, the smaller the wall



. A direction vector can be seen as follows: if you draw a line in the direction the player looks, through the position of the player, then every point of the line is the sum of the position of the player, and a multiple of the direction vector.
 The length of a direction vector doesn't really matter, only its direction. 
 Multiplying x and y by the same value changes the length but keeps the same direction

 In a true 3D engine, there's also a camera plane, and there this plane is really a 3D plane so two vectors (u and v) are required to represent it. 
 Raycasting happens in a 2D map however, so here the camera plane isn't really a plane, but a line, and is represented with a single vector.
  The camera plane should always be perpendicular on the direction vector. The camera plane represents the surface of the computer screen, while the direction vector is perpendicular on it and points inside the screen.
   The position of the player, which is a single point, is a point in front of the camera plane. 
 A certain ray of a certain x-coordinate of the screen, is then the ray that starts at this player position, and goes through that position on the screen or thus the camera plane.
