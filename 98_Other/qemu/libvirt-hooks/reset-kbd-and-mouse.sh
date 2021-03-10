#!/usr/bin/env bash

mouse_event=$(cat /proc/bus/input/devices  | grep -P '^[NH]: ' | paste - - | grep -P '.*Logitech M720 Triathlon.*' | grep -Eo 'event[0-9]+')
kbd_event=$(cat /proc/bus/input/devices  | grep -P '^[NH]: ' | paste - - | grep -P '.*Logitech MX Keys.*' | grep -Eo 'event[0-9]+')

# Creates symlinks for the two events
ln -fs /dev/input/$kbd_event /dev/input/by-id/usb-Logitech_USB_Receiver-if02-event-kbd
ln -fs /dev/input/$mouse_event /dev/input/by-id/usb-Logitech_USB_Receiver-if02-event-mouse