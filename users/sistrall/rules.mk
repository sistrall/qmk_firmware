# Enable combos: the idea is to use combos for layer switching
COMBO_ENABLE = yes

# Enable tap dance: the idea is to use it for accents and symbols
TAP_DANCE_ENABLE = yes

BOOTMAGIC_ENABLE = no
MAGIC_ENABLE = no

INTROSPECTION_KEYMAP_C = sistrall.c

SRC += keycodes.c
SRC += tap_dances.c
SRC += layers.c

ifeq ($(strip $(ENCODER_ENABLE)), yes)
  SRC += encoder.c
endif
