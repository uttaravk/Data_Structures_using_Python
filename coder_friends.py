"""
Two players, Erica and Bob are participating in a coding series competition.
Skipped question: 0 points
Easy Level: 1 point
Medium Level: 3 points
Hard Level: 5 points
Task is to find the winner of this competition
Winning Criteria:
1. Player with highest score at the end of the competition wins
2. If both the players have same points:
    a. Player with greater number of Hard Level question wins
    b. If both have same number of Hard Level questions; then result depends on
       of medium level questions
    c. If both have same number of Hard and medium Level questions; then result depends on
       of easy level questions
    d. If all the count of three types of questions is exactly equal then its a tie breaker

Note:
If bob is a winner return Bob, if erica is the winner then return Erica and if its a tie then return Tie

Input:
erica="EMH"
bob="EEMH"
here, E corresponds to Easy, M corresponds to medium, H corresponds to hard

Expected Output:
Bob

"""


import collections
erica = "EEE"
bob = "SSM"


def score_counter(player_count):
    player_score = 0
    for difficulty, cnt in player_count.items():
        if difficulty == "E":
            player_score += cnt
        elif difficulty == "M":
            player_score += cnt * 3
        elif difficulty == "H":
            player_score += cnt * 5
    return player_score


def tieBreaker(erica_count, bob_count):
    if erica_count["H"] > bob_count["H"]:
        return "Erica"
    elif erica_count["H"] < bob_count["H"]:
        return "Bob"

    if erica_count["M"] > bob_count["M"]:
        return "Erica"
    elif erica_count["M"] < bob_count["M"]:
        return "Bob"

    if erica_count["E"] > bob_count["E"]:
        return "Erica"
    elif erica_count["E"] < bob_count["E"]:
        return "Bob"

    return "Tie"


def winner(erica, bob):
    erica_count = collections.Counter(erica)
    bob_count = collections.Counter(bob)
    erica_score = score_counter(erica_count)
    bob_score = score_counter(bob_count)
    if erica_score > bob_score:
        return "Erica"
    elif erica_score < bob_score:
        return "Bob"
    return(tieBreaker(erica_count, bob_count))


print(winner(erica, bob))
