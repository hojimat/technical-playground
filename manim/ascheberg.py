from manim import *
import pandas as pd

data = pd.read_csv

class TimeSeries(Scene):
    def construct(self):
        axes = Axes(
            x_range=[0,10],
            y_range=[-1,1],
            axis_config={'color': BLUE},
        )

        data