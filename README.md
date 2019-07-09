# BeeWars
Small mini-game test task on Qt C++

# Qt version
Qt 5.12.1

# Test task text
Bee game - the game with one button "hit" in upper right corner in menu bar.

You need to kill all bees around you; When you push the hit button, server randomly hits some bee; Before the bee is hitted it makes an action, which is defined by its type;

You have 300 health.

    If you kill all the bees - you are a winner.
    If you are killed by the bees - you are a loser.
    If the last bee kills you before its death then the result is draw.
Specification:

1.Queen Bee

The Queen Bee has a lifespan of 100 Hit Points. When the Queen Bee is hit, 8 Hit Points are deducted from her lifespan.

If/When the Queen Bee has run out of Hit Points, All remaining alive Bees automatically run out of hit points.

    There is only 1 Queen Bee.

2.Worker Bee

    Worker Bees have a lifespan of 75 Hit Points.

    When a Worker Bee is hit, 10 Hit Points are deducted from his lifespan.

    There are 5 Worker Bees.

3.Drone Bee

    Drone Bees have a lifespan of 50 Hit Points.

    When a Drone Bee is hit, 12 Hit Points are deducted from his lifespan.

    There are 8 Drone Bees.

Gameplay:

To play, there must be a button that enables a user to “hit” a random bee. The selection of a bee must be random.

When the bees are all dead, the game must be able to reset itself with full life bees for another round.
in a form of windows app

#TO DO
1) Class restructurisation
2) Tests
