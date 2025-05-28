## 1. System requirements

### 1.1 Functional requirements

#### 1.1.1 Player Management
- The system should allow the player to move around the map using the WASD keys
- The player must be able to attack the enemies
- The player must be able to interact with the NPC
- The player must be able to use amulets from the inventory.

#### 1.1.2 Combat System
- Each hit must deal damage calculated according to the formula: (base damage + bonuses) - target protection
- Health should decrease when taking damage.
- When reaching 0 health, the character must die.
- After killing an enemy, the player must gain experience and gold.

#### 1.1.3 The Amulet System
- Each amulet must have a unique effect.
- The effects of amulets should not be temporary
- Amulets should be available for purchase from a merchant only once.
- Amulets must be kept in the player's inventory.

#### 1.1.4 The NPC System
- NPCs must be able to communicate with the player
- A merchant has to sell amulets for gold
- An elder should give quests

###2.2 Non-functional requirements

#### 1.2.1 Reliability
- The system must save the player's progress in one game cycle.

## 2. Usage Scenarios

### 2.1 Basic Gameplay

#### Scenario 1: Moving around the map
1. The player presses the WASD keys
2. The system checks the ability to move (if the player is not trying to pass through an obstacle or other characters)
3. The system updates the player's position on the map
4. The system displays the player's new position

#### Scenario 2: Fight with the enemy
1. The player is approaching the enemy
2. The player presses the attack button
3. The system calculates the damage
4. The system reduces the enemy's health
5. If the enemy's health is 0:
- The enemy dies
   - The player gets experience and gold
6. If the enemy's health is > 0:
- The enemy counterattacks
   - The system calculates damage by player
   - The system reduces the player's health

### 2.2 Using Amulets
- the amulet is applied immediately after its purchase

### 2.3 Interacting with NPCs

### Scenario 3: Talking to NPCs and moving on to the next levels
1. The player approaches the elder
2. The player presses the interaction button
3. The system displays a dialog
4. The player will also have to talk to the merchant once to continue with the token
5. The player will need to talk to the merchant twice before the boss battle.

#### Scenario 4: Trading
1. The player approaches the merchant
2. The player presses the interaction button (optional)
3. The system opens the trading menu
4. The player chooses an amulet to buy (required)
5. The system checks for gold
6. If there is enough gold and the player does not have the amulet, there is a free place in the inventory:
- There is an exchange
   - The amulet is added to the inventory
7. If there is not enough gold:
   - The system reports an error
8. If the player has an amulet:
- The player will not be able to buy such an amulet
9. If there is no free space in the other calendar: 
   - The player receives the appropriate reward from the system.

## 3. System Limitations
1. Maximum inventory size: 20 slots 
2. Maximum player level: 3

## 4. System Dependencies
- Input system for processing player actions (terminal)