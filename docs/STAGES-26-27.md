# J-Roc Stages 26-27

## Stage 26
Per-process virtual address-space foundation:
- address-space objects
- user-range validation
- page-mapping API
- process/address-space association

## Stage 27
Persistent-storage foundation:
- block device API
- VFS open-file API
- mount manager
- filesystem superblock

## Still required for production integration
- hardware page-table activation per process
- CR3 switching during context switches
- real page-fault handler
- actual disk controller driver
- persistent read/write operations
- real filesystem implementation
- filesystem journaling/recovery
