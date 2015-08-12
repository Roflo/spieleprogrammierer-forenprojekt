# Parallax-Scrolling #

Each level is designed to allow parallax-scrolling. Therefore the background-tag includes the parallax-child-tags. Each one defines a width and height and each content placed inside will be scrolled based on the position of the view inside the level.
The bigger a parallax-layer is, the faster the content will be scrolled when moving the view inside the level and the closer to the viewer the content will appear to be.

The layers aligned that way, that they all line up their left borders when the view is the furthest left possible and all top borders will line up when the view is at the most top position. The lower and right borders will be aligned in a similar fashion. All other positions in between will be aligned based on the percentage of the view alignment inside the level. If the view is centred in the level, the parallax-layers will be centred as well.

To visualize the concept, see the lower image. The blue frame represents the level, the red frame represents the view and the green frames represent the parallax-layers.

![https://spieleprogrammierer-forenprojekt.googlecode.com/svn/trunk/Concepts/graphical/parallax.gif](https://spieleprogrammierer-forenprojekt.googlecode.com/svn/trunk/Concepts/graphical/parallax.gif)

## Note ##
In order not to display empty borders on any side of the view, each layer must have at least a size as big as the maximum supported resolution of the game, which is 1920x1080.