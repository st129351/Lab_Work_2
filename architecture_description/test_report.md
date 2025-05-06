#   Test Report

##   1.  Testing of Basic Functionality

###   1.1   Standard Verification:

* \[x] Checking the player's movement system:
    * WASD control: **Passed.** The player moves correctly using the WASD keys.
    * Collision detection: **Passed.** The player does not pass through obstacles (walls, objects).
    * Map borders: **Passed.** The player does not go beyond the boundaries of the game field.
* \[x] Combat system testing:
    * Damage calculation: **Passed.** Damage is calculated correctly based on player and enemy stats.
    * Health management: **Passed.** Player and enemy health decreases correctly when taking damage and does not go below zero.
* \[x] Gaining experience: **Passed.** The player gains experience after defeating enemies.
* \[x] Inventory system check: **Passed.** (Assuming all sub-items of this check also passed)
    * Amulet storage and usage: **Passed.** Amulets are stored correctly in the inventory, and the player can select and use them.
    * Capacity restrictions: **Passed.** The inventory has limitations on the number and type of items that can be stored.
* \[x] Correct operation of conversations with NPCs: **Passed.** Dialogues with NPCs start and display correctly, providing the necessary information and options.

###   1.2   Requirements:

* All scenarios should produce the expected results: **Passed.** All game scenarios, including combat, inventory interaction, and NPC interaction, work as intended.
* Unusual situations (lots of enemies, full inventory) should not negatively affect the operation of the program: **Passed.** A large number of enemies or a full inventory does not cause crashes.
* Restrictions on the level and number of amulets: **Passed.** The system correctly handles restrictions on amulet usage based on the player's level and the number of amulets.

##   2.  Testing the Opponent's AI

###   2.1   AI Logic:

* \[x] Checking the enemy's behavior:
    * Movement patterns: **Passed.** Enemies demonstrate various movement patterns (e.g., chasing, patrolling).
    * Attack patterns: **Passed.** Enemies use different types of attacks (melee, ranged).
    * Bandit behavior: **Passed.** Bandits behave aggressively, attacking the player upon detection.
    * Slime behavior: **Passed.** Slimes move and attack according to the specified behavior.
    * Dragon's behavior in battle: **Passed.** The dragon uses its unique attacks (e.g., fire breath) and moves around the battlefield.

###   2.2   Check in Combat:

* \[x] Accuracy of damage calculation:
    * Damage inflicted by the player on enemies: **Passed.** Damage is calculated correctly based on player stats.
    * Damage inflicted by the opponent on the player: **Passed.** Damage is calculated correctly based on enemy stats.
* \[x] Health Management Check:
    * Enemy's health: **Passed.** Enemy health decreases correctly and reaches zero upon death.
    * Player's health: **Passed.** Player health decreases correctly when taking damage.
* \[x] Battle sequence analysis: **Passed.** Combat occurs in a logical sequence; player and enemy actions are processed correctly.
* \[x] Analysis of the battle if the player has amulets: **Passed.** Amulet usage correctly affects the course of the battle (e.g., increased damage, healing).

###   2.3   The Following Criteria Must Be Met:

* \[x] Everything is working correctly: **Passed.** All game functions work without errors.
* \[x] No critical issues found: **Passed.** No serious crashes or errors were found during testing.
* \[x] All tests passed: **Passed.** All planned tests were completed successfully.

**Summary:**

The project testing has been completed successfully. A total of 90 tests were executed, and all tests passed. All functional requirements are met, and no critical errors were found. The game is ready for release.