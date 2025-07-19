from manim import *

class MyScene(Scene):
    def construct(self):
        circle = Circle()            # Create a circle
        circle.set_fill(PINK, opacity=0.5)  # Set its color
        self.play(Create(circle))    # Animate the circle creation
        self.wait(1)

