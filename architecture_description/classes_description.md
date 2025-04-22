# Class diagram

## Main classes

### Fighter (Base Class)
- **Attributes:**
- health
- damage
- defense
- level
- experience
- **Methods:**
- attack() - attack
  - TakeDamage() - taking damage
  - isAlive() - test of life
  - gainExperience() - gaining experience

### Player (Inherited from Fighter)
- **Additional attributes:**
- inventory
- gold
- position on the map
- **Additional methods:**
- move() - move
- useAmulet() - using the amulet
  - interactWithNPC() - interaction with NPCs
- LevelUp() - level up

### Enemy (The base class of enemies, inherited from Fighter)
- **Subclasses:**
  - **Bandit**
    - Features: balance of characteristics
- Additional methods: stealGold() - stealing gold
  - **Slime**
    - Features: low damage, high survivability
- Additional methods: split() - split
- **YardDragon**
    - Features: Boss with unique abilities
- Additional methods: FireBreath() - Fire breath

### Amulet (Base class of amulets)
- **Attributes:**
- name (name)
- price (price)
  - duration (duration of the effect)
- **Methods:**
- activate() - activation
- deactivate() - deactivation
- **Subclasses:**
- **ADash** - instant movement
- **AFearOfDeath** - protection from fatal damage
  - **AHeal** - restoring health
  - **AKillerLook** - Attack enhancement
  - **AMadness** - temporary enhancement of all characteristics
  - **APerseverance** - enhanced protection

### NPC (Base class of non-player characters)
- **Subclasses:**
  - **Elder**
    - Methods: giveQuest() - issuing a quest
  - **Trader**
    - Methods: sellAmulet() - sale of an amulet

### Inventory
- **Attributes:**
  - items (items)
- capacity (capacity)
- **Methods:**
- addItem() - adding an item
  - removeItem() - deleting an item
  - useItem() - use of the item

### Game
- **Attributes:**
- player (player)
- enemies (enemies)
- npcs (NPCs)
- gameField (playing field)
- **Methods:**
- start() - the beginning of the game
  - update() - status update
- end() - end of the game

### GameField
- **Attributes:**
- width (width)
- height (height)
- matrix (field matrix)
- **Methods:**
- generate() - field generation
- update() - field update
- display() - field display

## Connections between classes

1. **Inheritance:**
- Player → Fighter
   - Enemy → Fighter
   - Bandit → Enemy
   - Slime → Enemy
   - YardDragon → Enemy
   - Elder → NPC
- Trader → NPC
- All Charms → Amulet

2. **Composition:**
- Player contains Inventory
   - The game contains a GameField
   - Inventory contains an Amulet

3. **Aggregation:**
- The game is controlled by Enemy
   - The game is controlled by the NPC
- The Player interacts with the NPC
- The Player uses the Amulet