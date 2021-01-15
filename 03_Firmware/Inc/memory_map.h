#pragma once

extern int __bootrom_start__;
extern int __bootrom_size__;
extern int __approm_start__;
extern int __approm_size__;
extern int __ram_start__;
extern int __ram_size__;
// Here we will store our vector table in RAM
extern int __vector_table_ram_start__;