import json
import netifaces

# 외부 네트워크 인터페이스의 IP 주소를 가져오는 함수
def get_external_ip_address():
    for interface in netifaces.interfaces():
        # 루프백 인터페이스가 아닌 경우만 선택
        if interface != "lo":
            iface_info = netifaces.ifaddresses(interface)
            # IPv4 주소가 있는 인터페이스만 선택
            if netifaces.AF_INET in iface_info:
                ip_address = iface_info[netifaces.AF_INET][0]['addr']
                return ip_address, interface
    return None, None

# JSON 파일의 unicast 필드를 업데이트하는 함수
def update_unicast_ip(filename):
    # JSON 파일 열기
    with open(filename, 'r') as file:
        config = json.load(file)
    
    # 외부 네트워크 인터페이스와 IP 주소 가져오기
    ip_address, interface = get_external_ip_address()
    
    # IP 주소가 유효한 경우 JSON의 unicast 필드 업데이트
    if ip_address:
        config["unicast"] = ip_address

        # 업데이트된 JSON 파일 저장
        with open(filename, 'w') as file:
            json.dump(config, file, indent=4)
        
        print(f"Updated 'unicast' IP address to: {ip_address} on interface {interface}")
    else:
        print("Could not find a valid external IP address.")

# 파일 이름 설정
filename = "/opt/IC_someip/json/IC.json"
update_unicast_ip(filename)
