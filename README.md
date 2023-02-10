# Ayura
<h>Modern Tetris Clone built from C++</h>

This is a modified version of Tetris in C++. The base game comes from the help of <a href= "https://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/">Javier López's tutorial on building a Tetris game in C++</a>. Several changes were made to make Ayura unique.

<b><strong>Features</strong></b>
<ul>
  <li>Piece Shadow: A shadow of the current piece will be cast onto the board where it will be placed if it is hard dropped.
  <li>Das and Arr: Holding a direction (left or right) for long enough will start to automatically move the piece in that direction at a speed dependent on the Arr value.
  <li>Hold: Implemented a hold system. If you hold, a piece is stored in the hold section and you are given a new piece. If the hold section already has a piece, your new piece is the piece in the hold section. If the hold section is empty, you are given the next piece in the queue.
  <li>Proper piece coloring: Pieces have the proper color (Square is yellow, Line is cyan, etc.) and they retain their color after being placed.
  <li>Proper modern tetris movement: J-tucks, L-tucks, Z-spins, S-spins, T-spin minis and other possible tuck/rotation variations are now possible.
  <li>Grid on the board: The original version from López had no grid on the board. This is a simple grid feature. 
</ul


There is much more to come in the future. Possible future changes include adding game modes such as the blitz game mode, sprint game modes, and survival. Also the inclusion of stats such as PPS (pieces per second), KPP (keys per piece), etc.
And the option to change your DAS and ARR values from the application itself and not having to manually change the value inside the .cpp file

<b>Setup to Play</b>
Simply clone the repository or download the source code on your machine, go to the debug folder, and run the .exe.

<b>Controls</b> 
<ul>
  <li>UP: Clockwise rotate.
  <li>LEFT: Move left one block. Hold to activate auto repeat
  <li>RIGHT: Move right one block. Hold to activate auto repeat
  <li>DOWN: Soft drop. Move the piece down faster.
  <li>C: Hard drop. Instantly put the piece down on its shadow.
  <li>D: Hold. Store a piece in the hold section. If a piece is already in the hold section, that piece will become your current piece.
  <li>S: 180 Degree rotation.
  <LI>A: Counter clockwise rotate.
