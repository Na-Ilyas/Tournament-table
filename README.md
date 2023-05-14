# Tournament-table
This is the Tournament table project to help and find the champion in the league.
It follows strict format in two txt files, so please be careful with that.
For instance here is the format and expalanation of the  first input file:
4
118 Irtysh Pavlodar 200000.55 32
7909 Astana Nur-Sultan 8500000.20 41
234 Kaisar Kyzylorda 550000.49 29
56 Kairat Almaty 9000000.99 35
This means that there are 4 teams in this football league. The first team Irtysh with id 118
is from Pavlodar, has a budget of USD 200000.55 and has a score of 32. The second
team Astana with id 7909 is from Nur-Sultan, has a budget of USD 8500000.20 and has
a score of 41, etc. 

The input file should be provided by you and then it will print you the scoreboard.

Next, Second games.txt file's format is here:
118 234 1 2
234 7909 2 3
7909 56 0 1
56 118 1 5
234 7909 0 2
56 7909 1 7
Each line consists of 4 integers. The first two numbers 
indicate that there is a match between teams with teamId1 and teamId2. The third
number (match_result) can be either 0, 1, or 2, indicating who the winner is. If 1 then the
first team wins and its score is increased by score, which is the fourth integer in the
line. If 2 then the second team wins and its score is increased by score. If 0 then there
is a tie in the game and both teams’ scores are increased by score.

