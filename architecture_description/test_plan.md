# Test plan

## Testing of basic functionality

### Standart verification:
- [ ] Checking the player's movement system
  - WASD control
- Collision detection
- Map borders
- [ ] Combat system testing
  - Damage calculation
  - Health Management
- Gaining experience
- Inventory system check [ ]
- Amulet storages and using
- Capacity restrictions
- Correct operation of conversations with NPCs

### Requirements:
- All scenarios should produce the expected results.
  - Unusual situations (lots of enemies, full inventory) should not negatively affect the operation of the program
  - Restrictions on the level and number of amulets.

## Testing the opponent's AI

### AI Logic:
- [ ] Checking the enemy's behavior
  - Movement patterns
  - Attack patterns
  - Bandit Behavior
- Slime Behavior
  - Dragon's behavior in battle

### Check in combat:
- [ ] Accuracy of damage calculation
  - Damage inflicted by the player on enemies
  - Damage inflicted by the opponent on the player
- [ ] Health Management Check:
- Enemy's health
  - Player's health
- [ ] Battle sequence Analysis
- [] Analysis of the battle if the player has amulets

### The following criteria must be met:
- [ ] Everything is working correctly
- [ ] No critical issues found
- [ ] All tests passed