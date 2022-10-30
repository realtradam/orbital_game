**

Raylib RPG Example

# Concept

A single player dungeon crawl type game intended to be a basic example of the genre to people who are less familiar with game programming and design. Will use raylib with simple 3d top down sprites and sprite sheets to create a graphical rogue-like display.

![](https://lh4.googleusercontent.com/87e2GLF9vTDuBYNa_53i3ZX9Yl_RlgY16PyorJmzmXFVAtY9vh0sU0jwt2z7d0pxCDdKcl0t-YKfqOKn9sQoX-WsIKdXjKMrBc80mOp1xCm53nsKZl0ybGoFJver_DC5BHt1N7jymAubCH5HLnnVHeMhJ-KAboI0YxRtv2iO1wHLwZEjuj0h3aNB)

Possible assets to use.

# Scope

The scope of this project must be very limited by it’s simple nature. The main goal is for easy to understand code, not efficiency. The project must be completable in roughly a week’s time.

  

Things to avoid for the initial example.

  

-   Procedural Level Generation
    
-   Complex Character Creation
    
-   Complex Combat Systems
    
-   Multiplayer
    
-   Economy (vendors)
    
-   Character Stats
    
-   ECS
    

# Requirements

-   Basic C++
    

-   No Templates, simple containers (array, list, etc..)
    
-   Single Threaded
    
-   Use Tiled for maps if needed
    

-   Wall collision
    
-   Doors
    
-   Triggers
    

-   Use simple sprite sheets
    
-   Single player
    

-   One base player type, equipment says what you can do
    

-   Simple health system
    
-   Simple combat system
    

-   Melee
    
-   Ranged
    

-   No Ammo
    

-   Scrolls
    

-   Multiple monster types
    

-   Different health and attacks
    

-   Simple inventory
    

-   Paperdoll for equipment
    

-   Armor
    
-   Weapon
    

-   Backpack slots
    

-   Lootable items
    

-   Containers (chest and barrels)
    
-   Monsters
    
-   Coin for score
    

-   Activatable Items
    

-   Heal (Potion)
    
-   Protection (Scroll)
    
-   Attack (Potion)
    
-   Direct Damage (Fireball Wand)
    

-   Level Transitions
    
-   Win and Lose States
    

-   Win when you loot final level chest
    
-   Loose when you die, YOLO
    

-   Simple sound effects
    

# Open Questions

None at this time.

# GamePlay

### Basic UI

The basic UI will have the player in the level as the focus of the camera in the main content area of the window. A player health bar, gold(score), and action buttons are along the bottom. Menus are shown over the main view with a transparent background. Pressing I or the InventoryAction button on the UI will bring up the inventory window.

  

![](https://lh6.googleusercontent.com/sXiPR-6F5SQU6BiaOOmXMdOzQ9-y796XsMQisTo51qROeDoVISC9njLfBs6uhvg5MeEj2DZr7f6vAZjOJ_Kfq7rtHzhza271YDPxO4-OHVEAD-_WK_mOzdgZJj-R1Gc3gPOz7rmP04hunRxkJbjmOA0euUo3Q6JIl5_2en4Q_6jHldITl5RWMMOj)

#### Inventory Window ![](https://lh4.googleusercontent.com/-OMV6IVty1IsGkRAw9srtrVq1W5WZ-7I7dukPGezk6uIytIQ551rsfVPHuCv95m6mbSPAVs3EBIw2x0D5H3bLhqyWldTRsgyAwJcCn7SOviSoZFs0g-PtddbpsQFXoLtD7Dlye4nFn4DsXifV2w_TQehWagHBACVOOZ-DidXcG493bcLKGLxe_Z3)

The Inventory window will have a grid of item slots (20), and two equippable slots for weapon and armor. The user can drag items from inventory into the equippable slots. Items dragged out of the window will be dropped. When selected or hovered a tooltip will show the item's name and bonuses. Any item can be put in any item slot. Only weapons can be put in the weapon slot, and only armor can be put in the armor slot.

![](https://lh4.googleusercontent.com/6CsJOy4erYJ1lAkigRm8EGvy7E0dYb2aiVBYZDgZAnH-JCRTxiSqh_zzv9RJdOI72TGoLUDABN6Kgv8_g63vm1ozas7_YmKEoTz6XraS1lLEdiPzOhZpQjWoC8UjHLTcCXEWzOYn9o24avkaaGMd8GZKQMCyy20Vv436zyMtEvrndFpEqp3gBBBQ)

### Controls

The player moves around the world by clicking on areas on the map (Click to move). Pressing the left mouse button activates an attack for the primary weapon. If the primary weapon is Melee it attacks all enemies in a radius around the player. If the primary weapon is ranged, the cursor will be an attack cursor when not over a UI element. When a ranged weapon is used then the enemy under the cursor will be attacked. Primary attacks have a cooldown based on a speed stored with the weapon. Changing weapons does not reset the cooldown time from a previous attack. The primary attack action button in the UI will gray out during the cooldown.

### Movement ![](https://lh6.googleusercontent.com/1MO9GYUpIxHpORQVye5WDqYDfX9zj9A_ZVYsxfqycce6E_JleldHOKL6R3FECLFDsKk0dzRhZC-2QNdyJ-ecnFgcPsu8U3enxI1RjJHeiiOFsTVs0uVjXCtKQWHYvinaLTYBY6KkGyHyHH9bTzDRryTr5F1TltpV8360pFwGQNuQQpbr3kre3rLL)

When the player moves around the map, they are constrained to an inset rectangle around the screen, similar to the “Player push camera on getting too close to screen edge” mode from the [core_2d_camera_platformer example](https://www.raylib.com/examples/core/loader.html?name=core_2d_camera_platformer). Some levels will be larger than the screen and will scroll using this method.

### Gameplay

The game starts with the player equipped with no armor and no weapon, in a simple room with a stairwell down. This first room has a lootable chest with a health potion in it and a sign saying how to loot it (click on it when near). While in this first room the UI will have tooltips showing what each button does.

  

When the player enters the stairwell they go down a level to the combat training room.

This room has a basic melee combat encounter against a simple enemy, like a rat. Their is a chest with a dagger in it at the start of the room, with a text that describes how to equip it. Opening the chest with the dagger triggers a door to open to the next room. The rat will begin attacking when the player enters that room. Killing the rat opens a door to a third room with a chest and basic armor and stairs down.

Third room is similar to the second room but trains ranged combat with throwing daggers. This room has no chest at the end.

The fourth through Nth room are gameplay rooms, with more monsters and loot. In the last room is a boss monster and a chest that ends the game. When the game is over you are shown a win screen and clicking will take you back to the main menu.

  

If you die, you are shown a defeat screen and clicking will take you back to the menu.

#### Combat ![](https://lh3.googleusercontent.com/qC64yFNdSEfE9ZmqszNZFRFg7R9nYTq5RH7Y7-2eJenpQ1DMmNb5nSDG3jGHtr4WVKg5kzzqwRQMtvrMWOKnItjV20QxwnU-zSvNh1ZoHLkZXmwm1BZ211NLUYq6zZTGKbrxpWnqTFKAW0nWC7H04B4_r0nhzrPfoDEqT72cX_Wwx3FdxzIYyV7q)

Combat is a simple process. The attack damage of the weapon + A random number from -3 to 6 is the attack roll. The target’s defense is subtracted from this. Any positive remainder is removed from the health of the target. When the target’s health is 0 it dies. Dead monsters leave a corpse behind that may have loot from a loot table.

### Monsters ![](https://lh5.googleusercontent.com/7xl0JEFOaU_xu8pJ3HIsxU6BOgdG0NmR2AQaLyGhTougPlGJ9_KXNze1bL9wrNcLnPDczYfLyaVMU8oHY7ksKVn15OtV63N-JbIItUlA69xN9aAz3g3dokm584J3Bx59FMX5cxJr4AQuiz2b3rwqsK7gXE9FDy7WpN2Mh5FLJzj3qDXhM5aDeW5G)

Monsters are given an attack skill using an internal weapon. This can be ranged or melee. Monster AI will be very simple, move toward the player when in view and attack when in range. When a monster is killed it may drop lootable items and/or coins near it. When dropped these items appear near the monster to be looted.

### Items ![](https://lh5.googleusercontent.com/HicVf_lXGPMrwNITfKtDtV01lEb2TAmKtDLsr1NS4J9eNmpuVIrQsgUC4pXgnbLzEI1KNi3Ezl-suD6gtZci8FBdAgJIRkBfQihtL7pnoRsyML0-_-ex1JMLPOTbVRh9SNkNbeViBjnR2N5rfKD_5TzBFo3FRhqytvNYm9E9uSXTYUE90kApjHek)

Items are shown in the world as icons on the map. Items can be picked up by clicking on them. If the player has room in the inventory the item is put in the next available slot. If there is no room in the inventory the item is dropped. Dropped items are placed near the player within the map. Items can overlap.

  

Some items are activatable, like a health potion, or protection scroll. When an activatable item is picked up, it’s icon is shown on the action bar on the hud. Clicking the icon in the hud will activate the item. Activated items are destroyed after a single use and are removed from inventory.

  
Coin “items” have a value and are added to the coin score when picked up. Coins do not go into inventory.

# Application Design

The game application will be made up of multiple source and header files that handle the following items.

-   Main (application startup)
    
-   Resources
    
-   Menus
    
-   Map
    
-   Player
    
-   Monster
    
-   Items
    
-   Gameplay
    
-   Drawing/UI
    

## Resource System

A resource management system will handle loading and storing all used textures and sounds. Textures and sounds will be given an ID using an enumeration and code will request a reference to the resource by this ID.

## Menu System

A menu system will reference the current menu by an ID. The menu system will maintain a stack of menu IDs that can be pushed and popped as needed. 

## Map System

The map system will handle loading the level from the resource system and providing storage for items and monsters that are created by the gameplay system. The map system will not draw the level or any of its contents, it is simply data and state storage.

## Player, Monsters, and Items

Players, Monsters and Items will be simple classes that define the data for each instance of the object. Functions will exist to create and fill out the data for each type of monster or item. These objects will then be stored by the map system for use by gameplay.

## Gameplay System

The Gameplay system will handle all game logic. It will take input from the player and apply it to the state stored in the map system. The gameplay system is responsible for all player actions, monster AI, and combat resolution. 

## Drawing/UI System

The drawing/UI system is responsible for drawing the map and handling events from the HUD. It uses data from the map to draw and passes events into the gameplay system as needed. The UI system is responsible for handling events in the inventory window.

# Content

This section describes the specific content used in the game.

  

##    Menus

The game will start on the main menu. During gameplay pressing escape will pause the game and show the main menu.

### Main Menu

The main menu has the following items.

-   Start Game
    

-   Will change to Resume Game when invoked while the game is playing.
    

-   Options
    
-   Quit
    

### Options Menu

The options menu has three items.

-   Fullscreen
    
-   Volume
    
-   Back
    

  

Player Data ![](https://lh5.googleusercontent.com/c756MOCHUMepCE67Voe5_vUFg_ubU4BlG4GSTyi3vD8_MwfMmhiAgrmIg8iMEWzAAxq3W_C17HMrIvkJJpk-WN_is_lnF3--a7TYGlNg2yp4Ty8WBAPDd-057wxB7Igu8JagdayVtSe6Bcg9AbFiYtebM9hjLRXQfnlS3PcqEq1U0kADgdY-iDCy)

The player starts with 20 health and 0 defense. Items can increase these values.

## Enemy Types

Describes the types of enemies, stats

### Rat ![](https://lh3.googleusercontent.com/SKk2Hs6tECO0W6R6BNQ82dy3CqEhhe4wy5R9JVpo6hzFdrZwAj8FVjc0CC3VYwFQCWkjXcn7NaRPKLNiv59JMS9bk2o-6jBcMy-D5iEHVHIYOT6fsjyVj2sjGlAOaZn_Pcxw9U1e5N0Y2Gh2kstkywaQjuHOZJ9SxeW2ACVhKAxe00fCXF8BBWXN)

-   1 Health
    
-   0 Defense
    
-   Claw Attack
    

-   Melee
    
-   1 Damage
    
-   1 second cooldown
    

### Snek ![](https://lh6.googleusercontent.com/BUcD6aReOa2i0X6O8YL1TGgqnPTC2xGOtQunZ_YEZS7kHwXvlJxEbFyjR3wO8qp2Sa_lQRNTgxw70fldFfOWAshRt3EkpOcOpNVzSQQ60gpjniEdqJv5gjrNjVeR85W3ONHPqlfI9ZviuI-Ul4d8Hz43LwAZQvE8BK8GI7kWlWOICouP8GBjmOus)

-   3 Health
    
-   10 Defense
    
-   Bite Attack
    

-   Melee
    
-   2 Damage
    
-   1 second cooldown
    

### Ghust ![](https://lh6.googleusercontent.com/BQj5ebZoxyuyE7yyfGZRoFHY_JBtJYdgb7CZJwuEpx5ukTFZZT7HwWuFDaNfTqKyWa4uZpzIoeWRxOII5l-PVZEEOF-O4aBZqEKe324Y0vkuzU3U4h_gYr2wf6R5nZwer-WGJa3znf60LxFCXr2zkYX7RCmNOpDAYIZ3uJCjQP8rRMV5LVZk5JV_)

-   2 Health
    
-   15 Defense
    
-   Scare Attack
    

-   Ranged
    
-   10 Damage
    
-   5 second cooldown
    

### Troll ![](https://lh4.googleusercontent.com/eQ-LVzT7OwR2wUKXU8mk7cstWQWBLUKZ_LeKZJ5qyH8q1wz-Nb1iRp_QcaqKXbFNER-cgDBVB22nty-ExEShoiwbMS4tnfNqxydaaFKq_WLlmzt84FNIeZmG3fGm2O7KMwzErhkLN9k_gY-HcXKmitACzFR1_T_KQRVaf43GjQadd81zBhrPcihs)

-   30 Health
    
-   10 Defense
    
-   Punch Attack
    

-   Melee
    
-   10 Damage
    
-   1 second cooldown
    

### Tortile ![](https://lh5.googleusercontent.com/JCAPBXsaK3KInX3MvdQnr8EGUq8veeHzQgu41-FkX5AlBLS77e1VcSirzBlC4l1_k-E71qrNZZdgmxvsBH5IYz6pWZkeqzPWYXTU1cSlaygf9EGtxXnwvt9Ng8g0E9BICj7SM59W85XleFmi_sL9_7DMW1hYb7gSvlRIe781_M7FoV-TJ1HFU-z6)

-   5 Health
    
-   18 Defense
    
-   Headbut Attack
    

-   Melee
    
-   1 Damage
    
-   15 second cooldown
    

### Blorb ![](https://lh3.googleusercontent.com/I40nN33lJO-U19nC0bWK1c1a4b8Y5a0fkeC6U3hgjqOjllcQcPrbnQJkRMYrbSOOZAO4JIf9zIutWkhnzssOgcti2I4BcVXbGDbT0L1ws-zDgcU5SbBvYiJqw5q1uFhsl2il-iLaGLlWHpiuSSGK9bkmQWem_8JMcdywHU1D_ZUobtau5U5RUFZ6)

-   20 Health
    
-   10 Defense
    
-   Eww Attack
    

-   Melee
    
-   15 Damage
    
-   2 second cooldown
    

###   
DudeBro ![](https://lh6.googleusercontent.com/IAw6WsZV7hqEhGoegXdXOFq4hPlkD2LSSRZZ_I5gNByuHyUdLftS_-lV3IxhKx6I7RHWtuZJ6PoClzOgvBpF8Fvl6q5xsjkX49rnXddF0Rd3UIY4H1Dnw7Jl4_96X1MvzeTAehy33i_XU2aJnK-WAShYohA-ZDmV850oBY3FZ1S6KrQ-QRsRuk5e)

-   20 Health
    
-   10 Defense
    
-   Rust Attack
    

-   Melee
    
-   20 Damage
    
-   2 second cooldown
    

### Munk ![](https://lh5.googleusercontent.com/gcO5SCe0GME0ljvsfQwL0RmUUZgY9kKqbn6hIZiz63k7_6yldsUhcCuSAdI8HqCIaOm5KPiqdAzahZ-lIe2V3ys_SKl5twe7ka9DIkP4kSl1aVPLGo2S4B19fwZYrJnra27IQJw5gmPaObDVzLG90FOPy0bSDWfGKceFARYXr12SIgCdo4wcM9MO)

-   15 Health
    
-   14 Defense
    
-   Chant Attack
    

-   Ranged
    
-   25 Damage
    
-   3 second cooldown
    

### Moderator ![](https://lh5.googleusercontent.com/hqxxiYNc2Il4KYpysfl5BWQipdnJmwJMzwCakOSY5-NjiEtW6XXyQ6ynBcig3SCtJnxjexuftMjJ6RAnuvhCWaD83VxvFXbsanvpVNAGbSdJS_OwTM9C3czQRC7aLL7fb8TdNMj9CkETXpU8r6BdeaUFJeTCa2EHlk1Vc9XRgPYmoF8BYeNvZ_W7)

-   Boss Mob  
    50 Health
    
-   10 Defense
    
-   Ray Attack
    

-   Ranged
    
-   25 Damage
    
-   3 second cooldown
    

## Items

These items can be picked up from monsters or chests.

### WeaponsI

Sword ![](https://lh3.googleusercontent.com/xs9nMvXBKqnxrnvaS6doDjAF8VLtMt8xLcIRt0B8ZxWoULAru96CwBLRBej9CMF2yngrcBt8brrLcK610EqNhcf0UGnzdITX_bgb6UeiGj9C7ryiB-vcIVrnXpS6jSToWzqBol_QEl4aDq3BjT2F-bzsZYcA6xb72Mv1GC09YQxXKwypBDmoQjKN)

A basic sword.

-   Melee
    
-   Attack Power 0 -2
    
-   Speed 1s
    

Really Cool Sword ![](https://lh4.googleusercontent.com/lXZYOShRZ1Sh1hmdmQ6aLpUQDuyXJLAl6tYKVeE1R0Bs1d_uxndRU5zpjTiW5ehtnYvoDF9FU0xJLi7FYFsehOvmbsqN3wx2d_SALbNPjsPU8iT06Cvt8TXKS1vAn5twSNlpbYfDW11QpC8KME7t14A7Gyi4eitUUiIKFidFSd8YA2QCirCFgBiy)

A fancy sword.

-   Melee
    
-   Attack Power 2 -4
    
-   Speed 1s
    

  

Awesome Sword![](https://lh3.googleusercontent.com/rYB5LDAiceuR7Ez-tO-iyCG5UrKnAWnSxnJIaSARMGSiF35qG1vAlu5egvnlt6mcCUZ9J9cl4yBjQgJi_SAWlUPVvvDuq1qWqrdwGVhGpm0rcKg3LtnWyjLxIRLhGkdMNrpQkKVdKvd08uAAfyV9HhaWqSdSnJRgttBo0Y1JVUKCNHhPJ9ry6viK)

This is a good sword

-   Melee
    
-   Attack Power 4 -6
    
-   Speed 1s
    

  

Axe ![](https://lh3.googleusercontent.com/CrRyrjLKGjF13bpwjtv0pFSjVSMawnqD2YWll3WOyzuKOfUcZjHQ9MJHW9yg-enKHF6dcBC4-eSymmLs28K5LO1tK9MfhoAK9dFTPgDYSYnex_JW1kN-1iMcNHxtH7pewCEcXmvZBXfIV2O6Et-yW7DEU88hmt9ybaiWZYmFoSCCPf5Ocdu537Vs)

Better than a sword 

-   Melee
    
-   Attack Power 1 -4
    
-   Speed 1.5s
    

  

Mighty Axe ![](https://lh3.googleusercontent.com/Sw2RU4M82Ee-RSVguQj-QyFFP3jyE2dhmbIhPh9rkTxBm7JzCz1cjHJRZ7VrNDqjXUAWfuyDZKTnzZqXG8NNDBXXvXvUdjhsorogDN2_fxshpCdobNJPwsvUi0FKUIOPFbA7iZM2mbu7YfJvFAtxKcjCYMcMCPjaYOfri7RaWIQ59JaD6InLSMx7)

Better than an axe

-   Melee
    
-   Attack Power 2 -6
    
-   Speed 1.5s
    

  

Battle Fork ![](https://lh4.googleusercontent.com/4tsNZSHBnK-S44U-pzELjWQjaXXklxefsQv9-7Izeku3Fb3o1GNqXJRcBp9yNStmzcLnTC3_GeBsX_Kigwp8bEe7OiYheC7XejmXe-M4UXeGveC9P_HyKklAlKXkVKtb3odaA8NODRTF93WbSvASUu9Eoa9XDs4xPCfSS_LOlvmo-gEevEc0TOwI)

Stabbing for Justice

-   Melee
    
-   Attack Power 0-2
    
-   Speed 0.5s
    

  

Bow ![](https://lh3.googleusercontent.com/akYOswT52V9S4Vcbi_tG0aIKRdcPaZ6L8CwP_YHOq2S23-Nclf066hFUggpNFHbfVDYPbFEbtdxr8WR5YVeeTVUMvKgXzllBnQKpolma3kDWZZWXbhwERZdi7yhQlhAMrt1hTrzfxapvF0W6fUqgRbNWmRs7tTbsl7ibuF1cdB5-Vb6MvZ1AGnkG)

Pew-Pew-Pew

-   Ranged
    
-   Attack Power 0-2
    
-   Speed 0.25s
    

  

Bonkmaster 5000 ![](https://lh4.googleusercontent.com/-W-DaiFGW24Gl6MazSGWrtsob4uphmsXm0noDegFnsIOfDhnPXELzngJ3fix11RbxOnYFuiZiSqGHeD-G2BJeS0ln5D8GxRx0K9ZpebxTaPzdDQraqtn680GMHbaFq87iLXgBWZT7AMOBjT68VwUcUcuQcap-t8a-9dLDmqkqeiuyvQzobS617PH)

Bonk

-   Melee
    
-   Attack Power 5-10
    
-   Speed 3s
    

### Armor

Pleather Armor ![](https://lh4.googleusercontent.com/Qc6itp_40JwoLELjN35KPOd6cHISAKLLLOBYoHAKKDygkdK3Du4IAcZ-Faf9GIS9W68x879XZj41QHFZlJ0dXxtHGQ0C4V1WGGlldDmdtsSj-t1mt_s_nkWbMR4NzO_ewVZ8hh2m4H1eg_YXc-6pRzaW0LPRhPVlbqS8BQgojYliWbmSHTxuk6pS)

Better than nothing

-   2 Defense
    

  

Chain Shirt ![](https://lh6.googleusercontent.com/wMTpNkuLLHl8oVmUkFWC-hwdX1S7wYH5leWOezbi85ovAIDzRNvCTG_fvgNtsgAJ8Wf0LW8EzNo5podgscQK4LKDxWb9kqD6Zu7ACeeV3X9zeToTekGPzT1P9PphOs13jUq6UF12UCwtffLgn49OM4Wje1PP-4iA5BDdIuarfbT_4JY8jkbIXl3N)

Jingle Nangle

-   4 Defense
    

  

Full Plate ![](https://lh3.googleusercontent.com/Jqqbz-xqbmZNIth_jKur9upjO7XLEFNqQQHLZKwmFiMsOLgD2rsutBrqSTUjn18HPuioGNMJ0_deoab1acwJqUg0d3ZmKJfF_DdhdSPz7SWPeWrGs1T5ffpTx0GwFqMZwOfFAUAjoRksSd-UdJLpzwoHYe9hfchHwzqdPajj-S7NGB-cRWYl0op-)

You are the tank

-   10 Defense
    

### Activatable Items

Fud ![](https://lh4.googleusercontent.com/ICHpr_RMU-9W4XggnQow3I18MfSlwwCgF9WGgFUFG9J79owm_5VvOP_DrZ6ye1DdePZCzK1J1ScFwOc4Oxs018ugfueE8Gi-HZGi0J8y7Y3wRSmLToAw7A0Vw4SyYmZRo4MM7wR5mc0Do6K27QmEZ-c1g7lM9yt3hMMiWaHq0XMnVMV_4C0qZ32g)

A snack

-   + 5Health
    

Potion ![](https://lh5.googleusercontent.com/ImcQ30BJO_MEBCSyMETC1ctR6Z9uMeX263EPm4mxj6ux_GUmyInUV6SNTpX3xk2srq-cX02TUenM7DomNyNexR49VPruXJjw7tjKRXf6H60eZPKocJhpAWgNgZZMZIn70nWDIzbC9fC-jxIgnx3kqUVnDFBtdDpIeyZ2lV9KXgwSyExFwdG2XjmX)

Smells funny, but works

-   + 20 health
    

  

Shield ![](https://lh6.googleusercontent.com/80iuFgrj2Y0a1xDp4XTVJUSN5KR8WgfUwBpGOsAvbpSZLyD-zsziRiwq9tjEWZdhyb65BjsZlObUYJpsiuhPtOmp7IJFuZ97UIaXdWmyMFc6_x9CRoUQ14lRtvkJOlRjUsf3R868Wj2G-v-de9IhLm7GdnP7gX7HF_niS3dzLUUQhpcOtCqSuCY3)

-   + 10 defense for 30 seconds
    

  

Fireballs ![](https://lh3.googleusercontent.com/jFB_ZWz6Hnr9D6x1oIXjYZsDeniqNvqHAmtZI14LVJt9hGE1piy8ND6FqzFyTpqUtwhBZR1-7ahxO0xk1YI25N8G_3Nq-R6mljeqo5RMQyC9rdOm22E2iIC5MJ74iQnVbjcZJ1ejUE4Lh7lP-W5Z8ZF4U0Kcao83KOJTPu9nfiQwCJ-vw9et7yqW)

Boom

-   10 damage to nearest enemy
    

  

### Other Lootables

Monies ![](https://lh5.googleusercontent.com/dWUs1FIy0NLJrx0hpvA7PRE-Jqe49-CQSsQpq3qmlhRVX6RkqZ59QUSJ42DU86ZGrgxmhI3eLDrIZXbjxSR8H_jFNs__R7Z9Hd5pUu7cS7oY-dUF0faQsNjTAfketbUN7_mNmbMGjKa-qpGASxFE6aQnNUbYqQlwv28GMau7C9YsDtTNMp5FDf5u)

A bag of coins

-   1-10 coins
    

## Levels

### Level 1  
![](https://lh4.googleusercontent.com/Okarl4ah9mDh3LCjFJC28T6mzB8seD2kP78Iu2wRveFb86iwTzBjY72_pKVL5_EaKLOJvmmW2VnQKlGoWnRiQPDHi8EBPLcZvgsjKWbiYHjoGqC265zVIjiUe_H7fU4JUxAsIwPt3UuDLEbAFb8pOUIEUC66hkplMsvduquOeRdRIXVqGQWLUnup)

**