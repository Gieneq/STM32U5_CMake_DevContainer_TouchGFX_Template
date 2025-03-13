arm-none-eabi-objcopy -O binary --only-section=ExtFlashSection target/build/tmplatemkfileu5dk.elf gdb/jlink_flash_loader/images.bin
echo "Check file 'gdb/jlink_flash_loader/images.bin'"