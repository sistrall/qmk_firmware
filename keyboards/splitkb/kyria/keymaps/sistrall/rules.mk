# General configurations
#
# See: https://docs.qmk.fm/#/squeezing_avr?id=rulesmk-settings
LTO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
ENCODER_ENABLE = no       # Enables the use of one or more encoders

# Microcontroller configuration
#
# My Corne is using an Elite-C v4 microcontroller,
# that comes with a DFU bootloader.
BOOTLOADER = atmel-dfu

# No mouse keys, 'cause I like using a real mouse
MOUSEKEY_ENABLE = no

# No LEDs on my Corne: I was kind of worry about soldering them,
# so I left them out for my first build.
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow

# Sure, a display may help.
OLED_ENABLE = yes
OLED_DRIVER = ssd1306

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
  SRC += lighting_layers.c
endif
