# Farkle Dice Minigame (as depicted in Kingdom Come Deliverance 2)

This CLI game made in C is a recreation of the dice minigame from KCD2. I'm working on this for fun to learn C. 

Created in Visual Studio 2022 with the included build tools.

This video may be more helpful for learning the rules of the dice game https://youtu.be/wztXFvbiu20, but I will attempt to explain it below.

## Rules:
- The game is played with 2 players taking turns to roll dice, starting with 6 of them. In this game you will play against the computer (or maybe another player on the same keyboard, haven't decided yet).
  
- After the dice are rolled, if there are any viable options to score points (see scoring section below), you must select at least one scoring die to add to your score.
  
- From here, you can stop your turn and bank your points, then it will be the other player's turn to roll...
  
- OR you can reroll the dice you haven't selected in the hopes of getting a better roll and thus scoring more points.

- This is where the fun of the game comes from, balancing risk vs reward to maximise points per turn, with the risk of throwing away all the points you earned that turn if you get too greedy.
  
- However, if none of the dice score in a roll, the player has 'farkled' and all points for that round/turn are lost.

- If you manage to score with all 6 dice (whether in the first throw or through rerolling remaining dice), you have 'hot dice' and may continue your turn with a new throw of all six dice, adding to your score for that round. There is no limit to how many times this can occur in a round, albeit unlikely.

- The first player to reach 10,000 points wins.

## Scoring:

| Dice Combination   | Points |
|--------------------|---------|
| <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/0/09/Dice-1.svg/2048px-Dice-1.svg.png" alt="Each 1" width="32"/>      |   100    |
| <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/dc/Dice-5.svg/2048px-Dice-5.svg.png" alt="Each 5" width="32"/>       | 50 |
| <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/0/09/Dice-1.svg/2048px-Dice-1.svg.png" alt="Three 1s" width="32"/> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/0/09/Dice-1.svg/2048px-Dice-1.svg.png" alt="Each 1" width="32"/> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/0/09/Dice-1.svg/2048px-Dice-1.svg.png" alt="Each 1" width="32"/>| 1000 |
| <img src="https://upload.wikimedia.org/wikipedia/commons/3/34/Dice-2.svg" alt="Three 2s" width="32"/> <img src="https://upload.wikimedia.org/wikipedia/commons/3/34/Dice-2.svg" alt="Three 2s" width="32"/> <img src="https://upload.wikimedia.org/wikipedia/commons/3/34/Dice-2.svg" alt="Three 2s" width="32"/> | 200 |
| <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/Dice-3.svg/600px-Dice-3.svg.png" alt="Three 3s" width="32"/> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/Dice-3.svg/600px-Dice-3.svg.png" alt="Three 3s" width="32"/>  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/Dice-3.svg/600px-Dice-3.svg.png" alt="Three 3s" width="32"/> | 300 |
| <img src="https://upload.wikimedia.org/wikipedia/commons/1/16/Dice-4.svg" alt="Three 4s" width="32"/> <img src="https://upload.wikimedia.org/wikipedia/commons/1/16/Dice-4.svg" alt="Three 4s" width="32"/> <img src="https://upload.wikimedia.org/wikipedia/commons/1/16/Dice-4.svg" alt="Three 4s" width="32"/>  | 400 |
| <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/dc/Dice-5.svg/2048px-Dice-5.svg.png" alt="Three 5s" width="32"/><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/dc/Dice-5.svg/2048px-Dice-5.svg.png" alt="Three 5s" width="32"/><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/dc/Dice-5.svg/2048px-Dice-5.svg.png" alt="Three 5s" width="32"/>  | 500 |
| <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/14/Dice-6.svg/600px-Dice-6.svg.png" alt="Three 6s" width="32"/>  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/14/Dice-6.svg/600px-Dice-6.svg.png" alt="Three 6s" width="32"/>  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/14/Dice-6.svg/600px-Dice-6.svg.png" alt="Three 6s" width="32"/>| 600 |
| Each additional die after 3 of a kind, doubles the value | e.g. Four 5s = 1000, Five 5s = 2000, etc. |
| <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/0/09/Dice-1.svg/2048px-Dice-1.svg.png" alt="1" width="32"/> <img src="https://upload.wikimedia.org/wikipedia/commons/3/34/Dice-2.svg" alt="2" width="32"/>  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/Dice-3.svg/600px-Dice-3.svg.png" alt="3" width="32"/>  <img src="https://upload.wikimedia.org/wikipedia/commons/1/16/Dice-4.svg" alt="4" width="32"/> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/dc/Dice-5.svg/2048px-Dice-5.svg.png" alt="5" width="32"/> | 500 |
| <img src="https://upload.wikimedia.org/wikipedia/commons/3/34/Dice-2.svg" alt="2" width="32"/>  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/Dice-3.svg/600px-Dice-3.svg.png" alt="3" width="32"/>  <img src="https://upload.wikimedia.org/wikipedia/commons/1/16/Dice-4.svg" alt="4" width="32"/> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/dc/Dice-5.svg/2048px-Dice-5.svg.png" alt="5" width="32"/>  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/14/Dice-6.svg/600px-Dice-6.svg.png" alt="6" width="32"/> | 750 |
| <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/0/09/Dice-1.svg/2048px-Dice-1.svg.png" alt="1" width="32"/> <img src="https://upload.wikimedia.org/wikipedia/commons/3/34/Dice-2.svg" alt="2" width="32"/>  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/Dice-3.svg/600px-Dice-3.svg.png" alt="3" width="32"/>  <img src="https://upload.wikimedia.org/wikipedia/commons/1/16/Dice-4.svg" alt="4" width="32"/> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/dc/Dice-5.svg/2048px-Dice-5.svg.png" alt="5" width="32"/>  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/14/Dice-6.svg/600px-Dice-6.svg.png" alt="6" width="32"/> | 1500 |

Screenshot from Kingdom Come Deliverance 2, ignore the devil's head, custom dice are not implemented in this.

![image](https://github.com/user-attachments/assets/90b43ded-942f-47b2-a3ad-a8b7b7524256)
