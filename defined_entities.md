# List of all used entities #


| **Rep** | **used in Level** / **.inc file** | **description** |
|:--------|:----------------------------------|:----------------|
| BB      | default.inc                       | old Ball        |
| BB      | twirl.inc                         | new Ball        |
| `^`O + `^`X | spike.inc                         | spikes kill the ball, this spikes direction is **up** |
| o`^` + x`^` | spike.inc                         | spikes kill the ball, this spikes direction is **down** |
| o> + x> |spike.inc                          | spikes kill the ball, this spikes direction is **right** |
| >o + >x |spike.inc                          | spikes kill the ball, this spikes direction is **left** |
| t1      | Phase\_out.inc                    | this Targets give 100 Points and it is temporaly not hitable|
| t1      | static.inc                        | this Targets give 100 points |
| c1      | static.inc                        | this Targets give 100 points and it circulate around in a distance of **500 px** |
| c2      | static.inc                        | this Targets give 100 points and it circulate around in a distance of **720 px** |
| c3      | static.inc                        | this Targets give 100 points and it circulate around in a distance of **820 px** |
| c4      | static.inc                        | this Targets give 100 points and it circulate around in a distance of **1020 px** |
| bt      | static.inc                        | this bonustarget give 10 points |
| b1      | static.inc                        | this bonustarget  give 10 points and it circulate around in a distance of **500 px** |
| 1t      | static.inc                        | this Targets give 100 Points and change gravity **(x=0; y=-40)** |
| 2t      | static.inc                        | this Targets give 100 Points and change gravity **(x=0; y=40)** |
| 3t      | static.inc                        | this Targets give 100 Points and change gravity **(x=40; y=0)** |
| 4t      | static.inc                        | this Targets give 100 Points and change gravity **(x=-40; y=0)** |
| TT      | wood.inc                          | Standard Teeter horizontal|
| T2      | wood.inc                          | Standard Teeter vertical|
| T3      | wood.inc                          | Teeter vertical after hit Change gravity **(x=-10; y=0)** |
| T4      | wood.inc                          | Teeter vertical after hit Change gravity **(x=10; y=0)** |
| F1      | wood.inc                          | flipperteeter horizontal pivot Point is right |
| F2      | wood.inc                          | flipperteeter horizontal pivot Point is left |
| P1      | wood.inc                          | Paddel vertical  no pivot Point moves up and down after hit change gravity **(x=-10; y=0)** |
| P2      | wood.inc                          | Paddel vertical  no pivot Point moves up and down after hit change gravity **(x=10; y=0)** |
| w1 - w6 | walls.inc                         | wall sandy-texture 60x60|
| d1 - d6 | walls.inc                         | wall sandy-texture 60x60|
| s1 - s6 | walls.inc                         | wall sandy-texture 60x60|
| h1 - h6 | walls.inc                         | wall sandy-texture 60x120|
| W1 - W6 | walls.inc                         | wall sandy-texture 120x60|
| D1 - D6 | walls.inc                         | wall sandy-texture 120x60|
| q1 - q4 | walls.inc                         | wall wood-texture 60x60|
| g1 - g4 | walls.inc                         | window-texture 60x60 no physics|
| )1 - )6 | walls.inc                         | Triangel wall sandy-texture 90° left upper corner|
| (1 - (6 | walls.inc                         | Triangel wall sandy-texture 90° right upper corner|
| /1 - /6 | walls.inc                         | Triangel wall sandy-texture 90° right lower corner|
| \1 - \6 | walls.inc                         | Triangel wall sandy-texture 90° left lower corner|
| Do      | "Level 4" / 004.lvl               | Area Change gravity **(x=0; y=40)** |
| Ri      | "Level 4" / 004.lvl               | Area Change gravity **(x=40; y=0)** |
| Le      | "Level 4" / 004.lvl               | Area Change gravity **(x=-40; y=0)** |
| Up      | "Level 4" / 004.lvl               | Area Change gravity **(x=0; y=-40)** |
| AR      | "Level 4" / 004.lvl               | Arrow that shows gravity direction |
| `R1`    | "Level 6" / 006.lvl               | Area for checkpoint |
| `R2`    | "Level 6" / 006.lvl               | Area for checkpoint |
| x1      | "Level 6" / 006.lvl               | Wall - when the ball hit the wall he Change his color|
| X1-X3   | "Level 6" / 006.lvl               | Wall - Ball with correct Color can through this wall|
| ra      | "Up and Down" / 007.lvl           | Area that apply a force to the ball **(x=20; y=0)** |
| la      | "Up and Down" / 007.lvl           | Area that apply a force to the ball **(x=-20; y=0)** |
| GT      | "Up and Down" / 007.lvl           | `GhostTeeter` sometimes he can not hit the ball (semi transparent then) |
| ti      | "Up and Down" / 007.lvl           | timer to control the `GhostTeeter`|
| br      | "Up and Down" / 007.lvl           | Wall that apply an impulse to the ball when the ball hit the Wall **(x=50; y=0)** |
| bl      | "Up and Down" / 007.lvl           | Wall that apply an impulse to the ball when the ball hit the Wall **(x=-50; y=0)** |
| TP      | "Shooting Range" / 012.lvl        | Teleport the ball to "BB" position|
| RR      | "Level 2" / 016.lvl               | Rotating Teeter (no control)|
| P1      | "Level 2" / 016.lvl               | Wall - when ball hit this wall on the top the wall push the ball back|
| GL & GR | "Level 2" / 016.lvl               | Gate (like a gull-wing door) when the ball hit one of them the gate opens|
| k1 - k6 | "Rocket Science" / 017.lvl        | wall sandy-texture 60x60 fall down (physic-rules) |
| a1 - a6 | "Rocket Science" / 017.lvl        | wall sandy-texture 60x60 destroyable and fall down (physic-rules)|
| K1 - K6 | "Rocket Science" / 017.lvl        | wall sandy-texture 120x60 destroyable and fall down (physic-rules)|
| A1 - A6 | "Rocket Science" / 017.lvl        | wall sandy-texture 120x60 fall down (physic-rules)|
| m1      | "Moving Walls" / 024.lvl          | wall 60x60 moving horizontal in sinus rhythm|
| m2      | "Moving Walls" / 024.lvl          | wall 60x60 moving horizontal in cosinus rhythm|
| M1      | "Moving Spikes" / 025.lvl         | wall 120x60 moving vertical in sinus rhythm|
| M2      | "Moving Spikes" / 025.lvl         | wall 120x60 moving vertical in cosinus rhythm|
| MO & MX | "Moving Spikes" / 025.lvl         | Spikes moving vertical in sinus rhythm, spikes direction is **down**|
| oM & xM | "Moving Spikes" / 025.lvl         | Spikes moving vertical in cosinus rhythm, spikes direction is **up**|
| M2      | "RR Fliper" / 026.lvl             | device to shoot in the ball (flipperlike)|
| P1 - P8 | "RR Fliper" / 026.lvl             | Wall - when the ball hit this wall from a specific direction the ball will push back|