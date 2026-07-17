Virtual Networks Lab (ELC 3080)

Objective: Explore TCP behavior and OSPF routing dynamics using Linux and the CORE network emulator, based on a provided OSPF/TCP network topology (Project_OSPF_TCP.imn).

What's Covered


Effect of TCP Window Size — measuring throughput and retransmissions with iperf3 across varying window sizes (1–32 KB); dissecting TCP/IP/Ethernet headers in Wireshark
TCP Short vs. Long Paths — comparing throughput between nodes on paths of equal capacity but different lengths
Link Capacity & Packet Loss Tradeoffs — comparing throughput across combinations of link capacity (3–100 Mbps) and loss rates (0–10%, symmetric and asymmetric)
OSPF Link Cost Changes — observing route changes and traffic path shifts in response to manually adjusted OSPF interface costs (via vtysh)
OSPF Database Updates — capturing OSPF link-state advertisements in Wireshark, measuring convergence time after a cost change, and analyzing routing table/database updates after a router is disconnected


Key Takeaway

The project ties together TCP congestion/throughput behavior with link-layer conditions (capacity, loss) and OSPF's dynamic route selection and convergence, using live packet captures and CLI router tools to observe real network behavior rather than just theory.




Tools

Linux · CORE Network Emulator · iperf3 · Wireshark · vtysh (OSPF/FRRouting)
