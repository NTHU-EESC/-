# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import numpy as np
import matplotlib.pyplot as plt

# Compute the x and y coordinates for points on a sine curve
t = np.arange(0, 10 * np.pi, 0.1)
y = abs( np.exp(2j*t) + np.exp(3j*t) )
# Plot the points using matplotlib
plt.plot(t, y)
plt.show()  # You must call plt.show() to make graphics appear.