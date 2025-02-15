.SILENT:

MAKEFLAGS += --no-print-directory

QMK_USERSPACE := $(patsubst %/,%,$(dir $(shell realpath "$(lastword $(MAKEFILE_LIST))")))
ifeq ($(QMK_USERSPACE),)
    QMK_USERSPACE := $(shell pwd)
endif

QMK_FIRMWARE_ROOT = $(shell qmk config -ro user.qmk_home | cut -d= -f2 | sed -e 's@^None$$@@g')
ifeq ($(QMK_FIRMWARE_ROOT),)
    $(error Cannot determine qmk_firmware location. `qmk config -ro user.qmk_home` is not set)
endif

%: assets/keymap.svg
	+$(MAKE) -C $(QMK_FIRMWARE_ROOT) $(MAKECMDGOALS) QMK_USERSPACE=$(QMK_USERSPACE)

assets/keymap.svg: keyboards/ergodox_ez/base/keymaps/tbung/keymap.c
	mkdir -p assets
	qmk c2json --no-cpp keyboards/ergodox_ez/base/keymaps/tbung/keymap.c | \
		keymap parse -q - | \
		keymap draw -o assets/keymap.svg -
