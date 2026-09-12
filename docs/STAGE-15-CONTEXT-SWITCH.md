# J-Roc XCore Stage 15

## Added

- CPU context structure
- Context zeroing
- Context validation
- Low-level context-switch ABI
- Task-context table
- Task stack metadata
- Context-switch compile test
- Context structure test

## Not yet activated in the boot path

- Timer ISR -> scheduler handoff
- Register-frame capture from an interrupt
- Full save/restore of a running task
- Kernel stack switching
- TSS
- Ring-3 execution
- Address-space switching

These are the next protected integration steps.
