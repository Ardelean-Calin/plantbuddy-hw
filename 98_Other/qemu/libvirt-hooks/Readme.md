You need libvirt-hook-helper for this. See: https://web.archive.org/web/20210304145230/https://passthroughpo.st/simple-per-vm-libvirt-hooks-with-the-vfio-tools-hook-helper/

Then place the reset-kbd-and-mouse.sh hook inside the /etc/libvirt/hooks/qemu.d/macos/prepare/begin/ folder.

https://wiki.archlinux.org/index.php/PCI_passthrough_via_OVMF
