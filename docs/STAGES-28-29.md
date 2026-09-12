# J-Roc Stages 28-29

## Stage 28
Network runtime foundation:
- network-device model
- Ethernet frame definitions
- IPv4 packet definitions
- routing table
- socket manager
- packet buffer
- TCP state model
- UDP state model

## Stage 29
Security and desktop/application integration:
- security policy
- permission evaluation
- runtime identity
- security auditing
- sandbox runtime
- GUI runtime
- window manager runtime
- settings
- file manager
- notifications
- themes
- application runtime interfaces

## Production work still required

Networking:
- actual NIC driver
- DMA/ring management
- packet TX/RX
- ARP
- DHCP
- complete IPv4
- complete TCP/UDP
- DNS resolver

Security:
- real authentication
- cryptographic implementation/auditing
- enforced page/process isolation
- secure storage

Desktop:
- framebuffer/GPU driver
- actual compositor
- input event routing
- GUI toolkit
- application process integration
