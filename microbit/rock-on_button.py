# Add your Python code here. E.g.
# Upload codes here: https://python.microbit.org/v/2
# References:
# - Buttons: https://microbit-challenges.readthedocs.io/en/latest/tutorials/buttons.html
# - Displays: https://microbit-micropython.readthedocs.io/en/v1.0.1/display.html

from microbit import *


while True:
    if button_a.is_pressed():
        display.show("A")
    if button_b.is_pressed():
        display.show("B")
    if button_a.is_pressed() and button_b.is_pressed():
        display.scroll("rock-on")
