# General configurations
#
# See: https://docs.qmk.fm/#/squeezing_avr?id=rulesmk-settings
LTO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no

# Microcontroller configuration
#
# My Corne is using an Elite-C v4 microcontroller,
# that comes with a DFU bootloader.
BOOTLOADER = atmel-dfu

# No mouse keys, 'cause I like using a real mouse
MOUSEKEY_ENABLE = no

# No LEDs on my Corne: I was kind of worry about soldering them,
# so I left them out for my first build.
RGBLIGHT_ENABLE = no
