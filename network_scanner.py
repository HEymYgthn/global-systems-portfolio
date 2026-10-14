import socket
import sys

def scan_port(ip, port):
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.settimeout(0.5)
        result = sock.connect_ex((ip, port))
        if result == 0:
            print(f"[+] Port {port} is OPEN")
        sock.close()
    except Exception as e:
        pass

if __name__ == "__main__":
    target_host = "127.0.0.1"
    print(f"--- Low-Level Network Port Scanner ---")
    print(f"Target: {target_host}\n")
    for port in [21, 22, 80, 443, 8080]:
        scan_port(target_host, port)
