# GameProcess (Game Process)

The main container encompassing all game components and their interactions.

---

## GeneralComponents

### Game
- **Description:** The central component for game management.
- **Functions:**
  - Controls the game process.
  - Manages enemies via the **"controls"** connection.
  - Utilizes GameField via the **"use"** connection.

### GameField
- **Description:** Represents the game space.
- **Characteristics:**
  - Contains the matrix of the game field.
  - Used by the Game component to display the game world.

---

## Fighters

### Enemies
- **Description:** Represents all enemies in the game.
- **Functions:**
  - Interacts with the Player via the **"combat"** connection.
  - Is managed by the Game component.

### Player
- **Description:** The central game character.
- **Functions and Capabilities:**
  - Engages in combat with Enemies.
  - Interacts with NPCs.
  - Possesses an inventory.
  - Can purchase amulets from the Trader.

### NPC
- **NPC Elements:**

  #### Elder
  - **Interaction:** with the Player via the **"speak"** connection.
  - **Role:** Provides dialogues and quests.

  #### Trader
  - **Interaction:** with the Player via the **"Buy Amulets"** connection.
  - **Role:** Facilitates the trading of amulets.

---

## Inventory
- **Ownership:** Belongs to the Player via the **"has"** connection.
- **Functionality:**
  - Stores and manages Amulets via the **"contains"** connection.
  - Provides an interface for using amulets via the **"uses"** connection.

---

## Amulets
- **Storage:** Held in the Inventory.
- **Usage:**
  - Used through the inventory system.
  - Can be purchased from the Trader.

---

## Main Connections

- **Game → GameField: "use"**
  - The game uses the game field to display the world.

- **Game → Enemies: "controls"**
  - The game manages the enemies' behavior.

- **Enemies ↔ Player: "combat"**
  - A bidirectional combat interaction link.

- **Player → NPC:**
  - **"speak"** for Elder.
  - **"Buy Amulets"** for Trader.

- **Player → Inventory: "has"**
  - The player owns the inventory.

- **Inventory ↔ Amulets:**
  - **"contains"** - storing amulets.
  - **"uses"** - using amulets.

---
## Class hierarchy

### Basic classes

#### Fighter
- **Description:** Base class for all creatures capable of fighting
- **Stats:**
- Basic attributes: Health, Damage, Defense
  - Methods for basic combat

### Hierarchy of game characters

#### Player
- **Inheritance:** Inherited from Fighter
- **Additional features:**
- Inventory Management
  - Using amulets
- Interacting with NPCs

#### Enemy (The base class of enemies)
- **Inheritance:** Inherited from Fighter
- **Subclasses:**
  - **Bandit**
    - Features: Basic enemy with balanced stats
  - **Slime**
    - Features: Low damage, but high survivability
  - **YardDragon**
    - Features: Powerful boss with unique abilities

### Hierarchy of amulets

#### Amulet (Base class)
- **Description:** Base class for all amulets
- **Subclasses:**
- **ADash**
- Ability: Instant Movement
- **AFearOfDeath**
    - Ability: Protection from fatal damage
  - **AHeal**
- Ability: Restore Health
  - **AKillerLook**
    - Ability: Enhance attacking stats
  - **AMadness**
- Ability: Temporary enhancement of all stats
  - **APerseverance**
    - Ability: Enhance protective characteristics

### The NPC Hierarchy

#### NPC (Base Class)
- **Description:** Base class for non-player characters
- **Subclasses:**
  - **Elder**
    - Role: Quest character
  - **Trader**
    - Role: Amulet Dealer

## Game Process
- **Combat**
  - **Player:**
    - may fight with different enemies
    - may die, if he is killed by an enemy (if his health = 0)
    - may buy and use different amulets
    - may walking on the map by "WASD"
    - may earn experience and gold by killing enemies
    - may level up if has enough experience

  - **Enemy:**
    - is an AI, who can combat with player
    - can die and give player different resources
    - can couse damage to the player

  - **NPC**
    - interaction with player
